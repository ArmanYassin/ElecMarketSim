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

    return 0;
}