/*
Casey Rose - CS310
Ch12Exercise03.cpp
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
    int numCandidates;

    std::cout << "Enter the number of candidates: ";
    std::cin >> numCandidates;

    // Input validation for the number of candidates
    while (std::cin.fail() || numCandidates <= 0) {
        std::cout << "Please enter a valid positive number of candidates: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> numCandidates;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume the newline

    // Dynamically allocate an array of Candidate structs
    Candidate* candidates = new Candidate[numCandidates];
    int totalVotes = 0;

    std::cout << "\nEnter the last names and votes for " << numCandidates << " candidates:\n";

    for (int i = 0; i < numCandidates; ++i) {
        std::cout << "Candidate " << (i + 1) << " name: ";
        std::getline(std::cin, candidates[i].name); // Use getline to handle names with spaces

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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume the newline

        totalVotes += candidates[i].votes;
    }

    std::cout << "\nElection Results:\n";
    std::cout << std::left << std::setw(15) << "Candidate"
              << std::setw(10) << "Votes"
              << "Percentage\n";
    std::cout << "----------------------------------------\n";

    int winnerIndex = 0;

    for (int i = 0; i < numCandidates; ++i) {
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

    // Deallocate the dynamically allocated array to prevent memory leaks
    delete[] candidates;
    candidates = nullptr; // Good practice to set the pointer to null after deleting

    return 0;
}