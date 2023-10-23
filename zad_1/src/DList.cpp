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
    Node<T> * result = GetElementByIndex(index);
    return result->GetValue();
}

template<typename T>
T& DList<T>::operator[](size_t index)
{
    Node<T> * result = GetElementByIndex(index);
    return result->GetValue();
}


template<typename T>
Node<T> * DList<T>::Append(T val)
{
    auto * newNode = new Node<T>(val, endNode, nullptr);
    endNode->setNextPtr(newNode);
    endNode = newNode;
    list_size++;
    
    return endNode;
}

template<typename T>
Node<T> * DList<T>::RemoveByValue(T val)
{
    Node<T> * current_node = startNode;

    while (current_node != endNode)
    {
        if (current_node->GetValue() == val)
        {
            return RemoveElement(current_node);
        }
        current_node = current_node->next_node();
    }

    return nullptr;
}

template<typename T>
Node<T> * DList<T>::RemoveByIndex(int index)
{
    Node<T> * currentNode = GetElementByIndex(index);
    Node<T> * node = RemoveElement(currentNode);

    return node;
}

template<typename T>
size_t DList<T>::GetSize() const
{
    this->list_size;
}

template<typename T>
Node<T> * DList<T>::GetElementByIndex(int index)
{
    if (index == 0) return startNode;
    if (index == list_size - 1) return endNode;
    if (index < 0 || index > (list_size - 1)) return nullptr;

    Node<T> * currentNode;

    if (index > (list_size - 1) - index)
    {
        currentNode = endNode;
        for (int i = list_size - 1; i > index; --i)
        {
            currentNode = currentNode->prev_node();
        }
        return currentNode;
    }

    currentNode = startNode;

    for (int i = 0; i < index; ++i)
    {
        currentNode = currentNode->next_node();
    }
    return currentNode;
}

template<typename T>
Node<T> * DList<T>::RemoveElement(Node<T> * node)
{
    if (node == startNode)
    {
        Node<T> * nextNode = startNode->next_node();
        nextNode->setPrevPtr(nullptr);
        startNode = nextNode;

        list_size--;
        delete node;
        return startNode;
    }
    else if (node == endNode)
    {
        Node<T> * prevNode = endNode->prev_node();
        prevNode->setNextPtr(nullptr);
        endNode = prevNode;

        list_size--;
        delete node;
        return endNode;
    }

    Node<T> * prevNode = node->prev_node();
    Node<T> * nextNode = node->next_node();

    prevNode->setNextPtr(nextNode);
    nextNode->setPrevPtr(prevNode);

    node->setPrevPtr(nullptr);
    node->setNextPtr(nullptr);

    list_size--;
    delete node;
    return nextNode;
}

template<typename T>
void DList<T>::Print() const
{
    Node<T> * current_node = startNode;
    std::cout << "[";
    while (true) {
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
