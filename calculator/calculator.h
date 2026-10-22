#pragma once

#include <string>

using Number = double;

// Реализуйте здесь класс Calculator.
class Calculator {
 public:
  void Set(Number n);
  Number GetNumber() const;
  void Add(Number n);
  void Sub(Number n);
  void Div(Number n);
  void Mul(Number n);
  void Pow(Number n);
  void Save();
  void Load();
  bool HasMem() const;
  std::string GetNumberRepr() const;

 private:
  Number current_number_ = 0;
  Number number_in_memory_ = 0;
  bool memory_is_used_ = false;
};
