#pragma once

#include "LRU.h"
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using std::string;
using std::vector;
using std::unordered_map;
using std::queue;
using std::priority_queue;
using std::pair;

class CacheSim {
private:
    struct Instruction {
        bool isLoad;
        string address; // 32-bit memory address

        Instruction(bool isLoad, const string& address) {
            this->isLoad = isLoad;
            this->address = address;
        }
    };

    struct Line {
        unsigned int lineNum;
        unsigned int tag;
    };

    unsigned int numHits;
    unsigned int numMisses;
    vector<Instruction> instructionStore;

    /* Fully Associative */
    unordered_map<string, string> cacheFullyAssociative;
    queue<string> fifoFullyAssociative;
    LRU<string> lruFullyAssociative;

    /* Direct Mapped */
    unordered_map<int, string> cacheDirectMapped;

    /* Set Associative */
    unordered_map<string, unordered_map<string, string>> cacheSetAssociative;
    unordered_map<string, queue<string>> fifoSetAssociative;
    unordered_map<string, LRU<string>> lruSetAssociative;
public:
    static string hexToBin(const string& in);

    void readFile(const string& filePath);
    void simFullyAssociative(int numSets, int numBlocks, int bytesPerBlock, const string& replacePol);
    void simDirectMapped(int numSets, int numBlocks, int bytesPerBlock, const string& replacePol);
    void simSetAssociative(int numSets, int numBlocks, int bytesPerBlock, const string& replacePol);
    void simulate(int numSets, int numBlocks, int bytesPerBlock, const string& replacePol);
    double getHitRate();

    void printStored();
};
