#include "Fraction.h"
#include "MixedFraction.h"
#include <iostream>

void displayMenu() {
    std::cout << "\nOptions:\n";
    std::cout << "1. Enter a fraction manually\n";
    std::cout << "2. Add a fraction\n";
    std::cout << "3. Subtract a fraction\n";
    std::cout << "4. Multiply by a fraction\n";
    std::cout << "5. Divide by a fraction\n";
    std::cout << "6. Display as Mixed Fraction\n";
    std::cout << "7. Clear Fraction\n";
    std::cout << "8. Exit\n";
}

Fraction getFractionFromUser() {
    int num, den;
    std::cout << "Enter numerator: ";
    std::cin >> num;
    std::cout << "Enter denominator: ";
    std::cin >> den;
    return Fraction(num, den);
}

int main() {
    Fraction current(0, 1);
    int choice;

    while (true) {
        std::cout << "\nCurrent Fraction: " << current << "\n";
        displayMenu();
        std::cout << "Enter choice: ";
        std::cin >> choice;

        try {
            switch (choice) {
            case 1:
                current = getFractionFromUser();
                break;
            case 2:
                current = current + getFractionFromUser();
                break;
            case 3:
                current = current - getFractionFromUser();
                break;
            case 4:
                current = current * getFractionFromUser();
                break;
            case 5:
                current = current / getFractionFromUser();
                break;
            case 6: {
                MixedFraction mf(current);
                std::cout << "Mixed Fraction: " << mf << "\n";
                break;
            }
            case 7:
                current = Fraction(0, 1);
                break;
            case 8:
                return 0;
            default:
                std::cout << "Invalid choice, try again.";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }
}
