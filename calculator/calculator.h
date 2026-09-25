#pragma once
#include <string>

using Number = double;

// Возвращает true, если удалось прочитать число
// и сохранить его в Number.
bool ReadNumber(Number& result);

// Возвращает true, если работа завершилась штатно
// командой q. Если из-за ошибки, возвращает false.
bool RunCalculatorCycle();

int ReadCommand(std::string& command);

void Calculate(int command, Number& result, Number second_number);
