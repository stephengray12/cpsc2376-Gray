#include "MixedFraction.h"
#include <iostream>

MixedFraction::MixedFraction(int whole, int n, int d) : Fraction(n, d), whole(whole) {}

MixedFraction::MixedFraction(const Fraction& fraction) : Fraction(fraction) {
    whole = getNumerator() / getDenominator();
    setNumerator(getNumerator() % getDenominator());
}

std::ostream& operator<<(std::ostream& out, const MixedFraction& mf) {
    if (mf.whole != 0) {
        out << mf.whole << " ";
    }
    out << static_cast<const Fraction&>(mf);
    return out;
}
