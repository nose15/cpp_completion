#include <iostream>
#include "include/FunctionArrayManager.h"
#include "include/IntFunctions.h"
#include "include/Function.h"


int main()
{
    Function subtract_function = {"subtract", IntFunctions::subtract};
    Function sum_function = {"sum", IntFunctions::sum};
    Function multiply_function = {"multiply", IntFunctions::multiply};

    Function funcArray[3] = {subtract_function, sum_function, multiply_function};

    FunctionArrayManager functionArrayManager(funcArray, 3);

    std::string func;
    int arg1, arg2;
    while (true)
    {
        std::cout << "Podaj funkcje i dwa argumenty:";
        std::cin >> func >> arg1 >> arg2;
        if (func == "stop") break;

        try
        {
            int result = functionArrayManager.executeFuncByName(func, arg1, arg2);
            std::cout << "Wykonywanie funkcji " << func << "(" << arg1 << ", " << arg2 << ")" << std::endl;
            std::cout << "Wynik: " << result << std::endl;
        }
        catch (std::runtime_error& e)
        {
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}