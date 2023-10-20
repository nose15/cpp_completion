#ifndef NODE_H
#define NODE_H


template<typename T>
class Node {
private:
    Node<T> * prev_pointer;
    Node<T> * next_pointer;
    T value;
public:
    Node<T>();
    Node<T>(T, Node<T> *, Node<T> *);
    Node<T>& operator=(const Node<T>& other) {
        if (this != &other) {
            this->value = other.value;
            this->prev_pointer = other.prev_pointer;
            this->next_pointer = other.next_pointer;
        }
        return *this;
    }

//    ~Node<T>();
    Node<T> * next_node() const;
    Node<T> * prev_node() const;
    void setNextPtr(Node<T> *);
    void setPrevPtr(Node<T> *);
    T& GetValue();
};

#include "../src/Node.cpp"
#endif //NODE_H
