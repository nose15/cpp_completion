#include "../include/DList.h"

template<typename T>
DList<T>::DList(std::initializer_list<T> initializerList)
{
    size_t initListSize = initializerList.size();

    this->startNode = Node<T>(initializerList.begin(), nullptr, nullptr);

    Node<T> * prev_pointer = &startNode;
    for (int i = 1; i < initListSize - 2; i++)
    {
        Node<T>* node = new Node<T>(initializerList[i], prev_pointer, nullptr);
        prev_pointer->setNextPtr(node);
        prev_pointer = node;
    }
    this->endNode = Node<T>(initializerList.end(), prev_pointer, nullptr);

    this->size = (this->endNode - this->startNode) / sizeof(T);

    std::cout << size;
}

template<typename T>
T DList<T>::operator[](size_t index) const
{
    std::cout << "aaa" << std::endl;
}

template<typename T>
T& DList<T>::operator[](size_t index)
{
    std::cout << "aaa" << std::endl;
}

template<typename T>
T* Append(T item)
{
    std::cout << "aaa" << std::endl;
}

template<typename T>
T* Remove(T item)
{
    std::cout << "aaa" << std::endl;
}

template<typename T>
size_t DList<T>::GetSize() const
{
    std::cout << "aaa" << std::endl;
}




