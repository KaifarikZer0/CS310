#include <iostream>
#include <string>
using namespace std;

class bankAccount {
private:
    string name;
    int accountNumber;
    string accountType;
    double balance;
    double interestRate; // as a decimal, e.g., 0.05 for 5%

    static int nextAccountNumber;

public:
    // Default constructor
    bankAccount() : name(""), accountNumber(0), accountType(""), balance(0.0), interestRate(0.0) {}

    // Parameterized constructor
    bankAccount(string accName, string accType, double initialBalance, double rate)
        : name(accName), accountType(accType), balance(initialBalance), interestRate(rate) {
        accountNumber = nextAccountNumber++;
    }

    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient funds!" << endl;
    }

    void applyInterest() {
        balance += balance * interestRate;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
        cout << "-----------------------------" << endl;
    }
};

// Initialize static member
int bankAccount::nextAccountNumber = 1001;

int main() {
    const int SIZE = 10;
    bankAccount customers[SIZE] = {
        bankAccount("Alice Smith", "Checking", 1500.0, 0.01),
        bankAccount("Bob Johnson", "Saving", 2500.0, 0.03),
        bankAccount("Carol King", "Checking", 1800.0, 0.015)
    };

    // Simulate operations
    customers[0].deposit(500.0);
    customers[1].withdraw(300.0);
    customers[2].applyInterest();

    // Display accounts
    for (int i = 0; i < 3; ++i) {
        customers[i].display();
    }

    return 0;
}
