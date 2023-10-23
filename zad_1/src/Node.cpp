#include "../include/Node.h"
#include <string>

template<typename T>
Node<T>::Node() = default;

template<typename T>
Node<T>::Node(T value, Node<T> * prev_ptr, Node<T> * next_ptr) : value(value), next_pointer(next_ptr), prev_pointer(prev_ptr) {}

template<typename T>
Node<T> &Node<T>::operator=(const Node<T> & other) {
    if (this != &other) {
        this->value = other.value;
        this->prev_pointer = other.prev_pointer;
        this->next_pointer = other.next_pointer;
    }
    return *this;
}

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