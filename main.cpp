#include <iostream>
#include "CacheSim.h"
using namespace std;

int main() {
    CacheSim sim;
    sim.readFile("gcc.trace");
    sim.simFullyAssociative(1, 16, 4, "LRU");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
}
