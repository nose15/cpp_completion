#include "../include/Node.h"

template<typename T>
Node<T>::Node(T value, void * prev, void * next) : value(value), prev_pointer(prev), next_pointer(next) {}

template<typename T>
Node<T>::~Node<T>()
{
    delete value;
}

template<typename T>
void *Node<T>::next() const
{
    return this->next_pointer;
}

template<typename T>
void *Node<T>::prev() const
{
    return this->prev_pointer;
}

template<typename T>
void Node<T>::setNextPtr(void * nextPtr)
{
    this->next_pointer = nextPtr;
}

template<typename T>
void Node<T>::setPrevPtr(void * prevPtr)
{
    this->prev_pointer = prevPtr;
}
