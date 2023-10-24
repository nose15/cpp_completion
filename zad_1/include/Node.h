#ifndef ZALICZENIE_NODE_H
#define ZALICZENIE_NODE_H

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
