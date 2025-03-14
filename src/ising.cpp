#include "ising.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

IsingModel::IsingModel(int size, double beta) : size(size), beta(beta) {
    initialize();
}

void IsingModel::initialize() {
    spins.resize(size);
    for (int i = 0; i < size; ++i) {
        spins[i] = (rand() % 2 == 0) ? 1 : -1;
    }
}

int IsingModel::deltaEnergy(int index) {
    int left = (index == 0) ? size - 1 : index - 1;
    int right = (index == size - 1) ? 0 : index + 1;
    return 2 * spins[index] * (spins[left] + spins[right]);
}

void IsingModel::flipSpin(int index) {
    spins[index] *= -1;
}

void IsingModel::runSimulation(int steps) {
    for (int step = 0; step < steps; ++step) {
        int index = rand() % size;
        int dE = deltaEnergy(index);

        if (dE <= 0 || ((double)rand() / RAND_MAX) < exp(-beta * dE)) {
            flipSpin(index);
        }
    }
}

double IsingModel::computeEnergy() {
    double energy = 0;
    for (int i = 0; i < size; ++i) {
        energy += -spins[i] * spins[(i + 1) % size];
    }
    return energy;
}

int IsingModel::computeMagnetization() {
    int M = 0;
    for (int spin : spins) {
        M += spin;
    }
    return M;
}

void IsingModel::printLattice() {
    for (int spin : spins) {
        std::cout << (spin == 1 ? "↑" : "↓") << " ";
    }
    std::cout << std::endl;
}
