#include "ising.h"
#include <iostream>

int main() {
    int size = 100;   // Number of spins
    double beta = 1.0; // Temperature parameter
    int steps = 10000; // Monte Carlo steps

    IsingModel model(size, beta);
    model.runSimulation(steps);

    std::cout << "Final Energy: " << model.computeEnergy() << std::endl;
    std::cout << "Final Magnetization: " << model.computeMagnetization() << std::endl;
    model.printLattice();
    return 0;
}
