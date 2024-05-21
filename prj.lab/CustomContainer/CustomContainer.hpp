#include "IContainerBase.hpp"
#include <iostream>

class CustomContainer : public IContainerBase {
public:
    struct Node {
        int* data;
        size_t size;
        Node* next;
        Node* prev;

        Node(size_t capacity) : data(new int[capacity]), size(0), next(nullptr), prev(nullptr) {}
        ~Node() { delete[] data; }
    };

    CustomContainer(size_t capacity) : head(nullptr), tail(nullptr), nodeCapacity(capacity) {}

    ~CustomContainer() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(int value) override {
        if (!tail || tail->size == nodeCapacity) {
            Node* newNode = new Node(nodeCapacity);
            if (tail) {
                tail->next = newNode;
                newNode->prev = tail;
            }
            tail = newNode;
            if (!head) {
                head = tail;
            }
        }
        tail->data[tail->size++] = value;
    }

    bool remove(int value) override {
        Node* current = head;
        while (current != nullptr) {
            for (size_t i = 0; i < current->size; ++i) {
                if (current->data[i] == value) {
                    for (size_t j = i; j < current->size - 1; ++j) {
                        current->data[j] = current->data[j + 1];
                    }
                    current->size--;
                    if (current->size == 0) {
                        if (current->prev) {
                            current->prev->next = current->next;
                        }
                        if (current->next) {
                            current->next->prev = current->prev;
                        }
                        if (current == head) {
                            head = current->next;
                        }
                        if (current == tail) {
                            tail = current->prev;
                        }
                        delete current;
                    }
                    return true;
                }
            }
            current = current->next;
        }
        return false;
    }

    bool contains(int value) const override {
        Node* current = head;
        while (current != nullptr) {
            for (size_t i = 0; i < current->size; ++i) {
                if (current->data[i] == value) {
                    return true;
                }
            }
            current = current->next;
        }
        return false;
    }

    void insert(size_t index, int value) {
        if (index < 0)
            return;

        size_t currentIdx = 0;
        Node  *current = head;
        while (current != nullptr) {
            if (index < currentIdx + current->size) {
                for (size_t i = current->size; i > index - currentIdx; --i) {
                    current->data[i] = current->data[i - 1];
                }
                current->data[index - currentIdx] = value;
                current->size++;
                return;
            }
            currentIdx += current->size;
            current = current->next;
        }
        add(value);
    }


    // перегрузка операторов
    CustomContainer& operator+=(int value) {
        add(value);
        return *this;
    }

    CustomContainer& operator-=(int value) {
        remove(value);
        return *this;
    }

    bool operator==(const CustomContainer& other) const {
        Node* thisCurrent = this->head;
        Node* otherCurrent = other.head;

        while (thisCurrent != nullptr && otherCurrent != nullptr) {
            if (thisCurrent->size != otherCurrent->size) {
                return false;
            }
            for (size_t i = 0; i < thisCurrent->size; ++i) {
                if (thisCurrent->data[i] != otherCurrent->data[i]) {
                    return false;
                }
            }
            thisCurrent = thisCurrent->next;
            otherCurrent = otherCurrent->next;
        }
        return thisCurrent == nullptr && otherCurrent == nullptr;
    }

    friend std::ostream& operator<<(std::ostream& os, const CustomContainer& container) {
        Node* current = container.head;
        while (current != nullptr) {
            for (size_t i = 0; i < current->size; ++i) {
                os << current->data[i] << " ";
            }
            current = current->next;
        }
        return os;
    }

private:
    Node* head;
    Node* tail;
    size_t nodeCapacity;
};