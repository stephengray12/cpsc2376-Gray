#include <iostream>
#include <fstream>
#include <iomanip>

const std::string FILE_NAME = "account_balance.txt";

// Function to read balance from file
double readBalanceFromFile() {
    std::ifstream file(FILE_NAME);
    double balance = 100.00; // Default balance if file doesn't exist

    if (file) {
        file >> balance;
    }
    else {
        // Create file with initial balance if it doesn't exist
        std::ofstream outFile(FILE_NAME);
        outFile << std::fixed << std::setprecision(2) << balance;
    }

    return balance;
}

// Function to write balance to file
void writeBalanceToFile(double balance) {
    std::ofstream file(FILE_NAME);
    if (file) {
        file << std::fixed << std::setprecision(2) << balance;
    }
    else {
        std::cerr << "Error: Unable to update balance." << std::endl;
    }
}

// Function to display balance
void checkBalance(double balance) {
    std::cout << "Your current balance is: $" << std::fixed << std::setprecision(2) << balance << "\n";
}

// Function to deposit money
void deposit(double& balance) {
    double amount;
    std::cout << "Enter deposit amount: ";
    std::cin >> amount;

    if (amount > 0) {
        balance += amount;
        writeBalanceToFile(balance);
        std::cout << "Deposit successful. Your new balance is: $" << balance << "\n";
    }
    else {
        std::cout << "Error: Deposit amount must be positive.\n";
    }
}

// Function to withdraw money
void withdraw(double& balance) {
    double amount;
    std::cout << "Enter withdrawal amount: ";
    std::cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        writeBalanceToFile(balance);
        std::cout << "Withdrawal successful. Your new balance is: $" << balance << "\n";
    }
    else if (amount <= 0) {
        std::cout << "Error: Withdrawal amount must be positive.\n";
    }
    else {
        std::cout << "Error: Insufficient funds. Your balance is $" << balance << "\n";
    }
}

// Main program loop
int main() {
    double balance = readBalanceFromFile();
    int choice;

    std::cout << "Welcome to Your Bank Account!\n";

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Deposit Money\n";
        std::cout << "3. Withdraw Money\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear(); // Clear error flag
            std::cin.ignore(10000, '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue;
        }

        switch (choice) {
        case 1:
            checkBalance(balance);
            break;
        case 2:
            deposit(balance);
            break;
        case 3:
            withdraw(balance);
            break;
        case 4:
            std::cout << "Thank you for using the bank system. Goodbye!\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }
    }
}
