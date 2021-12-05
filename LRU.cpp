#include "LRU.h"

using std::pair;


void LRU::insert(const string &val) {
    ll.push_back(val);
    pointerHashTable.insert(pair<string, list<string>::iterator>(val, --ll.end()));
}

void LRU::remove(const string &val) {
    auto listIter = pointerHashTable.find(val)->second;
    pointerHashTable.erase(val);
    ll.erase(listIter);
}

void LRU::hit(const string &val) {
    remove(val);
    insert(val);
}

string LRU::getLRU() {
    return ll.front();
}

