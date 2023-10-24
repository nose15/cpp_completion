#ifndef INTFUNCTIONS_H
#define INTFUNCTIONS_H


class IntFunctions
{
public:
    static int sum(int, int);
    static int subtract(int, int);
    static int multiply(int, int);

    IntFunctions() = delete;
};

#include "../src/IntFunctions.cpp"
#endif