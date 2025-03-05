#include "Fraction.h"
#include "MixedFraction.h"
#include <iostream>

int main() {
    Fraction f1(1, 3);
    Fraction f2(2, 3);
    Fraction result = f1 + f2;
    std::cout << "Sum: " << result << std::endl;
    return 0;
}