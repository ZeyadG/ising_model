#ifndef ISING_MODEL_H
#define ISING_MODEL_H

#include "lattice.h"
#include <random>

/// Implements the Ising model simulation using Monte Carlo methods.
class IsingModel {
private:
    Lattice lattice;   // Spin lattice
    double beta;       // Inverse temperature (β = 1/kT)
    std::mt19937 gen;  // Mersenne Twister random number generator

    // Computes energy change if spin at `index` flips
    double deltaEnergy(int index) const;
    
    // Performs one Monte Carlo step (spin flip attempt)
    void monteCarloStep();

public:
    /// Constructor: Initializes lattice with random spins.
    IsingModel(int size, double beta, int dimension);
    
    /// Thermalizes the system for `steps` sweeps (equilibration).
    void thermalize(int steps);
    
    /// Measures average energy and magnetization over `steps` configurations.
    std::pair<double, double> measure(int steps);
    
    /// Computes total energy of the current configuration.
    double computeEnergy() const;
    
    /// Computes total magnetization of the current configuration.
    int computeMagnetization() const;
};

#endif