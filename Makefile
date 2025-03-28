CXX = g++
CXXFLAGS = -std=c++17 -O3 -Wall -shared -fPIC -Iinclude $(shell python3 -m pybind11 --includes)
TARGET = libising$(shell python3-config --extension-suffix)

SRC = src/particle.cpp src/lattice.cpp src/ising_model.cpp src/binding.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $^ -o $@

clean:
	rm -f $(TARGET) *.png

run: $(TARGET)
	python3 ising_plot.py