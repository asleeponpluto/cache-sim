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

public:
    unsigned int numHits;
    unsigned int numMisses;
    vector<Instruction> instructionStore;

    /* Fully Associative */
    // "tag" as the key
    unordered_map<string, string> cacheFullyAssociative;
    queue<string> fifoFullyAssociative;
    LRU<string> lruFullyAssociative;

    /* Direct Mapped */
    unordered_map<int, string> cacheDirectMapped;



    // outer map is using the "tag" as the key
    // inner map is using the "set" as the key
    // inner map value is the data
    unordered_map<string, unordered_map<string, string>> cache;
public:
    static string hexToBin(const string& in);

    void readFile(const string& filePath);
    void simFullyAssociative(int numSets, int numBlocks, int bytesPerBlock, const string& replacePol);
    void simDirectMapped(int numSets, int numBlocks, int bytesPerBlock, const string& replacePol);
    void simulate(int numSets, int numBlocks, int bytesPerBlock, const string& replacePol);


    void printStored();
};
