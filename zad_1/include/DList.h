#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include "Node.h"

template<typename T>
class DList
{
private:
    Node<T> startNode;
    Node<T> endNode;
    size_t size;

public:
    DList<T>(std::initializer_list<T>);
    T operator[](size_t) const;
    T& operator[](size_t);
    T* Append(T);
    T* Remove(T);
    size_t GetSize() const;
};


#endif //DLIST_H
