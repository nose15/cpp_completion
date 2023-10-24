#ifndef INTFUNCTIONS_H
#define INTFUNCTIONS_H


// Klasa z przykładowymi statycznymi metodami, które w pliku main są zawarte w strukturach, które z kolei
// znajdują się w tablicy z funkcjami
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