#ifndef FUNCTION_H
#define FUNCTION_H

#include <string>

// Plik w którym w celu enkapsulacji zdefiniowałem strukutrę zawierającą nazwę funkcji oraz
// specjalny wskaźnik do funkcji która zwraca int i przyjmuje dwa argumenty typu int
typedef int (*FunctionPtr)(int, int);

struct Function
{
    std::string name;
    FunctionPtr p_function;
};

#endif //ZALICZENIE_FUNCTION_H
