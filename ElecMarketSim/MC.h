#ifndef MONTE_CARLO_SIMULATION_H
#define MONTE_CARLO_SIMULATION_H

#include <vector>
#include <functional>
#include <random>
#include <stdexcept>

namespace MonteCarlo {

    // A class to manage random number generation
    class RandomGenerator {
    public:
        RandomGenerator()
            : generator(std::random_device{}()), distribution(0.0, 1.0) {}

        // Generate a random double in the range [0, 1]
        double getRandom() {
            return distribution(generator);
        }

        // Generate a random double in a specified range
        double getRandom(double min, double max) {
            if (min > max) {
                throw std::invalid_argument("Min must be less than or equal to max.");
            }
            std::uniform_real_distribution<double> dist(min, max);
            return dist(generator);
        }

    private:
        std::mt19937 generator; // Mersenne Twister random number generator
        std::uniform_real_distribution<double> distribution;
    };

    // Abstract class representing a simulation model
    class SimulationModel {
    public:
        virtual ~SimulationModel() = default;

        // Override this method to implement the specific simulation logic
        virtual double run(RandomGenerator& rng) = 0;
    };

    // Monte Carlo simulation framework
    class MonteCarloSimulation {
    public:
        MonteCarloSimulation(SimulationModel& model, size_t iterations)
            : model(model), iterations(iterations) {
            if (iterations == 0) {
                throw std::invalid_argument("Number of iterations must be greater than zero.");
            }
        }

        // Run the simulation and return results
        std::vector<double> run() {
            std::vector<double> results;
            results.reserve(iterations);

            for (size_t i = 0; i < iterations; ++i) {
                results.push_back(model.run(rng));
            }

            return results;
        }

        // Compute the mean of the results
        static double computeMean(const std::vector<double>& results) {
            if (results.empty()) {
                throw std::invalid_argument("Results vector is empty.");
            }

            double sum = 0.0;
            for (double value : results) {
                sum += value;
            }
            return sum / results.size();
        }

    private:
        SimulationModel& model;
        size_t iterations;
        RandomGenerator rng;
    };

} // namespace MonteCarlo

#endif // MONTE_CARLO_SIMULATION_H
