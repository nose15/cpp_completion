#ifndef DLIST_H
#define DLIST_H

#include <iostream>
#include "Node.h"

template<typename T>
class DList
{
private:
    Node<T> * startNode;
    Node<T> * endNode;
    size_t list_size{};
    Node<T> * GetElementByIndex(int);
    Node<T> * RemoveElement(Node<T> *);

public:
    DList(std::initializer_list<T>);
    T operator[](size_t) const;
    T& operator[](size_t);
    Node<T> * Append(T);
    Node<T> * RemoveByValue(T);
    Node<T> * RemoveByIndex(int);
    void Print() const;
    [[nodiscard]] size_t GetSize() const;
};

#include "../src/DList.cpp"
#endif 
