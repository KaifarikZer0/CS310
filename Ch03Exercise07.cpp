#include <iostream>
#include <iomanip>
#include <locale>

int main() {
    double netBalance, payment, interestRate;
    int d1, d2;

    std::cout << "Enter the net balance: ";
    std::cin >> netBalance;

    std::cout << "Enter the payment: ";
    std::cin >> payment;

    std::cout << "Enter the number of days in the billing cycle: ";
    std::cin >> d1;

    std::cout << "Enter the number of days payment is made before the billing cycle: ";
    std::cin >> d2;

    std::cout << "Enter the interest rate per month (e.g., 0.0152): ";
    std::cin >> interestRate;

    double averageDailyBalance = (netBalance * d1 - payment * d2) / static_cast<double>(d1); //ensure double division

    double interest = averageDailyBalance * interestRate;

    // Format output
    std::cout << std::fixed << std::setprecision(2);
    std::locale loc("");
    std::cout.imbue(loc);

    std::cout << "Interest: $" << interest << std::endl;

    return 0;
}