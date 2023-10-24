#ifndef ZALICZENIE_NODE_H
#define ZALICZENIE_NODE_H

// Użycie template<typename T> umożliwia wykorzystanie listy do różnych typów danych
// Dzieje się tak ze względu na to, że w momencie kompilacji, T zostaje zastąpione przez typ danych nadany podczas inicjalizacji
// Np. dla DList<int>, kompilator zamieni wszystkie wystąpienia 'T' na 'int'

// Nagłówek z definicją klasy Node (ang. węzeł), która jest pojedynczą pozycją na liście
template<typename T>
class Node {
private:
    Node<T> * prev_pointer;
    Node<T> * next_pointer;
    T value;
public:
    Node<T>();
    Node<T>(T, Node<T> *, Node<T> *);
    Node<T>& operator=(const Node<T>&);

    Node<T> * next_node() const;
    Node<T> * prev_node() const;
    void setNextPtr(Node<T> *);
    void setPrevPtr(Node<T> *);
    T& GetValue();
};

#include "../src/Node.cpp"
#endif //ZALICZENIE_NODE_H
