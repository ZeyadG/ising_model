#include "particle.h"

/// Constructor: Initializes spin to +1 (default state)
Particle::Particle() : state(1) {}

/// Flips the spin (multiplies state by -1)
void Particle::flip() { 
    state *= -1; 
}

/// Returns the current spin state (+1 or -1)
int Particle::getState() const { 
    return state; 
}