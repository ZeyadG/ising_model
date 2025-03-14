#ifndef ISING_H
#define ISING_H

#include <vector>

class IsingModel {
public:
    IsingModel(int size, double beta);
    void initialize();
    void runSimulation(int steps);
    double computeEnergy();
    int computeMagnetization();
    void printLattice();

private:
    int size;
    double beta;
    std::vector<int> spins;

    int deltaEnergy(int index);
    void flipSpin(int index);
};

#endif
