#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <unordered_set>
#include <vector>
#include <cctype>

class Strategy {
public:
    virtual std::string apply(const std::string& input) const = 0;
    virtual ~Strategy() = default;
};

class Reverse : public Strategy {
public:
    std::string apply(const std::string& input) const override {
        std::string result = input;
        std::reverse(result.begin(), result.end());
        return result;
    }
};

class Uppercase : public Strategy {
public:
    std::string apply(const std::string& input) const override {
        std::string result = input;
        std::transform(result.begin(), result.end(), result.begin(), ::toupper);
        return result;
    }
};

class RemoveVowels : public Strategy {
public:
    std::string apply(const std::string& input) const override {
        std::string result;
        for (char ch : input) {
            if (!strchr("aeiouAEIOU", ch)) {
                result += ch;
            }
        }
        return result;
    }
};



void showMenu() {
    std::cout << "\nChoose a filter strategy:\n"
        << "1. Reverse\n"
        << "2. Uppercase\n"
        << "3. Remove vowels\n"
        << "0. Exit\n> ";
}

int main() {
    std::string input;
    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    std::unique_ptr<Strategy> strategy;

    while (true) {
        showMenu();
        int choice;
        std::cin >> choice;
        std::cin.ignore(); // Flush newline from buffer

        if (choice == 0) break;

        switch (choice) {
        case 1: strategy = std::make_unique<Reverse>(); break;
        case 2: strategy = std::make_unique<Uppercase>(); break;
        case 3: strategy = std::make_unique<RemoveVowels>(); break;
        default:
            std::cout << "Invalid choice.\n";
            continue;
        }

        std::cout << "Processed: " << strategy->apply(input) << "\n";
    }

    return 0;
}
