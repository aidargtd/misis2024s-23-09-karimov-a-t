#include <iostream>
#include <sstream>

#ifndef MISIS2024S_23_09_KARIMOV_A_T_COMPLEX_H
#define MISIS2024S_23_09_KARIMOV_A_T_COMPLEX_H
#include <limits>
#include <limits>

struct Complex {
    Complex() = default;
    Complex(const Complex &) = default;
    explicit Complex(const double real) : re(real) {};
    Complex(const double real, const double imaginary) : re(real), im(imaginary) {};

    Complex &operator=(const Complex &rhs);
    Complex &operator=(const double rhs);
    Complex operator-() const noexcept;

    ~Complex() = default;


    bool operator==(const Complex &rhs) const {return (std::abs(re - rhs.re) <= minDiff) && (std::abs(im - rhs.im) <= minDiff);}
    bool operator==(const double &rhs) const { return (std::abs(re - rhs) <= minDiff) && (std::abs(im) <= minDiff);}
    bool operator!=(const Complex &rhs) const { return !operator==(rhs); }
    bool operator!=(const double &rhs) const { return !operator==(rhs); }

    Complex &operator+=(const Complex &rhs);
    Complex &operator+=(const double &rhs) { return operator+=(Complex(rhs)); }

    Complex &operator-=(const Complex &rhs);
    Complex &operator-=(const double &rhs) { return operator-=(Complex(rhs)); }

    Complex &operator*=(const Complex &rhs);
    Complex &operator*=(const double &rhs);

    Complex &operator/=(const Complex &rhs);
    Complex &operator/=(const double &rhs);

    std::ostream &WriteTo(std::ostream &ostrm) const noexcept;
    std::istream &ReadFrom(std::istream &istrm) noexcept;


    double re{0.0};
    double im{0.0};

    static const char leftBrace{'{'};
    static const char separator{','};
    static const char rightBrace{'}'};
    const double minDiff = 2 * std::numeric_limits<double>::epsilon();
};

Complex operator+(const Complex &lhs, const Complex &rhs) noexcept;
Complex operator+(const Complex &lhs, const double rhs) noexcept;
Complex operator+(const double lhs, const Complex &rhs) noexcept;


Complex operator-(const Complex &lhs, const Complex &rhs) noexcept;
Complex operator-(const Complex &lhs, const double rhs) noexcept;
Complex operator-(const double lhs, const Complex &rhs) noexcept;

Complex operator*(const Complex &lhs, const Complex &rhs) noexcept;
Complex operator*(const Complex &lhs, const double rhs) noexcept;
Complex operator*(const double lhs, const Complex &rhs) noexcept;


Complex operator/(const Complex &lhs, const Complex &rhs);
Complex operator/(const Complex &lhs, const double rhs);
Complex operator/(const double lhs, const Complex &rhs);

inline std::ostream &operator<<(std::ostream &ostrm, const Complex &rhs) noexcept {
    return rhs.WriteTo(ostrm);
}

inline std::istream &operator>>(std::istream &istrm, Complex &rhs) noexcept {
    return rhs.ReadFrom(istrm);
}

#endif