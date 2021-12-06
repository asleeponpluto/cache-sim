#include <iostream>
#include "CacheSim.h"
using std::cout;
using std::endl;

int main() {
    CacheSim sim;
    sim.readFile("gcc.trace");

    /* Fully Associative */
    cout << "\nFully Associative: " << endl;
    sim.printHeader();
    sim.runTest(1, 1, 4, "FIFO", 0);
    sim.runTest(1, 1, 4, "LRU", 0);
    sim.runTest(1, 16, 4, "FIFO", 0);
    sim.runTest(1, 16, 4, "LRU", 0);
    sim.runTest(1, 16, 16, "FIFO", 0);
    sim.runTest(1, 16, 16, "LRU", 0);
    sim.runTest(1, 64, 16, "FIFO", 0);
    sim.runTest(1, 64, 16, "LRU", 0);
    sim.runTest(1, 64, 64, "FIFO", 0);
    sim.runTest(1, 64, 64, "LRU", 0);

    /* Direct Mapped */
    cout << "\nDirect Mapped: " << endl;
    sim.printHeader();
    sim.runTest(16, 1, 4, "N/A", 1);
    sim.runTest(16, 1, 16, "N/A", 1);
    sim.runTest(64, 1, 16, "N/A", 1);
    sim.runTest(64, 1, 64, "N/A", 1);
    sim.runTest(256, 1, 64, "N/A", 1);
    sim.runTest(256, 1, 256, "N/A", 1);

    /* Set Associative */
    cout << "\nSet Associative: " << endl;
    sim.printHeader();
    sim.runTest(4, 4, 4, "FIFO", 2);
    sim.runTest(4, 4, 4, "LRU", 2);
    sim.runTest(4, 4, 16, "FIFO", 2);
    sim.runTest(4, 4, 16, "LRU", 2);
    sim.runTest(4, 16, 16, "FIFO", 2);
    sim.runTest(4, 16, 16, "LRU", 2);
    sim.runTest(4, 16, 64, "FIFO", 2);
    sim.runTest(4, 16, 64, "LRU", 2);
    sim.runTest(64, 64, 64, "FIFO", 2);
    sim.runTest(64, 64, 64, "LRU", 2);
    sim.runTest(64, 64, 256, "FIFO", 2);
    sim.runTest(64, 64, 256, "LRU", 2);
    sim.runTest(64, 256, 256, "FIFO", 2);
    sim.runTest(64, 256, 256, "LRU", 2);
    sim.runTest(64, 256, 1024, "FIFO", 2);
    sim.runTest(64, 256, 1024, "LRU", 2);
}
