#include "Fraction.h"
#ifndef MIXEDFRACTION_H
#define MIXEDFRACTION_H


class MixedFraction : public Fraction {
private:
    int whole;
public:
    MixedFraction(int whole, int n, int d);
    MixedFraction(const Fraction& fraction);
    friend std::ostream& operator<<(std::ostream& os, const MixedFraction& frac);
};

#endif