#include <iostream>
#include "CacheSim.h"

int main() {
    CacheSim sim;
    sim.readFile("read01.trace");
    sim.printStored();
}
