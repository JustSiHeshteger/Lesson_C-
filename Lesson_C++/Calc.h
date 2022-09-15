#pragma once

#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>

class Calculate
{
public:
    std::string _normalStr;

    void Start(double inputNumber)
    {
        int index = 1;
        FillTable("x", "y", "#", "a");

        for (float x = start; x <= stop; x += step)
        {
            float square = sqrt(sin(x) - 0.5f);
            double y = 2 / (inputNumber - square);
            std::string result = std::to_string(y);

            if (CheckStringOnDigit(result))
                FillTable(x, result, index, inputNumber);
            else
                FillTable(x, "Not Existing", index, inputNumber);

            index++;
        }
        std::cout << border << std::endl;
    };

    bool CheckStringOnDigit(std::string str)
    {
        bool dot = false, isNegative = false;
        int index = 0, length = str.length();

        if (str[0] == '-')
        {
            isNegative = true;
            index++;
        }

        for (index; index < length; index++)
        {
            if (str[index] == '.')
            {
                if (!dot)
                    dot = true;
                else
                    return false;
            }
            else if (str[index] == ',')
            {
                if (!dot)
                {
                    str[index] = '.';
                    dot = true;
                }
                else
                    return false;
            }
            else if (str[index] == '-')
                return false;
            else if (!isdigit(str[index]))
                return false;
        }

        if ((dot && length == 1) || (isNegative && length == 1))
            return false;

        _normalStr = str;

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
    const std::string border = "---------------------------------------------------------------";
    const float start = -2, stop = 7, step = 0.5;

    void FillTable(float x, std::string y, int index, double a) 
    {
        std::cout << border << std::endl;
        std::cout << "|  " << std::setw(2) << index << std::setw(5) << "|  " << std::setw(4) << std::setprecision(1) << x << "  |  ";
        std::cout << std::fixed << std::setw(16) << std::setprecision(6) << a << std::setw(3) << "  |  ";
        std::cout << std::setw(20) << y << std::setw(3) << "|" << std::endl;
    }

    void FillTable(std::string x, std::string y, std::string index, std::string a) 
    {
        std::cout << border << std::endl;
        std::cout << "|  " << std::setw(2) << index << std::setw(5) << "|  " << std::setw(4) << x << "  |  ";
        std::cout << std::setw(16) << a << std::setw(3) << "  |  ";
        std::cout << std::setw(20) << y << std::setw(3) << "|" << std::endl;
    }
};

