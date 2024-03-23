#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <cstdint>
#include <iostream>

class Rational {
public:
    Rational() : num_(0), den_(1) {};

    Rational(const Rational &) = default;

    explicit Rational(const int64_t &num) : Rational(num, 1) {};

    Rational(const int64_t &num, const int64_t &den);


    [[nodiscard]] int64_t num() const { return num_; }

    [[nodiscard]] int64_t den() const { return den_; }

    Rational operator-() const noexcept { return Rational(-num_, -den_); };

    Rational &operator=(const Rational &rhs);

    /// ASSIGNING OPERATIONS
    Rational operator*=(const Rational &rhs);

    Rational operator*=(const int64_t rhs) { return operator*=(Rational(rhs)); };

    Rational operator+=(const Rational &rhs);

    Rational operator+=(const int64_t rhs) { return operator+=(Rational(rhs)); };

    Rational operator-=(const Rational &rhs);

    Rational operator-=(const int64_t rhs) { return operator-=(Rational(rhs)); };

    Rational operator/=(const Rational &rhs);

    Rational operator/=(const int64_t rhs) { return operator/=(Rational(rhs)); };

    ~Rational() = default;

    std::ostream &Write(std::ostream &ostrm) const;

    std::istream &Read(std::istream &istrm);

    Rational operator-();

    Rational operator+();

    Rational operator++();

    Rational operator--();

    Rational operator++(int);

    Rational operator--(int);

private:
    int64_t num_ = 0;
    int64_t den_ = 1;
    static const char separator = {'/'};

    int64_t gcd(int64_t lhs, int64_t rhs) {
        return lhs == 0 ? rhs : gcd(rhs % lhs, lhs);
    }

    void simplifying() {
        int64_t common_mult = gcd(std::abs(num_), den_);
        num_ /= common_mult;
        den_ /= common_mult;
    }
};

//IN CASE THAT USER WILL PRINT RATIONAL VARIABLE IN CONSOLE
inline std::ostream &operator<<(std::ostream &ostr, const Rational &rhs) {
    return rhs.Write(ostr);
}

inline std::istream &operator>>(std::istream &istr, Rational &rhs) {
    return rhs.Read(istr);
}


Rational operator+(const Rational &lhs, const Rational &rhs);

Rational operator+(const Rational &lhs, const int64_t rhs);

Rational operator+(const int64_t lhs, const Rational &rhs);

Rational operator-(const Rational &lhs, const Rational &rhs);

Rational operator-(const Rational &lhs, const int64_t rhs);

Rational operator-(const int64_t lhs, const Rational &rhs);

Rational operator*(const Rational &lhs, const Rational &rhs);

Rational operator*(const Rational &lhs, const int64_t rhs);

Rational operator*(const int64_t lhs, const Rational &rhs);

Rational operator/(const Rational &lhs, const Rational &rhs);

Rational operator/(const Rational &lhs, const int64_t rhs);

Rational operator/(const int64_t lhs, const Rational &rhs);

bool operator<(const Rational &lhs, const Rational &rhs);

bool operator<(const int64_t lhs, const Rational &rhs);

bool operator<(const Rational &lhs, const int64_t rhs);

bool operator>(const Rational &lhs, const Rational &rhs);

bool operator>(const int64_t lhs, const Rational &rhs);

bool operator>(const Rational &lhs, const int64_t rhs);

bool operator<=(const Rational &lhs, const Rational &rhs);

bool operator<=(const int64_t lhs, const Rational &rhs);

bool operator<=(const Rational &lhs, const int64_t rhs);

bool operator>=(const Rational &lhs, const Rational &rhs);

bool operator>=(const int64_t lhs, const Rational &rhs);

bool operator>=(const Rational &lhs, const int64_t rhs);


bool operator==(const Rational &lhs, const Rational &rhs);

bool operator==(const int64_t lhs, const Rational &rhs);

bool operator==(const Rational &lhs, const int64_t rhs);

bool operator!=(const Rational &lhs, const Rational &rhs);

bool operator!=(const int64_t lhs, const Rational &rhs);

bool operator!=(const Rational &lhs, const int64_t rhs);

#endif
