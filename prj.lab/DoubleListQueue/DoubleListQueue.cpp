#include <DoubleListQueue/DoubleListQueue.hpp>
#include <stdexcept>

Node::Node(int val) : value(val), next(nullptr), prev(nullptr) {}
DoubleListQueue::DoubleListQueue() : frontNode(nullptr), backNode(nullptr), size(0) {}

bool DoubleListQueue::empty() const {
    return size == 0;
}

size_t DoubleListQueue::getSize() const {
    return size;
}

int DoubleListQueue::getFront() {
    if (empty()) throw std::out_of_range("queue is empty!!!");
    return frontNode->value;
}

int DoubleListQueue::getBack() {
    if (empty()) throw std::out_of_range("queue is empty!!!");
    return backNode->value;
}


DoubleListQueue::~DoubleListQueue() {
    while (!empty()) {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
    }
}
int DoubleListQueue::top() {
    if (empty()) throw std::out_of_range("queue is empty!!!");
    int value = frontNode->value;
    Node* temp = frontNode;
    frontNode = frontNode->next;
    if (frontNode != nullptr) {
        frontNode->prev = nullptr;
    } else {
        backNode = nullptr;
    }
    delete temp;
    size--;
    return value;
}

void DoubleListQueue::push(int value) {
    Node* newNode = new Node(value);
    if (empty()) {
        frontNode = backNode = newNode;}
    else {
        backNode->next = newNode;
        newNode->prev = backNode;
        backNode = newNode;}
    size++;
}