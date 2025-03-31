#include <iostream>
#include <iomanip>
#include <string>

int main() {
    // Named constants for royalty rates and fixed payments
    const double OPTION1_DELIVERY_PAYMENT = 5000.0;
    const double OPTION1_PUBLICATION_PAYMENT = 20000.0;
    const double OPTION2_ROYALTY_RATE = 0.125;
    const double OPTION3_ROYALTY_RATE_FIRST_4000 = 0.10;
    const double OPTION3_ROYALTY_RATE_OVER_4000 = 0.14;
    const int OPTION3_THRESHOLD_COPIES = 4000;

    // Get input from the author
    double netPrice;
    int estimatedCopies;

    std::cout << "Enter the net price of each copy: $";
    std::cin >> netPrice;

    std::cout << "Enter the estimated number of copies to be sold: ";
    std::cin >> estimatedCopies;

    // Calculate royalties for each option
    double option1Royalties = OPTION1_DELIVERY_PAYMENT + OPTION1_PUBLICATION_PAYMENT;
    double option2Royalties = estimatedCopies * netPrice * OPTION2_ROYALTY_RATE;
    double option3Royalties;

    if (estimatedCopies <= OPTION3_THRESHOLD_COPIES) {
        option3Royalties = estimatedCopies * netPrice * OPTION3_ROYALTY_RATE_FIRST_4000;
    } else {
        option3Royalties = (OPTION3_THRESHOLD_COPIES * netPrice * OPTION3_ROYALTY_RATE_FIRST_4000) +
                           ((estimatedCopies - OPTION3_THRESHOLD_COPIES) * netPrice * OPTION3_ROYALTY_RATE_OVER_4000);
    }

    // Determine the best option using a switch/case statement (for demonstration, we will use it to print the royalties)
    std::cout << std::fixed << std::setprecision(2); // Set precision for currency display
    std::cout << "\nRoyalties for each option:\n";

    int bestOption;
    double bestRoyalties = option1Royalties;
    bestOption = 1;

    if(option2Royalties > bestRoyalties) {
        bestRoyalties = option2Royalties;
        bestOption = 2;
    }
    if(option3Royalties > bestRoyalties){
        bestRoyalties = option3Royalties;
        bestOption = 3;
    }

    switch (1) { //Using a switch statement here to print the royalties.
        case 1:
            std::cout << "Option 1: $" << option1Royalties << std::endl;
        case 2:
            std::cout << "Option 2: $" << option2Royalties << std::endl;
        case 3:
            std::cout << "Option 3: $" << option3Royalties << std::endl;
            break;
    }

    // Output the best option
    std::string bestOptionString;

    switch (bestOption){
        case 1:
            bestOptionString = "Option 1";
            break;
        case 2:
            bestOptionString = "Option 2";
            break;
        case 3:
            bestOptionString = "Option 3";
            break;
    }

    std::cout << "\nThe best option for the author is: " << bestOptionString << std::endl;

    return 0;
}