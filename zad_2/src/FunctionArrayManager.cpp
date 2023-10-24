#include "../include/FunctionArrayManager.h"

FunctionArrayManager::FunctionArrayManager(Function * arr, int size)
{
    this->arr = arr;
    this->size = size;
}


FunctionPtr FunctionArrayManager::getFuncPtrByName(const std::string& name) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i].name == name)
        {
            return arr[i].p_function;
        }
    }

    return nullptr;
}


int FunctionArrayManager::executeFuncByName(const std::string& name, int arg1, int arg2)
{
    FunctionPtr func = getFuncPtrByName(name);

    if (func != nullptr)
    {
        return func(arg1, arg2);
    }

    throw std::runtime_error("Niepoprawna nazwa funkcji");
}