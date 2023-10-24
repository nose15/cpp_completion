#include "../include/Node.h"
#include <string>

// Plik źródłowy zawierający implementację klasy Node, której przeznaczenie jest opisane w jej pliku nagłówkowym Node.h
template<typename T>
Node<T>::Node() = default;

template<typename T>
Node<T>::Node(T value, Node<T> * prev_ptr, Node<T> * next_ptr) : value(value), next_pointer(next_ptr), prev_pointer(prev_ptr) {}

// nadpisanie operatora =, pozwala ono na przypisanie jednego węzła do drugiego
template<typename T>
Node<T> &Node<T>::operator=(const Node<T> & other) {
    if (this != &other) {
        this->value = other.value;
        this->prev_pointer = other.prev_pointer;
        this->next_pointer = other.next_pointer;
    }
    return *this;
}

// funkcja do ustawienia wskaźnika do następnego elementu listy, przydatna podczas inicjalizacji listy w klasie DList
template<typename T>
void Node<T>::setNextPtr(Node<T> * nextPtr)
{
    this->next_pointer = nextPtr;
}

// funkcja do ustawienia wskaźnika do poprzedniego elementu listy
template<typename T>
void Node<T>::setPrevPtr(Node<T> * prevPtr)
{
    this->prev_pointer = prevPtr;
}

// funckja zwracająca wartość zapisaną w węźle
template<typename T>
T& Node<T>::GetValue()
{
    return value;
}

// funkcja zwracająca wskaźnik do następnego węzła
template<typename T>
Node<T> * Node<T>::next_node() const
{
    Node<T> * ptr = this->next_pointer;
    return ptr;
}

// funkcja zwracająca wskaźnik do poprzedniego węzła
template<typename T>
Node<T> * Node<T>::prev_node() const
{
    Node<T> * ptr = this->prev_pointer;
    return ptr;
}