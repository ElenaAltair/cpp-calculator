#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>

const int COMMAND_EXIT_BY_ERROR = -1;
const int COMMAND_EXIT = 1;
const int COMMAND_RESET = 2;
const int COMMAND_EQUALLY = 3;
const int COMMAND_PLUS = 10;
const int COMMAND_MINUS = 11;
const int COMMAND_MULTIPLY = 12;
const int COMMAND_RAISE_TO_POWER = 13;
const int COMMAND_DIVIDED = 14;
const int COMMAND_NEW_NUMBER = 15;
const int COMMAND_SAVE = 16;
const int COMMAND_EXTRACT_FROM_MEMORY = 17;

bool ReadNumber(Number& result)
{
    bool is_number = true;

    if(!(std::cin >> result))
    {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        is_number = false;
    }

    return is_number;
}

int ReadCommand(std::string& command)
{
    std::cin >> command;

    if (command == "q")
    {
        return COMMAND_EXIT;
    }

    if (command == "c")
    {
        return COMMAND_RESET;
    }

    if (command == "=")
    {
        return COMMAND_EQUALLY;
    }

    if (command == "+")
    {
        return COMMAND_PLUS;
    }

    if (command == "-")
    {
        return COMMAND_MINUS;
    }

    if (command == "*")
    {
        return COMMAND_MULTIPLY;
    }

    if (command == "**")
    {
        return COMMAND_RAISE_TO_POWER;
    }

    if (command == "/")
    {
        return COMMAND_DIVIDED;
    }

    if (command == ":") {
        return COMMAND_NEW_NUMBER;
    }

    if (command == "s")
    {
        return COMMAND_SAVE;
    }

    if (command == "l")
    {
        return COMMAND_EXTRACT_FROM_MEMORY;
    }

    std::cerr << "Error: Unknown token " << command << std::endl;
    return COMMAND_EXIT_BY_ERROR;
}

void Calculate (int command, Number& result, Number second_number)
{
    if (command == COMMAND_PLUS) // "+"
    {
        result += second_number;

    } else if (command == COMMAND_MINUS) // "-"
    {
        result -= second_number;

    } else if (command == COMMAND_MULTIPLY) // "*"
    {
        result *= second_number;

    } else if (command == COMMAND_RAISE_TO_POWER) // "**"
    {
        result = std::pow(result, second_number);

    } else if (command == COMMAND_DIVIDED) // "/"
    {
        result /= second_number;

    } else if (command == COMMAND_NEW_NUMBER) // ":"
    {
        result = second_number;
    }
}


bool RunCalculatorCycle()
{
    // Число калькулятора.
    Number result = 0;
    Number memory = 0;
    bool memory_is_used = false;

    if(!ReadNumber(result))
    {
        return false;
    }

    while (true)
    {
        std::string command;
        int command_code = ReadCommand(command);

        if (command_code == COMMAND_EXIT) // завершение работы по q
        {
            return true;

        } else if (command_code == COMMAND_EXIT_BY_ERROR) // завершение работы с ошибкой
        {
            return false;

        } else if (command_code == COMMAND_PLUS || command_code == COMMAND_MINUS || command_code == COMMAND_MULTIPLY || command_code == COMMAND_RAISE_TO_POWER || command_code == COMMAND_DIVIDED || command_code == COMMAND_NEW_NUMBER) // получена мат.операция
        {
            Number second_number = 0;
            bool is_number = ReadNumber(second_number);

            if (!is_number)
            {
                return false;

            } else
            {
                Calculate (command_code, result, second_number);
            }
        } else if (command_code == COMMAND_RESET) // сбросить значение (c)
        {
            result = 0;
        } else if (command_code == COMMAND_EQUALLY) // знак равно
        {
            std::cout << result << std::endl;
        } else if (command_code == COMMAND_SAVE) // знак s  сохранение в память
        {
            memory_is_used = true;
            memory = result;
        } else if (command_code == COMMAND_EXTRACT_FROM_MEMORY) // знак l  извлечение из памяти
        {
            if (memory_is_used)
            {
                result = memory;
            } else
            {
                std::cerr << "Error: Memory is empty" << std::endl;
                return false;
            }
        }
    }
    return true;
}
