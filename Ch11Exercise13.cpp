#include <iostream>
#include <iomanip>
#include <string>

class bankAccount {
private:
    int accountNumber;
protected:
    double balance;

public:
    
    bankAccount() : accountNumber(0), balance(0.0) {}

    //  Account number and initial balance
    bankAccount(int accNum, double bal) : accountNumber(accNum), balance(bal) {}

    // Set the account number
    void setAccountNumber(int accNum) {
        accountNumber = accNum;
    }

    // Retrieve the account number
    int getAccountNumber() const {
        return accountNumber;
    }

    // Retrieve the balance
    double getBalance() const {
        return balance;
    }

    // Depositing money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposit of $" << std::fixed << std::setprecision(2) << amount << " successful.\n";
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    // Withdrawing money
    virtual void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawal of $" << std::fixed << std::setprecision(2) << amount << " successful.\n";
        } else if (amount <= 0) {
            std::cout << "Invalid withdrawal amount.\n";
        } else {
            std::cout << "Insufficient funds for withdrawal.\n";
        }
    }

    // Print account information
    virtual void printAccountInfo() const {
        std::cout << "Account Number: " << accountNumber << "\n";
        std::cout << "Balance: $" << std::fixed << std::setprecision(2) << balance << "\n";
    }
};

class checkingAccount : public bankAccount {
private:
    double interestRate;
    double minimumBalance;
    double serviceCharges;

public:
    // Default constructor
    checkingAccount() : interestRate(0.0), minimumBalance(0.0), serviceCharges(0.0) {}

    // Constructor with account number, initial balance, interest rate, minimum balance, and service charges
    checkingAccount(int accNum, double bal, double intRate, double minBal, double servCharge)
        : bankAccount(accNum, bal), interestRate(intRate), minimumBalance(minBal), serviceCharges(servCharge) {}

    // Set interest rate
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    // Retrieve interest rate
    double getInterestRate() const {
        return interestRate;
    }

    // Set minimum balance
    void setMinimumBalance(double minBal) {
        minimumBalance = minBal;
    }

    // Retrieve minimum balance
    double getMinimumBalance() const {
        return minimumBalance;
    }

    // Set service charges
    void setServiceCharges(double charges) {
        serviceCharges = charges;
    }

    // Retrieve service charges
    double getServiceCharges() const {
        return serviceCharges;
    }

    // Post interest
    void postInterest() {
        double interest = getBalance() * interestRate;
        deposit(interest);
        std::cout << "Interest of $" << std::fixed << std::setprecision(2) << interest << " posted.\n";
    }

    // Verify if the balance is less than the minimum balance
    bool isBalanceBelowMinimum() const {
        return getBalance() < minimumBalance;
    }

    // Write a check (withdraw money)
    void writeCheck(double amount) {
        std::cout << "Attempting to write a check for $" << std::fixed << std::setprecision(2) << amount << ".\n";
        withdraw(amount);
        if (isBalanceBelowMinimum()) {
            balance -= serviceCharges;
            std::cout << "Service charges of $" << std::fixed << std::setprecision(2) << serviceCharges << " applied due to balance below minimum.\n";
        }
    }

    // Override withdraw method
    void withdraw(double amount) override {
        if (amount > 0 && getBalance() >= amount) {
            balance -= amount;
            std::cout << "Withdrawal of $" << std::fixed << std::setprecision(2) << amount << " successful.\n";
            if (isBalanceBelowMinimum()) {
                balance -= serviceCharges;
                std::cout << "Service charges of $" << std::fixed << std::setprecision(2) << serviceCharges << " applied due to balance below minimum.\n";
            }
        } else if (amount <= 0) {
            std::cout << "Invalid withdrawal amount.\n";
        } else {
            std::cout << "Insufficient funds for withdrawal.\n";
        }
    }

    // Override print account information
    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        std::cout << "Interest Rate: " << std::fixed << std::setprecision(2) << interestRate * 100 << "%\n";
        std::cout << "Minimum Balance: $" << std::fixed << std::setprecision(2) << minimumBalance << "\n";
        std::cout << "Service Charges: $" << std::fixed << std::setprecision(2) << serviceCharges << "\n";
    }
};

class savingsAccount : public bankAccount {
private:
    double interestRate;

public:
    // Default constructor
    savingsAccount() : interestRate(0.0) {}

    // Constructor with account number, initial balance, and interest rate
    savingsAccount(int accNum, double bal, double intRate)
        : bankAccount(accNum, bal), interestRate(intRate) {}

    // Set interest rate
    void setInterestRate(double rate) {
        interestRate = rate;
    }

    // Retrieve interest rate
    double getInterestRate() const {
        return interestRate;
    }

    // Post interest
    void postInterest() {
        double interest = getBalance() * interestRate;
        deposit(interest);
        std::cout << "Interest of $" << std::fixed << std::setprecision(2) << interest << " posted.\n";
    }

    // Override withdraw method
    void withdraw(double amount) override {
        if (amount > 0 && getBalance() >= amount) {
            balance -= amount;
            std::cout << "Withdrawal of $" << std::fixed << std::setprecision(2) << amount << " successful.\n";
        } else if (amount <= 0) {
            std::cout << "Invalid withdrawal amount.\n";
        } else {
            std::cout << "Insufficient funds for withdrawal.\n";
        }
    }

    // Override print account information
    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        std::cout << "Interest Rate: " << std::fixed << std::setprecision(2) << interestRate * 100 << "%\n";
    }
};

int main() {
    // Test checkingAccount
    std::cout << "\n--- Testing Checking Account ---\n";
    checkingAccount checkingAcc(12345, 500.00, 0.01, 100.00, 5.00);
    checkingAcc.printAccountInfo();

    checkingAcc.deposit(100.00);
    checkingAcc.printAccountInfo();

    checkingAcc.writeCheck(200.00);
    checkingAcc.printAccountInfo();

    checkingAcc.writeCheck(450.00);
    checkingAcc.printAccountInfo();

    checkingAcc.postInterest();
    checkingAcc.printAccountInfo();

    // Test savingsAccount
    std::cout << "\n--- Testing Savings Account ---\n";
    savingsAccount savingsAcc(67890, 1000.00, 0.02);
    savingsAcc.printAccountInfo();

    savingsAcc.deposit(200.00);
    savingsAcc.printAccountInfo();

    savingsAcc.withdraw(300.00);
    savingsAcc.printAccountInfo();

    savingsAcc.withdraw(1500.00);
    savingsAcc.printAccountInfo();

    savingsAcc.postInterest();
    savingsAcc.printAccountInfo();

    return 0;
}
