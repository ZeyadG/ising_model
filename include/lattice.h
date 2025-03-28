#ifndef LATTICE_H
#define LATTICE_H

#include <vector>
#include "particle.h"

/// Represents a 1D or 2D lattice of spins.
class Lattice {
private:
    std::vector<Particle> grid; // 1D array storing spins
    int size;                   // Size per dimension (e.g., 100 for 100x100 grid)
    int dimension;              // 1 (1D) or 2 (2D)

public:
    Lattice(int size, int dimension);
    void initializeRandom();    // Randomize spins with 50% up/down
    
    // Accessors (non-const: allow spin modification)
    Particle& getParticle(int index);
    Particle& getParticle(int x, int y); // For 2D
    
    // Accessors (const: read-only access)
    const Particle& getParticle(int index) const;
    
    // Get neighboring spins (non-const/const versions)
    std::vector<Particle*> getNeighbors(int index);
    std::vector<const Particle*> getNeighbors(int index) const;
    
    int getSize() const;      // Total spins = size^dimension
    int getDimension() const;
};

#endif