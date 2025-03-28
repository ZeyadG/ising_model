#include "lattice.h"
#include <random>

/// Constructor: Creates a lattice of size^dimension spins.
Lattice::Lattice(int size, int dimension) 
    : grid(size * size), size(size), dimension(dimension) {}

/// Randomizes spins with 50% probability of being up (+1) or down (-1).
void Lattice::initializeRandom() {
    std::mt19937 gen(std::random_device{}()); 
    std::uniform_int_distribution<> distrib(0, 1); 
    for (auto& p : grid) { // `auto&` infers type as Particle& (avoid copying)
        if (distrib(gen)) p.flip(); // Flip spin if distrib returns 1
    }
}

// Non-const accessors (used during spin flips)
Particle& Lattice::getParticle(int index) { return grid[index]; }
Particle& Lattice::getParticle(int x, int y) { return grid[x * size + y]; }

// Const accessors (used in read-only calculations)
const Particle& Lattice::getParticle(int index) const { return grid[index]; }

/// Returns non-const pointers to neighboring spins.
std::vector<Particle*> Lattice::getNeighbors(int index) {
    std::vector<Particle*> neighbors;
    int x = index / size, y = index % size; // Convert index to 2D coords
    
    if (dimension == 1) { // 1D neighbors (left/right)
        if (index > 0) neighbors.push_back(&grid[index - 1]);
        if (index < size - 1) neighbors.push_back(&grid[index + 1]);
    } else if (dimension == 2) { // 2D neighbors (up/down/left/right)
        if (x > 0) neighbors.push_back(&grid[(x-1)*size + y]);
        if (x < size-1) neighbors.push_back(&grid[(x+1)*size + y]);
        if (y > 0) neighbors.push_back(&grid[x*size + (y-1)]);
        if (y < size-1) neighbors.push_back(&grid[x*size + (y+1)]);
    }
    return neighbors;
}

/// Returns const pointers to neighbors (for read-only access).
std::vector<const Particle*> Lattice::getNeighbors(int index) const {
    std::vector<const Particle*> neighbors;
    int x = index / size; // Convert index to 2D coordinates
    int y = index % size;

    if (dimension == 1) {
        // 1D neighbors (left/right)
        if (index > 0) neighbors.push_back(&grid[index - 1]);
        if (index < size - 1) neighbors.push_back(&grid[index + 1]);
    } else if (dimension == 2) {
        // 2D neighbors (up/down/left/right)
        if (x > 0) neighbors.push_back(&grid[(x - 1) * size + y]);
        if (x < size - 1) neighbors.push_back(&grid[(x + 1) * size + y]);
        if (y > 0) neighbors.push_back(&grid[x * size + (y - 1)]);
        if (y < size - 1) neighbors.push_back(&grid[x * size + (y + 1)]);
    }

    return neighbors; // Returns const pointers
}
int Lattice::getSize() const { return size * size; }
int Lattice::getDimension() const { return dimension; }