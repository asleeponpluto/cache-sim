#include <iostream>
#include "CacheSim.h"
using namespace std;

int main() {
    CacheSim sim;
    sim.readFile("gcc.trace");

    /* Fully Associative */
//    sim.simFullyAssociative(1, 16, 4, "FIFO");
//    cout << "fifo hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
//    sim.simFullyAssociative(1, 16, 4, "LRU");
//    cout << "lru hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;

    /* Direct Mapped */
//    sim.simDirectMapped(256, 1, 256, "FIFO");
//    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;

    /* Set Associative */
}
