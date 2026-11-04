#pragma once

#include <cmath>
#include <optional>
#include <string>
#include <type_traits>

#include "pow.h"
#include "rational.h"

using Error = std::string;

template <typename Number>
class Calculator {
 public:
  inline void Set(Number n) {
    current_number_ = n;
  }

  inline Number GetNumber() const {
    return current_number_;
  }

  inline std::optional<Error> Add(Number n) {
    current_number_ += n;
    return std::nullopt;
  }

  inline std::optional<Error> Sub(Number n) {
    current_number_ -= n;
    return std::nullopt;
  }

  inline std::optional<Error> Div(Number n) {
    if (n == 0 && (std::is_integral_v<Number> || std::is_same_v<Number, Rational>)) {
      return "Division by zero";
    }
    current_number_ /= n;
    return std::nullopt;
  }

  inline std::optional<Error> Mul(Number n) {
    current_number_ *= n;
    return std::nullopt;
  }

  inline std::optional<Error> Pow(Number n) {
    if constexpr (std::is_integral_v<Number> || std::is_same_v<Number, Rational>) {
      if (current_number_ == 0 && n == 0) {
        return "Zero power to zero";
      }
    }
    if constexpr (std::is_same_v<Number, Rational>) {
      if (n.GetDenominator() != 1) {
        return "Fractional power is not supported";
      }
    }
    if constexpr (std::is_integral_v<Number>) {
      if (n < 0) {
        return "Integer negative power";
      }
    }
    if constexpr (std::is_integral_v<Number>) {
      current_number_ = IntegerPow(current_number_, n);
    } else if constexpr (std::is_same_v<Number, double> || std::is_same_v<Number, float>) {
      current_number_ = std::pow(current_number_, n);
    } else if constexpr (std::is_same_v<Number, Rational>) {
      current_number_ = ::Pow(current_number_, n); // Вызов из pow.h
    }
    return std::nullopt;
  }

  inline void Save() {
    number_in_memory_ = current_number_;
  }

  inline void Load() {
    if (number_in_memory_.has_value()) {
      current_number_ = number_in_memory_.value();
    }
  }

  inline bool GetHasMem() const {
    return number_in_memory_.has_value();
  }

  inline std::string GetNumberRepr() const {
    return std::to_string(current_number_);
  }

 private:
  Number current_number_ = 0;
  std::optional<Number> number_in_memory_ = std::nullopt;
};