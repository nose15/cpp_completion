#include "../include/DList.h"

template<typename T>
DList<T>::DList(std::initializer_list<T> initializerList)
{
    bool firstSet = false;
    Node<T> * prev_pointer = nullptr;

    this->list_size = initializerList.size();

    for (const T& value : initializerList)
    {
        auto* node = new Node<T>(value, prev_pointer, nullptr);

        if (firstSet)
        {
            prev_pointer->setNextPtr(node);
        }
        else
        {
            this->startNode = node;
            firstSet = true;
        }

        prev_pointer = node;
        this->endNode = node;
    }
}


template<typename T>
T DList<T>::operator[](size_t index) const
{
    Node<T> * result = startNode;
    if (index == 0) return result->GetValue();

    for (int i = 1; i <= index; i++)
    {
        result = result->next_node();
    }

    return result->GetValue();
}

template<typename T>
T& DList<T>::operator[](size_t index)
{
    Node<T> * result = startNode;
    if (index == 0) return result->GetValue();

    for (int i = 1; i <= index; i++)
    {
        result = result->next_node();
    }

    return result->GetValue();
}

template<typename T>
Node<T> * DList<T>::Append(T val)
{
    auto * newNode = new Node<T>(val, endNode, nullptr);
    endNode->setNextPtr(newNode);
    endNode = newNode;
    return endNode;
}

template<typename T>
Node<T> * DList<T>::Remove(T val)
{
    Node<T> * current_node = startNode;

    if (current_node->GetValue() == val)
    {
        Node<T> * next = current_node->next_node();
        next->setPrevPtr(nullptr);
        startNode = next;
        return next;
    }

    while (current_node != endNode)
    {
        if (current_node->GetValue() == val)
        {
            Node<T> * prev = current_node->prev_node();
            Node<T> * next = current_node->next_node();

            next->setPrevPtr(prev);
            prev->setNextPtr(next);

            current_node->setPrevPtr(nullptr);
            current_node->setNextPtr(nullptr);

            return next;
        }
        current_node = current_node->next_node();
    }

    if (endNode->GetValue() == val)
    {
        Node<T> * prev = current_node->prev_node();
        prev->setNextPtr(nullptr);
        endNode = prev;
        return prev;
    }

    return nullptr;
}

template<typename T>
size_t DList<T>::GetSize() const
{
    return this->list_size;
}

template<typename T>
void DList<T>::Print() const
{
    Node<T> * current_node = startNode;
    std::cout << "[";
    while (true)
    {
        std::cout << current_node->GetValue();
        current_node = current_node->next_node();

        if (current_node != nullptr)
        {
            std::cout << ", ";
            continue;
        }
        break;
    }
    std::cout << "]" << std::endl;
}
