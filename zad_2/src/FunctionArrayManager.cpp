#include "../include/FunctionArrayManager.h"

// Konstruktor klasy FunctionArrayManager, przyjmuje wskaźnik do tablicy z funkcjami oraz wielkosc tej tablicy,
// dzieki czemu później ułatwia operacje związane z tymi tablicami
FunctionArrayManager::FunctionArrayManager(Function * arr, int size)
{
    this->arr = arr;
    this->size = size;
}


FunctionPtr FunctionArrayManager::getFuncPtrByName(const std::string& name) {
    // Wyszukujemy w tablicy z funkcjami funkcję o podanej nazwie

    for (int i = 0; i < size; i++)
    {
        if (arr[i].name == name)
        {
            return arr[i].p_function;
        }
    }

    // Jeśli taka funkcja się nie znalazła zwracamy wskaźnik do 0
    return nullptr;
}


int FunctionArrayManager::executeFuncByName(const std::string& name, int arg1, int arg2)
{
    // odczytujemy wskaznik do funkcji
    FunctionPtr func = getFuncPtrByName(name);

    if (func != nullptr)
    {
        return func(arg1, arg2);
    }

    // jeśli nie ma funkcji o podanej przez użytkownika nazwie, zwracamy błąd
    throw std::runtime_error("Niepoprawna nazwa funkcji");
}