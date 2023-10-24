#ifndef FUNCTIONARRAYMANAGER_H
#define FUNCTIONARRAYMANAGER_H

#include "Function.h"

class FunctionArrayManager
{
private:
    Function * arr;
    int size;

    FunctionPtr getFuncPtrByName(const std::string&);
public:
    FunctionArrayManager(Function *, int);
    int executeFuncByName(const std::string&, int, int);
};

#include "../src/FunctionArrayManager.cpp"
#endif
