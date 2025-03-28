import numpy as np
import matplotlib.pyplot as plt
import libising

def simulate(dimension):
    # Parameters
    size = 100
    betas = np.linspace(0.1, 4.0, 20)
    avg_energies = []
    avg_mags = []

    for beta in betas:
        print(f"Processing β={beta:.2f} ({dimension}D)")
        model = libising.IsingModel(size, beta, dimension)
        model.thermalize(5000)  # Thermalize first
        avg_energy, avg_mag = model.measure(10000)  # Measure 10k configs
        avg_energies.append(avg_energy)
        avg_mags.append(avg_mag)

    # Plotting
    plt.figure(figsize=(12,6))
    plt.subplot(2,1,1)
    plt.plot(betas, avg_energies, 'o-')
    plt.xlabel(r"$\beta$")
    plt.ylabel("Avg Energy per Config")
    
    plt.subplot(2,1,2)
    plt.plot(betas, avg_mags, 's-')
    plt.xlabel(r"$\beta$")
    plt.ylabel("Avg Magnetization per Config")
    
    plt.tight_layout()
    plt.savefig(f"ising_{dimension}D.png")
    plt.show()

if __name__ == "__main__":
    dimension = int(input("Enter dimension (1 or 2): "))
    simulate(dimension)