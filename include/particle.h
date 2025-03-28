#ifndef PARTICLE_H
#define PARTICLE_H

/// Represents a single spin in the lattice with state +1 or -1.
class Particle {
private:
    int state; // +1 (up) or -1 (down)
public:
    Particle();       // Initialize spin to +1
    void flip();       // Flip the spin (+1 ↔ -1)
    int getState() const; // Get current spin state
};

#endif