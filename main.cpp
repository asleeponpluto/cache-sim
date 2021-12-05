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
    sim.simSetAssociative(4, 4, 4, "FIFO");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
    sim.simSetAssociative(4, 4, 4, "LRU");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
    sim.simSetAssociative(4, 4, 16, "FIFO");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
    sim.simSetAssociative(4, 4, 16, "LRU");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;

    sim.simSetAssociative(4, 16, 16, "FIFO");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
    sim.simSetAssociative(4, 16, 16, "LRU");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
    sim.simSetAssociative(4, 16, 64, "FIFO");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
    sim.simSetAssociative(4, 16, 64, "LRU");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;

    sim.simSetAssociative(64, 64, 64, "FIFO");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
    sim.simSetAssociative(64, 64, 64, "LRU");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
    sim.simSetAssociative(64, 64, 256, "FIFO");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
    sim.simSetAssociative(64, 64, 256, "LRU");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;

    sim.simSetAssociative(64, 256, 256, "FIFO");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
    sim.simSetAssociative(64, 256, 256, "LRU");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
    sim.simSetAssociative(64, 256, 1024, "FIFO");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;
    sim.simSetAssociative(64, 256, 1024, "LRU");
    cout << "hit rate: " << (double)(sim.numHits) / (double)(sim.numHits + sim.numMisses) << endl;

}
