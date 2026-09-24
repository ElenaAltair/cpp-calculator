#include "calculator.h"
#include <iostream>
#include <string>
#include <cmath>

// Возвращает true, если удалось прочитать число
// и сохранить его в Number.
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

int CalculatorCommands(std::string& command)
{
    std::cin >> command;

    if (command == "q") 
        return 0;

    if (command == "c") 
        return 2;
    
    if (command == "=") 
        return 3;

    if (command == "+") 
        return 10; 

    if (command == "-") 
        return 11;  
    
    if (command == "*") 
        return 12; 
    
    if (command == "**") 
        return 13; 

    if (command == "/") 
        return 14;    
    
    if (command == ":") 
        return 15; 

    if (command == "s") 
        return 16; 
    
    if (command == "l")
        return 17;

    std::cerr << "Error: Unknown token " << command << std::endl;
    return -1; 
}

void Calculation (int command, Number& result, Number number_2, bool& result_inf)
{
    if (command == 10) // "+"
    {
        result += number_2;

    } else if (command == 11) // "-"
    {
        result -= number_2;

    } else if (command == 12) // "*"
    {
        result *= number_2;

    } else if (command == 13) // "**"
    {
        result = std::pow(result, number_2);

    } else if (command == 14) // "/"
    {
        if (number_2 != 0) 
        {
            result /= number_2;
        } else 
        {
            result_inf = true;
        }
    } else if (command == 15) // ":"
    {
        result_inf = false;
        result = number_2;
    } 
}

// Возвращает true, если работа завершилась штатно 
// командой q. Если из-за ошибки, возвращает false.
bool RunCalculatorCycle()
{
    // Число калькулятора.
    Number result;
    Number memory = 0;
    bool memory_is_used = false;
    bool end_with_q = true;
    bool calculator_is_working = true;
    bool result_inf = false; // деление на 0

    if(!ReadNumber(result))
    {
        return false;
    }

    while (calculator_is_working == true) 
    {
        std::string command;
        int is_command = CalculatorCommands(command);

        if (is_command == 0) // завершение работы по q
        {
            end_with_q = true;
            calculator_is_working = false;

        } else if (is_command == -1) // завершение работы с ошибкой
        {
            end_with_q = false;
            calculator_is_working = false;

        } else if (is_command >= 10 && is_command <= 15) // получена мат.операция
        {
            Number number_2;
            bool is_number = ReadNumber(number_2);

            if (is_number == false)
            {   
                calculator_is_working = false;
                end_with_q = false;

            } else 
            {
                Calculation (is_command, result, number_2, result_inf);
            }
        } else if (is_command == 2) // сбросить значение (c)
        {
            result_inf = false;
            result = 0;
        } else if (is_command == 3) // знак равно
        {
            if(result_inf == false) 
            {
                std::cout << result << std::endl;
            } else {
                std::cout << "inf" << std::endl;
            }
        } else if (is_command == 16) // знак s  сохранение в память
        {
            memory_is_used = true;
            memory = result;
        }  else if (is_command == 17) // знак l  извлечение из памяти
        {
            if (memory_is_used ==  true)
            {
                result = memory;
            } else
            {
                std::cerr << "Error: Memory is empty" << std::endl;
                calculator_is_working = false;
            }
        } 
    }
    return end_with_q;
}
