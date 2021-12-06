#include "CacheSim.h"
#include <string>
#include <fstream>
#include <iostream>
#include <cmath>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::log2;
using std::stoi;

void CacheSim::readFile(const string &filePath) {
    ifstream file(filePath);

    while (!file.eof()) {
        string instructionTypeStr;
        string hexAddressStr;
        string temp;

        bool isLoad;
        string binaryAddress;

        file >> instructionTypeStr;

        if (instructionTypeStr.empty())
            return;

        file >> hexAddressStr;
        file >> temp;

        isLoad = (instructionTypeStr == "l");
        binaryAddress = hexToBin(hexAddressStr);

        instructionStore.emplace_back(isLoad, binaryAddress);
    }
}

void CacheSim::simFullyAssociative(int numSets, int numBlocks, int bytesPerBlock, const string &replacePol) {
    cacheFullyAssociative.clear();
    lruFullyAssociative.clear();
    while (!fifoFullyAssociative.empty())
        fifoFullyAssociative.pop();

    numHits = 0;
    numMisses = 0;

    unsigned int offsetFieldSize = log2(bytesPerBlock);
    unsigned int tagFieldSize = 32 - offsetFieldSize;

    for (const Instruction& curr : instructionStore) {
        string tagField = curr.address.substr(0, tagFieldSize);
        string offsetField = curr.address.substr(tagFieldSize, offsetFieldSize);

        if (cacheFullyAssociative.find(tagField) != cacheFullyAssociative.end()) { // if it exists
            lruFullyAssociative.hit(tagField);
            numHits++;
        } else {
            lruFullyAssociative.insert(tagField);
            fifoFullyAssociative.push(tagField);
            numMisses++;

            if (cacheFullyAssociative.size() == numBlocks) {
                if (replacePol == "LRU") {
                    string tagToDelete = lruFullyAssociative.getLRU();
                    lruFullyAssociative.remove(tagToDelete);
                    cacheFullyAssociative.erase(tagToDelete);
                } else if (replacePol == "FIFO") {
                    string tagToDelete = fifoFullyAssociative.front();
                    fifoFullyAssociative.pop();
                    cacheFullyAssociative.erase(tagToDelete);
                }
            }

            cacheFullyAssociative.insert(pair<string, string>(tagField, offsetField));
        }
    }
}

void CacheSim::simDirectMapped(int numSets, int numBlocks, int bytesPerBlock, const string &replacePol) {
    cacheDirectMapped.clear();

    numHits = 0;
    numMisses = 0;

    unsigned int offsetFieldSize = log2(bytesPerBlock);
    unsigned int lineFieldSize = log2(numSets);
    unsigned int tagFieldSize = 32 - offsetFieldSize - lineFieldSize;

    for (const Instruction& curr : instructionStore) {
        string tagField = curr.address.substr(0, tagFieldSize);
        string lineField = curr.address.substr(tagFieldSize, lineFieldSize);
        string offsetField = curr.address.substr(tagFieldSize + lineFieldSize, offsetFieldSize);
        int cacheLine = stoi(lineField, nullptr, 2) % numSets;

        if (cacheDirectMapped[cacheLine] == tagField) {
            numHits++;
        } else {
            cacheDirectMapped[cacheLine] = tagField;
            numMisses++;
        }
    }
}

void CacheSim::simSetAssociative(int numSets, int numBlocks, int bytesPerBlock, const string &replacePol) {
    cacheSetAssociative.clear();
    lruSetAssociative.clear();
    fifoSetAssociative.clear();

    numHits = 0;
    numMisses = 0;

    unsigned int offsetFieldSize = log2(bytesPerBlock);
    unsigned int setFieldSize = log2(numSets);
    unsigned int tagFieldSize = 32 - setFieldSize - offsetFieldSize;

    for (const Instruction& curr : instructionStore) {
        string tagField = curr.address.substr(0, tagFieldSize);
        string setField = curr.address.substr(tagFieldSize, setFieldSize);
        string offsetField = curr.address.substr(tagFieldSize + setFieldSize, offsetFieldSize);

        if (cacheSetAssociative[setField].find(tagField) != cacheSetAssociative[setField].end()) {
            lruSetAssociative[setField].hit(tagField);
            numHits++;
        } else {
            lruSetAssociative[setField].insert(tagField);
            fifoSetAssociative[setField].push(tagField);
            numMisses++;

            if (cacheSetAssociative[setField].size() == numBlocks) {
                if (replacePol == "LRU") {
                    string tagToDelete = lruSetAssociative[setField].getLRU();
                    lruSetAssociative[setField].remove(tagToDelete);
                    cacheSetAssociative[setField].erase(tagToDelete);
                } else if (replacePol == "FIFO") {
                    string tagToDelete = fifoSetAssociative[setField].front();
                    fifoSetAssociative[setField].pop();
                    cacheSetAssociative[setField].erase(tagToDelete);
                }

            }

            cacheSetAssociative[setField].insert(pair<string, string>(tagField, offsetField));
        }
    }
}

void CacheSim::printStored() {
    for (const Instruction& t : instructionStore) {
        cout << t.isLoad << "\t" << t.address << endl;
    }
}
string CacheSim::hexToBin(const string &in) {
    const string inTrimmed = in.substr(2);
    string out;

    for (char c : inTrimmed) {
        switch (toupper(c)) {
            case '0':
                out += "0000";
                break;
            case '1':
                out += "0001";
                break;
            case '2':
                out += "0010";
                break;
            case '3':
                out += "0011";
                break;
            case '4':
                out += "0100";
                break;
            case '5':
                out += "0101";
                break;
            case '6':
                out += "0110";
                break;
            case '7':
                out += "0111";
                break;
            case '8':
                out += "1000";
                break;
            case '9':
                out += "1001";
                break;
            case 'A':
                out += "1010";
                break;
            case 'B':
                out += "1011";
                break;
            case 'C':
                out += "1100";
                break;
            case 'D':
                out += "1101";
                break;
            case 'E':
                out += "1110";
                break;
            case 'F':
                out += "1111";
                break;
        }
    }

    return out;
}

double CacheSim::getHitRate() {
    return (double)(numHits) / (double)(numHits + numMisses);
}

void CacheSim::runTest(int numSets, int numBlocks, int bytesPerBlock, const string &replacePol, unsigned int type) {
    if (type == 0)
        simFullyAssociative(numSets, numBlocks, bytesPerBlock, replacePol);
    else if (type == 1)
        simDirectMapped(numSets, numBlocks, bytesPerBlock, replacePol);
    else if (type == 2)
        simSetAssociative(numSets, numBlocks, bytesPerBlock, replacePol);

    cout << numSets << "\t" << numBlocks << "\t" << bytesPerBlock << "\t" << replacePol << "\t" << getHitRate() << endl;
}

void CacheSim::printHeader() {
    cout << "sets\tblocks\tsize\tpolicy\thit-rate" << endl;
}


