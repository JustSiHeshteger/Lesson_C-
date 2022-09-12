#pragma once

#include <math.h>
#include <iostream>
#include <iomanip>
#include <string>

class Calculate
{
public:
    void Start(float inputNumber)
    {
        int index = 1;
        FillTable("x", "y", "#", "a");

        for (float x = start; x <= stop; x += step)
        {
            double y = 2 / (inputNumber - sqrt(sin(x) - 0.5));

            if (CheckStringOnDigit(std::to_string(y)))
                FillTable(x, y, index, inputNumber);
            else
                FillTable(x, "Not Existing", index, inputNumber);

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

    bool CheckDigitOnExpress(float digit)
    {
        if (digit <= -1000000)
            return false;
        else if (digit >= 1000000)
            return false;

        return true;
    };

private:
    const std::string border = "-----------------------------------------------------------";
    const float start = -2, stop = 7, step = 0.5;

    void FillTable(float x, double y, int index, float a) //y - число
    {
        std::cout << border << std::endl;
        std::cout << "|  " << std::setw(2) << index << std::setw(5) << "|  " << std::setw(4) << std::setprecision(1) << x << "  |  ";
        std::cout << std::fixed << std::setw(16) << std::setprecision(6) << a << std::setw(3) << "  |  ";
        std::cout << std::fixed << std::setw(16) << std::setprecision(6) << y << std::setw(3) << "|" << std::endl;
    }

    void FillTable(float x, std::string y, int index, float a) //y - не удалось посчитать
    {
        std::cout << border << std::endl;
        std::cout << "|  " << std::setw(2) << index << std::setw(5) << "|  " << std::setw(4) << std::setprecision(1) << x << "  |  ";
        std::cout << std::fixed << std::setw(16) << std::setprecision(6) << a << std::setw(3) << "  |  ";
        std::cout << std::setw(16) << y << std::setw(3) << "|" << std::endl;
    }

    void FillTable(std::string x, std::string y, std::string index, std::string a) 
    {
        std::cout << border << std::endl;
        std::cout << "|  " << std::setw(2) << index << std::setw(5) << "|  " << std::setw(4) << x << "  |  ";
        std::cout << std::setw(16) << a << std::setw(3) << "  |  ";
        std::cout << std::setw(16) << y << std::setw(3) << "|" << std::endl;
    }
};

