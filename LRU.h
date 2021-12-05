#pragma once

#include <string>
#include <unordered_map>
#include <list>
using std::string;
using std::unordered_map;
using std::list;
using std::pair;

template <typename T>
class LRU {
private:
    unordered_map<T, typename list<T>::iterator> pointerHashTable;
    list<T> ll;
public:
    void insert(const T& val);
    void remove(const T& val);
    void hit(const T& val);
    void clear();
    string getLRU();
};

template <typename T>
void LRU<T>::insert(const T &val) {
    ll.push_back(val);
    pointerHashTable.insert(pair<T, typename list<T>::iterator>(val, --ll.end()));
}

template <typename T>
void LRU<T>::remove(const T &val) {
    auto listIter = pointerHashTable.find(val)->second;
    pointerHashTable.erase(val);
    ll.erase(listIter);
}

template <typename T>
void LRU<T>::hit(const T &val) {
    remove(val);
    insert(val);
}

template <typename T>
void LRU<T>::clear() {
    ll.clear();
    pointerHashTable.clear();
}

template <typename T>
string LRU<T>::getLRU() {
    return ll.front();
}
