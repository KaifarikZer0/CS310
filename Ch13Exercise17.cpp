#include <iostream>
#include <random>
#include <vector>
#include <iomanip> // For std::fixed and std::setprecision

int main() {
    // 1. Create a random number engine
    //    std::default_random_engine is a common choice, but for better
    //    quality and often faster generation, std::mt19937 (Mersenne Twister)
    //    is generally preferred.
    std::random_device rd; // Used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); // Standard Mersenne Twister engine seeded with rd()

    // 2. Define the distribution
    //    std::uniform_real_distribution specifies a uniform distribution
    //    of real numbers over a specified range [a, b).
    //    Here, between 10.0 and 100.0 (inclusive of 10.0, exclusive of 100.0
    //    if you strictly adhere to the mathematical definition of [a, b)
    //    but in practice for floating point numbers it's effectively inclusive).
    std::uniform_real_distribution<> dis(10.0, 100.0);

    // 3. Generate and print 25 numbers
    std::cout << "Generating 25 real numbers between 10 and 100:\n";
    std::cout << std::fixed << std::setprecision(4); // Format output to 4 decimal places

    for (int i = 0; i < 25; ++i) {
        double randomNumber = dis(gen);
        std::cout << randomNumber << "\n";
    }

    return 0;
}