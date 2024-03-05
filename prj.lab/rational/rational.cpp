#include <rational/rational.hpp>
#include <stdexcept>


Rational gcd1(const Rational rhs){
    int64_t a = rhs.num(), b = rhs.den();
    if (a < b) {
        std::swap(a, b);
    }
    if (b == 0) return Rational(0, 1);
    while (a % b != 0) {
        a = a % b;
        std::swap(a, b);
    }
    return Rational(rhs.num() / b, rhs.den() / b);
}


Rational::Rational(const int64_t &num, const int64_t &den) : num_(num), den_(den) {
    if (den_ == 0){
        throw std::invalid_argument("Div by zero");
    }
    if (den_ < 0){
        den_ = -den_;
        num_ = -num_;
    }
    simplifying();
}

std::ostream &Rational::Write(std::ostream &ostrm) const {
    ostrm << num_ << separator << den_;
    return ostrm;
}

Rational Rational::operator*=(const Rational &rhs) {
    num_ *= rhs.num_;
    den_ *= rhs.den_;
    Rational ans = gcd1(*this);
    num_ = ans.num_;
    den_ = ans.den_;
    return *this;
}

Rational Rational::operator+=(const Rational &rhs) {
    num_ *= rhs.den_;
    num_ += den_ * rhs.num_;
    den_ *= rhs.den_;
    Rational ans = gcd1(*this);
    num_ = ans.num_;
    den_ = ans.den_;
    return *this;
}

Rational Rational::operator-=(const Rational &rhs) {
    num_ *= rhs.den_;
    num_ -= den_ * rhs.num_;
    den_ *= rhs.den_;
    Rational ans = gcd1(*this);
    num_ = ans.num_;
    den_ = ans.den_;
    return *this;
}

Rational Rational::operator/=(const Rational &rhs) {
    if (rhs.num() == 0) throw std::invalid_argument("Div by zero");
    Rational lhs = rhs;
    int64_t temp = rhs.num_;
    lhs.num_ = rhs.den_;
    lhs.den_ = temp;
    return operator*=(Rational(lhs));
}


Rational operator+(const Rational& lhs, const Rational &rhs)
{
    return gcd1(Rational(lhs.num() * rhs.den() + rhs.num() * lhs.den(), lhs.den() * rhs.den()));
}
Rational operator+(const Rational& lhs, const int64_t rhs) { return lhs + Rational(rhs); }
Rational operator+(const int64_t lhs, const Rational& rhs) { return Rational(lhs) + rhs; }

Rational operator-(const Rational& lhs, const Rational &rhs){
    return gcd1(Rational(lhs.num() * rhs.den() - rhs.num() * lhs.den(), lhs.den() * rhs.den()));
}
Rational operator-(const Rational& lhs, const int64_t rhs) { return lhs - Rational(rhs); }
Rational operator-(const int64_t lhs, const Rational& rhs) { return Rational(lhs) - rhs; }

Rational operator*(const Rational& lhs, const Rational &rhs){
    return gcd1(Rational(lhs.num() * rhs.num(), lhs.den() * rhs.den()));
}
Rational operator*(const Rational& lhs, const int64_t rhs) { return lhs * Rational(rhs); }
Rational operator*(const int64_t lhs, const Rational& rhs) { return Rational(lhs) * rhs; }

Rational operator/(const Rational& lhs, const Rational &rhs){
    if (lhs.num() == 0) throw std::invalid_argument("Div by zero");
    return gcd1(Rational(lhs.num() * rhs.den(), lhs.den() * rhs.num()));
}
Rational operator/(const Rational& lhs, const int64_t rhs) { return lhs / Rational(rhs); }
Rational operator/(const int64_t lhs, const Rational& rhs) { return Rational(lhs) / rhs; }


std::istream &Rational::Read(std::istream &istrm) {
    int64_t num(0.0);
    char comma(0);
    int64_t den(1.0);
    istrm >> num >> comma >> den;
    if (istrm.good())
    {
        if (Rational::separator == comma)
        {
            num_ = num;
            den_ = den;
            simplifying();
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}


Rational &Rational::operator=(const Rational &rhs) {
    num_ = rhs.num_;
    den_ = rhs.den_;
    return *this;
}


bool operator<(const Rational& lhs, const Rational& rhs) {
    if (lhs.num() == 0) return rhs.num() > 0;
    else if (rhs.num() == 0) return lhs.num() < 0;
    else if (lhs == rhs) return false;
    return lhs.num() * rhs.den() < lhs.den() * rhs.num();
}
bool operator<(const Rational& lhs, const int64_t rhs) { return lhs < Rational(rhs); }
bool operator<(const int64_t lhs, const Rational& rhs) { return Rational(lhs) < rhs; }

bool operator<=(const Rational& lhs, const Rational& rhs){
    return lhs < rhs || lhs == rhs;
}
bool operator<=(const Rational& lhs, const int64_t rhs) { return lhs <= Rational(rhs); }
bool operator<=(const int64_t lhs, const Rational& rhs) { return Rational(lhs) <= rhs; }

bool operator>=(const Rational& lhs, const Rational& rhs){
    return !(lhs < rhs) || lhs == rhs;
}
bool operator>=(const Rational& lhs, const int64_t rhs) { return lhs >= Rational(rhs); }
bool operator>=(const int64_t lhs, const Rational& rhs) { return Rational(lhs) >= rhs; }

bool operator>(const Rational& lhs, const Rational& rhs){
    if (lhs == rhs) return false;
    return !(lhs < rhs);
}
bool operator>(const Rational& lhs, const int64_t rhs) { return lhs > Rational(rhs); }
bool operator>(const int64_t lhs, const Rational& rhs) { return Rational(lhs) > rhs; }

bool operator==(const Rational& lhs, const Rational& rhs){
    Rational a = gcd1(lhs), b = gcd1(rhs);
    return (a.num() == b.num()) && (a.den() == b.den());
}
bool operator==(const Rational& lhs, const int64_t rhs) { return lhs == Rational(rhs); }
bool operator==(const int64_t lhs, const Rational& rhs) { return Rational(lhs) == rhs; }

bool operator!=(const Rational& lhs, const Rational& rhs){
    return !operator==(lhs, rhs);
}
bool operator!=(const Rational& lhs, const int64_t rhs) { return lhs != Rational(rhs); }
bool operator!=(const int64_t lhs, const Rational& rhs) { return Rational(lhs) != rhs; }
