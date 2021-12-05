#include <iostream>
#include "CacheSim.h"
using namespace std;

int main() {
    CacheSim sim;
    sim.readFile("gcc.trace");

    /* Fully Associative */
    sim.simFullyAssociative(4, 16, 16, "FIFO");
    cout << "hit rate: " << sim.getHitRate() << endl;
    sim.simFullyAssociative(4, 16, 16, "LRU");
    cout << "hit rate: " << sim.getHitRate() << endl;
    sim.simFullyAssociative(4, 16, 64, "FIFO");
    cout << "hit rate: " << sim.getHitRate() << endl;
    sim.simFullyAssociative(4, 16, 64, "LRU");
    cout << "hit rate: " << sim.getHitRate() << endl;

    /* Direct Mapped */
    sim.simDirectMapped(4, 16, 16, "FIFO");
    cout << "hit rate: " << sim.getHitRate() << endl;
    sim.simDirectMapped(4, 16, 16, "LRU");
    cout << "hit rate: " << sim.getHitRate() << endl;
    sim.simDirectMapped(4, 16, 64, "FIFO");
    cout << "hit rate: " << sim.getHitRate() << endl;
    sim.simDirectMapped(4, 16, 64, "LRU");
    cout << "hit rate: " << sim.getHitRate() << endl;

    /* Set Associative */
    sim.simSetAssociative(4, 16, 16, "FIFO");
    cout << "hit rate: " << sim.getHitRate() << endl;
    sim.simSetAssociative(4, 16, 16, "LRU");
    cout << "hit rate: " << sim.getHitRate() << endl;
    sim.simSetAssociative(4, 16, 64, "FIFO");
    cout << "hit rate: " << sim.getHitRate() << endl;
    sim.simSetAssociative(4, 16, 64, "LRU");
    cout << "hit rate: " << sim.getHitRate() << endl;
}
