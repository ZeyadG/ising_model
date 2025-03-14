CXX = g++
CXXFLAGS = -std=c++11 -Wall -Iinclude  # Include the "include" directory for headers
EXEC = ising_model

all: $(EXEC)

$(EXEC): src/main.o src/ising.o
	$(CXX) $(CXXFLAGS) -o $(EXEC) src/main.o src/ising.o

src/main.o: src/main.cpp include/ising.h
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o src/main.o

src/ising.o: src/ising.cpp include/ising.h
	$(CXX) $(CXXFLAGS) -c src/ising.cpp -o src/ising.o

clean:
	rm -f src/*.o $(EXEC)

run: $(EXEC)
	./$(EXEC)
