// ElecMarketSim1.cpp : Defines the entry point for the application.
//

#include "ElecMarketSim1.h"
#include "MC.h"
#include <iostream>

using namespace std;

class ExampleModel : public MonteCarlo::SimulationModel {
public:
    // Example simulation: returns a random number between 0 and 10
    double run(MonteCarlo::RandomGenerator& rng) override {
        return rng.getRandom(0.0, 10.0);
    }
};

int main() {
    ExampleModel model;
    MonteCarlo::MonteCarloSimulation simulation(model, 10000); // 10,000 iterations

    std::vector<double> results = simulation.run();
    double mean = MonteCarlo::MonteCarloSimulation::computeMean(results);

    std::cout << "Simulation mean: " << mean << std::endl;
        int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Invalid input. Number of elements must be positive.\n";
        return 1;
    }

    std::vector<int> data(n);
    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> data[i];
    }

    // Count the frequency of each number
    std::map<int, int> frequency;
    for (int num : data) {
        ++frequency[num];
    }

    // Print the histogram
    MonteCarlo::RandomGenerator printHistogram(frequency);

    return 0;
}