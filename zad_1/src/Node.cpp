#include "../include/Node.h"
#include <string>


template<typename T>
Node<T>::Node()
{
    std::cout << "default_used" << std::endl;
}

template<typename T>
Node<T>::Node(T value, Node<T> * prev_ptr, Node<T> * next_ptr) : value(value), next_pointer(next_ptr), prev_pointer(prev_ptr) {}


template<typename T>
void Node<T>::setNextPtr(Node<T> * nextPtr)
{
    this->next_pointer = nextPtr;
}

template<typename T>
void Node<T>::setPrevPtr(Node<T> * prevPtr)
{
    this->prev_pointer = prevPtr;
}

template<typename T>
T& Node<T>::GetValue()
{
    return value;
}

template<typename T>
Node<T> * Node<T>::next_node() const
{
    Node<T> * ptr = this->next_pointer;
    return ptr;
}

template<typename T>
Node<T> * Node<T>::prev_node() const
{
    Node<T> * ptr = this->prev_pointer;
    return ptr;
}