#include "Calc.h"
#include <iostream>
#include <string>

int main()
{
    setlocale(LC_ALL, "RUS");
    Calculate calc;

    std::string str;
    std::cout << "Введите параметр А ";
    std::cin >> str;
    
    if (!calc.CheckStringOnDigit(str))
    {
        std::cout << "Параметр А не является числом." << std::endl;
        return 0;
    }

    double inputNumber = round(std::stod(str) * 1000000) / 1000000;

    if (!calc.CheckDigitOnExpress(inputNumber))
    {
        std::cout << "Введенное число превышает границы заданных параметров." << std::endl;
        return 0;
    }

    calc.Start(inputNumber);

    system("pause");
    return 0;
}
