#include <iostream>
#include "CacheSim.h"
using namespace std;

int main() {
    CacheSim sim;
    sim.readFile("read01.trace");
    sim.simFullyAssociative(1, 1, 4, "FIFO");
    cout << sim.numHits << endl;
    cout << sim.numMisses << endl;
}
