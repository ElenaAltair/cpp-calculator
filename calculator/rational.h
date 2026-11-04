#pragma once

#include <iostream>
#include <numeric>

using namespace std::literals;

class Rational {
 public:
  Rational() = default;

  inline Rational(int numerator) { numerator_ = numerator; }

  inline Rational(int numerator, int denominator) {
    if (denominator != 0) {
      numerator_ = numerator;
      denominator_ = denominator;
      Reduction();
    }
  }

  Rational(const Rational& r)
      : numerator_(r.numerator_), denominator_(r.denominator_) {};

  inline void Reduction() {
    if (denominator_ < 0) {
      numerator_ = -numerator_;
      denominator_ = -denominator_;
    }
    const int divisor = std::gcd(numerator_, denominator_);
    numerator_ /= divisor;
    denominator_ /= divisor;
  }

  inline int GetDenominator() const { return denominator_; }
  inline int GetNumerator() const { return numerator_; }

  inline Rational Inv() const { return Rational(denominator_, numerator_); }

  // Унарные операторы
  inline Rational operator+() const { return *this; }
  inline Rational operator-() const {
    return Rational(-numerator_, denominator_);
  }

  inline Rational& operator+=(const Rational& r2) {
    numerator_ = numerator_ * r2.denominator_ + denominator_ * r2.numerator_;
    denominator_ = denominator_ * r2.denominator_;
    Reduction();
    return *this;
  }

  inline Rational& operator-=(const Rational& r2) {
    numerator_ = numerator_ * r2.denominator_ - denominator_ * r2.numerator_;
    denominator_ = denominator_ * r2.denominator_;
    Reduction();
    return *this;
  }

  inline Rational& operator*=(const Rational& r2) {
    numerator_ = numerator_ * r2.numerator_;
    denominator_ = denominator_ * r2.denominator_;
    Reduction();
    return *this;
  }

  inline Rational& operator/=(const Rational& r2) {
    numerator_ = numerator_ * r2.denominator_;
    denominator_ = denominator_ * r2.numerator_;
    Reduction();
    return *this;
  }

  inline Rational operator+(const Rational& r2) const {
    Rational other{*this};
    other += r2;
    return other;
  }

  inline Rational operator-(const Rational& r2) const {
    Rational other{*this};
    other -= r2;
    return other;
  }

  inline Rational operator*(const Rational& r2) const {
    Rational other{*this};
    other *= r2;
    return other;
  }

  inline Rational operator/(const Rational& r2) const {
    Rational other{*this};
    other /= r2;
    return other;
  }

  inline Rational& operator=(const Rational& r) {
    if (this != &r) {
      numerator_ = r.numerator_;
      denominator_ = r.denominator_;
    }
    return *this;
  }

  friend std::istream& operator>>(std::istream& is, Rational& rational);
  friend std::ostream& operator<<(std::ostream& os, const Rational& rational);

 private:
  int numerator_ = 0;
  int denominator_ = 1;
};

inline auto operator<=>(const Rational& r1, const Rational& r2) {
  return (static_cast<double>(r1.GetNumerator()) / r1.GetDenominator()) <=>
         (static_cast<double>(r2.GetNumerator()) / r2.GetDenominator());
}

inline bool operator==(const Rational& r1, const Rational& r2) {
  return (r1.GetNumerator() == r2.GetNumerator()) &&
         (r1.GetDenominator() == r2.GetDenominator());
}

inline std::istream& operator>>(std::istream& is, Rational& rational) {
  int numerator = 0;
  int denominator = 1;

  if (!(is >> numerator)) return is;

  char slash;
  if (!(is >> slash)) {
    is.clear();
    rational.numerator_ = numerator;
    rational.denominator_ = 1;
    return is;
  }

  if (slash != '/') {
    is.unget();
    rational.numerator_ = numerator;
    rational.denominator_ = 1;
    return is;
  }

  if (!(is >> denominator)) {
    is.setstate(std::ios::failbit);
    return is;
  }

  if (denominator == 0) {
    is.setstate(std::ios::failbit);
    return is;
  }

  rational.numerator_ = numerator;
  rational.denominator_ = denominator;
  rational.Reduction();
  return is;
}

inline std::ostream& operator<<(std::ostream& os, const Rational& rational) {
  if (rational.denominator_ == 1) {
    os << rational.numerator_;
  } else {
    os << rational.numerator_ << " / " << rational.denominator_;
  }
  return os;
}
