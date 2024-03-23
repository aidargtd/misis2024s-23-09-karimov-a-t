#include <cassert>
#include <iostream>
#include "rational/rational.hpp"

void test_rational() {
    // Test default constructor
    Rational r_def;
    assert(0 == r_def.num());
    assert(1 == r_def.den());

    // Test constructor with integer argument
    Rational r_int(3);
    assert(3 == r_int.num());
    assert(1 == r_int.den());

    // Test unary operator
    Rational r(3);
    Rational r_neg = -r;
    assert(-3 == r_neg.num());
    assert(-3 == +r_neg.num());
    // Test constructor with numerator and denominator arguments
    try {
        Rational r_invalid(1, 0);
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }

    // Test equality operator
    Rational r1, r2;
    r1 = Rational(2);
    r2 = Rational(2);
    assert(r1 == r2);

    // Test addition
    r1 = Rational(1, 10);
    r2 = Rational(1, 2);
    assert(r1 + r2 == Rational(3, 5));
    r1 += r2;
    assert(r1 == Rational(3, 5));

    // Test subtraction
    r1 = Rational(1, 2);
    r2 = Rational(1, 2);
    assert(r1 - r2 == Rational());
    r1 -= r2;
    assert(r1 == Rational());

    // Test multiplication
    r1 = Rational(4, 5);
    r2 = Rational(1, 2);
    assert(r1 * r2 == Rational(2, 5));
    r1 *= r2;
    assert(r1 == Rational(2, 5));

    // Test division
    r1 = Rational(1, 6);
    r2 = Rational(1, 2);
    assert(r1 / r2 == Rational(1, 3));
    r1 /= r2;
    assert(r1 == Rational(1, 3));

    // Test division by zero
    try {
        Rational r_div_zero(1, 10);
        Rational r_zero(0);
        r_div_zero /= r_zero;
    } catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
}

int main() {
    test_rational();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}
