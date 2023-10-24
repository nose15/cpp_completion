#ifndef ZALICZENIE_DLIST_H
#define ZALICZENIE_DLIST_H

#include <iostream>
#include "Node.h"

// Użycie template<typename T> umożliwia wykorzystanie listy do różnych typów danych
// Dzieje się tak ze względu na to, że w momencie kompilacji, T zostaje zastąpione przez typ danych nadany podczas inicjalizacji
// Np. dla DList<int>, kompilator zamieni wszystkie wystąpienia 'T' na 'int'

// Plik nagłówkowy zawierający definicję klasy DList zawierającej wskaźniki do pierwszego i ostatniego węzła oraz metody do
// manipulacji oraz nawigacji pomiędzy węzłami
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

#endif //ZALICZENIE_DLIST_H

