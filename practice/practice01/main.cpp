#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <map>

// Function to print the vector (const reference to avoid copying)
void printVector(const std::vector<int>& vec) {
    if (vec.empty()) {
        std::cout << "The vector is empty.\n";
        return;
    }
    std::cout << "Vector contents: ";
    for (const int& num : vec) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}


//Did use some AI from chat gpt to explain how to do some things, especially with setting up visual studio alongside the tutorial video on blackboard.
// Function to double the values in the vector (by reference to modify original vector)
void doubleVector(std::vector<int>& vec) {
    for (int& num : vec) {
        num *= 2;
    }
    std::cout << "All values in the vector have been doubled.\n";
}

// Function to calculate the sum of the vector (const reference)
int calculateSum(const std::vector<int>& vec) {
    return std::accumulate(vec.begin(), vec.end(), 0);
}

// Function to print multiples of a user-defined value (const reference for read-only access)
void printMultiples(const std::vector<int>& vec, int value) {
    if (value == 0) {
        std::cout << "Cannot find multiples of zero.\n";
        return;
    }

    std::vector<int> multiples;
    std::copy_if(vec.begin(), vec.end(), std::back_inserter(multiples), [&value](int num) {
        return num % value == 0;
        });

    if (multiples.empty()) {
        std::cout << "No multiples of " << value << " found in the vector.\n";
    }
    else {
        std::cout << "Multiples of " << value << ": ";
        for (const int& num : multiples) {
            std::cout << num << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<int> vec;
    int choice = 0;
    bool exit = false;

    // Map menu options to functions
    std::map<int, std::function<void()>> menu = {
        {1, [&]() {
            int num;
            std::cout << "Enter a number to add to the vector: ";
            std::cin >> num;
            vec.push_back(num);
            std::cout << num << " added to the vector.\n";
        }},
        {2, [&]() {
            printVector(vec);
        }},
        {3, [&]() {
            doubleVector(vec);
        }},
        {4, [&]() {
            int sum = calculateSum(vec);
            std::cout << "The sum of the vector is: " << sum << "\n";
        }},
        {5, [&]() {
            int value;
            std::cout << "Enter a number to find multiples of: ";
            std::cin >> value;
            printMultiples(vec, value);
        }},
        {6, [&]() {
            std::cout << "Exiting the program. Goodbye!\n";
            exit = true;
        }}
    };

    // Menu loop
    while (!exit) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add an item to the vector\n";
        std::cout << "2. Print the vector\n";
        std::cout << "3. Double the vector\n";
        std::cout << "4. Find the sum of the vector\n";
        std::cout << "5. Print multiples of a user-defined value\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Execute the corresponding function if the choice is valid
        if (menu.find(choice) != menu.end()) {
            menu[choice]();
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
