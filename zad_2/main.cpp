#include <iostream>
#include "include/FunctionArrayManager.h"
#include "include/IntFunctions.h"
#include "include/Function.h"


int main()
{
    // Definicja kilku struktur z funkcjami z użyciem przykładowych statycznych metod z klasy IntFunctions
    Function subtract_function = {"subtract", IntFunctions::subtract};
    Function sum_function = {"sum", IntFunctions::sum};
    Function multiply_function = {"multiply", IntFunctions::multiply};

    // Definicja tablicy zawierającej struktury z funkcjami
    Function funcArray[3] = {subtract_function, sum_function, multiply_function};

    // Inicjalizacja instancji klasy FunctionArrayManager z utworzoną wyżej tablicą i jej rozmiarem
    FunctionArrayManager functionArrayManager(funcArray, 3);

    // Pętla umożliwiająca użytkownikowi na wywoływanie wielu funkcji w trakcie jednego odpalenia programu
    std::string func;
    int arg1, arg2;
    while (true)
    {
        std::cout << "Podaj funkcje i dwa argumenty:";
        std::cin >> func >> arg1 >> arg2;
        if (func == "stop") break;

        try
        {
            // próbujemy wywołać funkcję o nazwie w zmiennej func
            int result = functionArrayManager.executeFuncByName(func, arg1, arg2);
            std::cout << "Wykonywanie funkcji " << func << "(" << arg1 << ", " << arg2 << ")" << std::endl;
            std::cout << "Wynik: " << result << std::endl;
        }
        catch (std::runtime_error& e) {
            // w przypadku wystąpienia błędu program powiadamia o tym użytkownika
            // najbardziej prawdopodobnym błędem będzie zwrócony przez functionArrayManager.executeFuncByName
            // runtime_error z wiadomością powiadamiającą o błędnej nazwie funkcji
            std::cout << e.what() << std::endl;
        }
    }

    return 0;
}