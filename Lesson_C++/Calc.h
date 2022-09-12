#pragma once

#include <math.h>
#include <iostream>
#include <iomanip>

class Calculate
{
public:
    void Start(double inputNumber)
    {
        int index = 1;
        for (float x = start; x <= stop; x += step)
        {
            double sinus = sin(x);
            double square = sqrt(sinus - 0.5);
            double del = inputNumber - square;
            double y = 2 / del;

            CreateTable(x, y, index);
            index++;
        }
        std::cout << border << std::endl;

    };

    bool CheckStringOnDigit(std::string str)
    {
        bool tough = false;
        int index = 0;

        if (str[0] == '-')
            index++;

        while (index != str.length())
        {
            if (str[index] == '.')
                if (!tough)
                    tough = true;
                else
                    return false;
            else if (!isdigit(str[index]))
                return false;

            index++;
        }

        return true;
    };

    bool CheckDigitOnExpress(double digit)
    {
        if (digit <= -1000000)
            return false;
        else if (digit >= 1000000)
            return false;

        return true;
    };

private:
    const std::string border = "--------------------------------------";
    const float start = -2, stop = 7, step = 0.5;

    void CreateTable(double x, double y, int index)
    {
        std::cout << border << std::endl;
        std::cout << "|  " << std::setw(2) << index << std::setw(5) << "|  " << std::setw(4) << std::setprecision(1) << x << "  |  ";
        std::cout << std::fixed << std::setw(16) << std::setprecision(6) << y << std::setw(3) << "|" << std::endl;
    }
};

