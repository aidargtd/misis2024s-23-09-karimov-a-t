#ifndef DOUBLELISTQUEUE_HPP
#define DOUBLELISTQUEUE_HPP

#include <cstddef>

class Node {
public:
    int value;
    Node *next;
    Node *prev;

    Node(int val);
};

class DoubleListQueue {
private:
    Node *frontNode;
    Node *backNode;
    size_t size;
public:
    DoubleListQueue();

    ~DoubleListQueue();

    int top();

    void push(int value);

    [[nodiscard]] bool empty() const;

    [[nodiscard]] size_t getSize() const;

    int getFront();

    int getBack();
};

#endif
