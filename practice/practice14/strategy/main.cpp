#include <iostream>
#include <memory>
#include <string>
#include <algorithm>

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

int main() {
    std::unique_ptr<Strategy> strategy = std::make_unique<Reverse>();

    std::string text;
    std::cout << "Enter text: ";
    std::getline(std::cin, text);

    std::cout << "Filtered: " << strategy->apply(text) << "\n";
}
