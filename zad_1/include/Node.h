#ifndef NODE_H
#define NODE_H


template<typename T>
class Node {
private:
    void * prev_pointer;
    void * next_pointer;
    T value;
public:
    Node<T>(T, void *, void *);
    ~Node<T>();
    void * next() const;
    void * prev() const;
    void setNextPtr(void *);
    void setPrevPtr(void *);
};


#endif //NODE_H
