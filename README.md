# Ising Model Simulation

Monte Carlo simulation of the 1D/2D Ising model to study phase transitions in ferromagnetic systems.

## Key Features
- **1D and 2D lattice** support with periodic boundary conditions
- **Metropolis algorithm** for thermalization and measurement
- Computes **average energy** and **absolute magnetization** per configuration
- Python plotting (`ising_plot.py`) for energy/magnetization vs temperature

## Code Structure

### 1. `Particle` Class
- Represents a single spin (+1 or -1)
- Methods: `flip()`, `getState()`

### 2. `Lattice` Class
- Manages spin grid (1D chain or 2D square lattice)
- Methods: 
  - `initializeRandom()` - Random spin initialization
  - `getNeighbors()` - Find adjacent spins
  - Particle accessors for 1D/2D indices

### 3. `IsingModel` Class
- Core simulation logic
- Methods:
  - `thermalize()` - Equilibrate the system
  - `measure()` - Average energy/magnetization
  - Monte Carlo spin flip implementation

### 4. Python Binding (`binding.cpp`)
- Exposes C++ functionality to Python via `pybind11`
- Enables plotting with `ising_plot.py`

## How to Use:
   make run # Compiles Python module and executable

   then the user will be asked to choose between 1d or 2d to perform energy and magnitization plot against beta for the chosen dimension ising model