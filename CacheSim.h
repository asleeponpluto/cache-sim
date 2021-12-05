#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
using std::string;
using std::vector;
using std::unordered_map;
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

    vector<Instruction> instructionStore;
    unordered_map<string, string> cache;
//    priority_queue<pair<int, string> accessHeap;
public:
    static string hexToBin(const string& in);

    void readFile(const string& filePath);
    void simulate(int numSets, int numBlocks, int bytesPerBlock, const string& replacePol);


    void printStored();
};
