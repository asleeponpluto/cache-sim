#pragma once

#include <string>
#include <unordered_map>
#include <list>
using std::string;
using std::unordered_map;
using std::list;

class LRU {
private:
    unordered_map<string, list<string>::iterator> pointerHashTable;
    list<string> ll;
public:
    void insert(const string& val);
    void remove(const string& val);
    void hit(const string& val);
    string getLRU();
};