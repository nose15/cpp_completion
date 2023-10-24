#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

typedef int (*FunctionPtr)(int, int);

struct Function
{
    std::string name;
    FunctionPtr p_function;
};

#endif //ZALICZENIE_FUNCTION_H
