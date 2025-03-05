#include "Fraction.h"
#include "MixedFraction.h"
#include <iostream>

int main() {
    try {
        Fraction f1(1, 3);
        Fraction f2(2, 3);
        Fraction result = f1 + f2;
        std::cout << "Sum: " << result << std::endl;

        MixedFraction mixedResult(result);
        std::cout << "Mixed Fraction: " << mixedResult << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}