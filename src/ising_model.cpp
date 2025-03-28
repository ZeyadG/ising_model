#include "ising_model.h"
#include <cmath>

/// Constructor: Initializes lattice and random number generator.
IsingModel::IsingModel(int size, double beta, int dimension) 
    : lattice(size, dimension), beta(beta), gen(std::random_device{}()) {
    lattice.initializeRandom();
}

/// Computes energy change ΔE if spin at `index` flips.
double IsingModel::deltaEnergy(int index) const {
    const auto& p = lattice.getParticle(index); // `auto` deduces type as Particle
    double energy = 0.0;
    for (const auto* neighbor : lattice.getNeighbors(index)) {
        energy += p.getState() * neighbor->getState(); // Sum neighbor interactions
    }
    return 2.0 * energy; // ΔE = 2 * s_i * sum(neighbors)
}

/// Performs one Monte Carlo step.
void IsingModel::monteCarloStep() {
    // Randomly select a spin
    std::uniform_int_distribution<> idx_dist(0, lattice.getSize() - 1);
    int idx = idx_dist(gen);

    // Calculate energy change if spin flips
    double dE = deltaEnergy(idx);

    // Determine acceptance probability
    double P;
    if (dE <= 0) {
        P = 1.0; // Always accept energy-lowering flips
    } else {
        P = std::exp(-beta * dE); // Probabilistically accept energy-raising flips
    }

    // Generate a random number between 0 and 1
    std::uniform_real_distribution<double> prob_dist(0.0, 1.0);
    double rand = prob_dist(gen);

    // Flip spin if random number < P
    if (rand < P) {
        lattice.getParticle(idx).flip();
    }
}


/// Thermalizes the system by performing `steps` full lattice sweeps.
void IsingModel::thermalize(int steps) {
    for (int i = 0; i < steps; i++) {
        // One sweep: attempt to flip each spin once
        for (int j = 0; j < lattice.getSize(); j++) monteCarloStep();
    }
}

/// Computes total energy of the current configuration.
double IsingModel::computeEnergy() const {
    double energy = 0.0;
    for (int i = 0; i < lattice.getSize(); i++) {
        for (const auto* neighbor : lattice.getNeighbors(i)) {
            // Energy contribution from spin i and neighbor
            energy -= lattice.getParticle(i).getState() * neighbor->getState();
        }
    }
    return energy / 2; // Correct double-counting for all dimensions
}

/// Computes total magnetization of the current configuration.
int IsingModel::computeMagnetization() const {
    int mag = 0;
    for (int i = 0; i < lattice.getSize(); i++) {
        mag += lattice.getParticle(i).getState(); // Sum all spins
    }
    return mag;
}

/// Measures average energy and |magnetization| over `steps` configurations.
std::pair<double, double> IsingModel::measure(int steps) {
    double totalE = 0.0, totalM = 0.0;
    for (int i = 0; i < steps; i++) {
        // Thermalize for one sweep between measurements
        for (int j = 0; j < lattice.getSize(); j++) monteCarloStep();
        totalE += computeEnergy();
        totalM += std::abs(computeMagnetization()); // Use absolute magnetization
    }
    return {totalE / steps, totalM / steps}; // Averages per configuration
}