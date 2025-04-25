/*
Casey Rose - CS310
Ch08Exercise07.cpp
*/

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

// Struct to store candidate data
struct Candidate {
    std::string name;
    int votes;
};

int main() {
    std::vector<Candidate> candidates(5);
    int totalVotes = 0;

    std::cout << "Enter the last names and votes for 5 candidates:\n";

    for (int i = 0; i < 5; ++i) {
        std::cout << "Candidate " << (i + 1) << " name: ";
        std::cin >> candidates[i].name;

        while (true) {
            std::cout << "Candidate " << (i + 1) << " votes: ";
            std::cin >> candidates[i].votes;

            if (std::cin.fail() || candidates[i].votes < 0) {
                std::cout << "Please enter a valid non-negative number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }

        totalVotes += candidates[i].votes;
    }

    std::cout << "\nElection Results:\n";
    std::cout << std::left << std::setw(15) << "Candidate"
              << std::setw(10) << "Votes"
              << "Percentage\n";
    std::cout << "----------------------------------------\n";

    int winnerIndex = 0;

    for (int i = 0; i < 5; ++i) {
        double percentage = (static_cast<double>(candidates[i].votes) / totalVotes) * 100.0;
        std::cout << std::left << std::setw(15) << candidates[i].name
                  << std::setw(10) << candidates[i].votes
                  << std::fixed << std::setprecision(2) << percentage << "%\n";

        if (candidates[i].votes > candidates[winnerIndex].votes) {
            winnerIndex = i;
        }
    }

    std::cout << "\nWinner: " << candidates[winnerIndex].name
              << " with " << candidates[winnerIndex].votes << " votes.\n";

    return 0;
}
