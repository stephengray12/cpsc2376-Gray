#include "Fraction.h"
#include <numeric>

Fraction::Fraction() : num(0), den(1) {}

Fraction::Fraction(int n, int d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    num = n;
    den = d;
    simplify();
}

int Fraction::getNumerator() const { return num; }
int Fraction::getDenominator() const { return den; }

void Fraction::setNumerator(int n) {
    num = n;
    simplify();
}

void Fraction::setDenominator(int d) {
    if (d == 0) throw std::invalid_argument("Denominator cannot be zero");
    den = d;
    simplify();
}

void Fraction::simplify() {
    int gcd = std::gcd(num, den);
    num /= gcd;
    den /= gcd;
    if (den < 0) {
        num = -num;
        den = -den;
    }
}

Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.den + rhs.num * lhs.den, lhs.den * rhs.den);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.den - rhs.num * lhs.den, lhs.den * rhs.den);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    return Fraction(lhs.num * rhs.num, lhs.den * rhs.den);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.num == 0) throw std::invalid_argument("Cannot divide by zero");
    return Fraction(lhs.num * rhs.den, lhs.den * rhs.num);
}

std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.num << "/" << frac.den;
    return os;
}
