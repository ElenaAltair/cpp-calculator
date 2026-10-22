#include "calculator.h"

#include <cmath>
#include <string>

// Реализуйте здесь методы класса.
void Calculator::Set(Number n) {
  current_number_ = n;
}

Number Calculator::GetNumber() const {
  return current_number_;
}

void Calculator::Add(Number n) {
  current_number_ += n;
}

void Calculator::Sub(Number n) {
  current_number_ -= n;
}

void Calculator::Div(Number n) {
  current_number_ /= n;
}

void Calculator::Mul(Number n) {
  current_number_ *= n;
}

void Calculator::Pow(Number n) {
  current_number_ = std::pow(current_number_, n);
}

void Calculator::Save() {
  number_in_memory_ = current_number_;
  memory_is_used_ = true;
}

void Calculator::Load() { current_number_ = number_in_memory_; }

bool Calculator::HasMem() const { return memory_is_used_; }

std::string Calculator::GetNumberRepr() const {
  return std::to_string(current_number_);
}
