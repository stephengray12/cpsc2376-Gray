#include "MixedFraction.h"

MixedFraction::MixedFraction(int whole, int n, int d) : Fraction(n, d), whole(whole) {}

MixedFraction::MixedFraction(const Fraction& fraction) : Fraction(fraction) {
    whole = fraction.getNumerator() / fraction.getDenominator();
}

std::ostream& operator<<(std::ostream& os, const MixedFraction& frac) {
    int n = frac.getNumerator() % frac.getDenominator();
    if (frac.whole != 0) os << frac.whole << " ";
    if (n != 0) os << n << "/" << frac.getDenominator();
    return os;
}