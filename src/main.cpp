// main.cpp
#include <iostream>
#include "ising_model.h"

int main() {
    //this class is mainly for testing.


    
    // Hardcoded parameters for testing
    int size = 100;
    double beta = 1.0;
    int thermalization_steps = 5000;
    int measurement_steps = 10000;

    IsingModel model(size, beta, dimension);
    model.thermalize(thermalization_steps);
    auto [avg_energy, avg_mag] = model.measure(measurement_steps);

    std::cout << "\nResults for β = " << beta << ":\n";
    std::cout << "Average Energy per Configuration: " << avg_energy << "\n";
    std::cout << "Average Magnetization per Configuration: " << avg_mag << "\n";

    return 0;
}