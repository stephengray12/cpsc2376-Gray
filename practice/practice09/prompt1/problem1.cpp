#include <iostream>
#include <string>

int main() {
    float redPotion{ 0.0f };
    float bluePotion{ 0.0f };
    float* flask{ nullptr };

    std::string input;

    while (true) {
        std::cout << "Which potion would you like to add to? (Red/Blue/Done): ";
        std::getline(std::cin, input);

        if (input == "Done" || input == "done") {
            break;
        }
        else if (input == "Red" || input == "red") {
            flask = &redPotion;
        }
        else if (input == "Blue" || input == "blue") {
            flask = &bluePotion;
        }
        else {
            std::cout << "Invalid choice. Please enter Red, Blue, or Done.\n";
            continue;
        }

        float amount;
        std::cout << "How many mL would you like to add? ";
        std::cin >> amount;
        std::cin.ignore();

        *flask += amount;

        std::cout << "Red Potion: " << redPotion << " mL\n";
        std::cout << "Blue Potion: " << bluePotion << " mL\n";
    }

    std::cout << "Brewing complete. Final potion levels:\n";
    std::cout << "Red Potion: " << redPotion << " mL\n";
    std::cout << "Blue Potion: " << bluePotion << " mL\n";

    return 0;
}
