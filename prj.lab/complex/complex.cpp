#include <iostream>
#include <complex/complex.hpp>


Complex Complex::operator-() const noexcept {return Complex(-re, -im);}

Complex &Complex::operator+=(const Complex &rhs){
  re += rhs.re;
  im += rhs.im;
  return *this;
}
Complex &Complex::operator*=(const Complex &rhs){
  double a, b;
  a = re * rhs.re;
  a -= im * rhs.im;
  b = im * rhs.re;
  b += re * rhs.im;
  re = a;
  im = b;
  return *this;
}

Complex &Complex::operator-=(const Complex &rhs) {
  re -= rhs.re;
  im -= rhs.im;
  return *this;
}

Complex &Complex::operator/=(const Complex &rhs) {
  if (rhs.re == 0 && rhs.im == 0){
    throw std::runtime_error("Div by zero");
  }
  else {
    auto real = float(re * rhs.re + im * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    auto imagin = float(im * rhs.re - re * rhs.im) / (rhs.re * rhs.re + rhs.im * rhs.im);
    re = real;
    im = imagin;
  }
  return *this;
}

Complex &Complex::operator*=(const double &rhs) {
  re *= rhs;
  im *= rhs;
  return *this;
}
Complex &Complex::operator/=(const double &rhs) {
  re /= rhs;
  im /= rhs;
  return *this;
}
Complex &Complex::operator=(const Complex& rhs) {
  re = rhs.re;
  im = rhs.im;
  return *this;
}

std::ostream &Complex::WriteTo(std::ostream &ostrm) const noexcept{
    ostrm << leftBrace << re << separator << im << rightBrace;
    return ostrm;
}

std::istream &Complex::ReadFrom(std::istream &istrm) noexcept{
    char left(0);
    double rea(0.0);
    char comma(0);
    double ima(0.0);
    char right(0);
    istrm >> left >> rea >> comma >> ima >> right;
    if (istrm.good())
    {
        if ((Complex::leftBrace == left) && (Complex::separator == comma) && (Complex::rightBrace == right))
        {
            re = rea;
            im = ima;
        }
        else
        {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

Complex &Complex::operator=(const double rhs) {
  return operator=(Complex(rhs));
}

Complex operator+(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }
Complex operator+(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) += Complex(rhs); }
Complex operator+(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) += rhs; }

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }
Complex operator-(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) -= Complex(rhs); }
Complex operator-(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) -= rhs; }

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }
Complex operator*(const Complex& lhs, const double rhs) noexcept { return Complex(lhs) *= Complex(rhs); }
Complex operator*(const double lhs, const Complex& rhs) noexcept { return Complex(lhs) *= rhs; }

Complex operator/(const Complex& lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }
Complex operator/(const Complex& lhs, const double rhs) { return Complex(lhs) /= Complex(rhs); }
Complex operator/(const double lhs, const Complex& rhs) { return Complex(lhs) /= rhs; }