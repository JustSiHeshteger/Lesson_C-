#include "Calc.h"
#include <iostream>
#include <string>

int main()
{
    //setlocale(LC_ALL, "RUS");
    Calculate calc;

    std::string str;
    std::cout << "Input parametr A ";
    std::cin >> str;
    
    if (!calc.CheckStringOnDigit(str))
    {
        std::cout << "Parametr A is not a number" << std::endl;
        return 0;
    }

    float inputNumber = std::stof(str);

    if (!calc.CheckDigitOnExpress(inputNumber))
    {
        std::cout << "Input value out of interval." << std::endl;
        return 0;
    }

    calc.Start(inputNumber);

    system("pause");
    return 0;
}
