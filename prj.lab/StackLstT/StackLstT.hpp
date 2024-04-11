//
// Created by karim on 11.04.2024.
//

#ifndef MISIS2024S_23_09_KARIMOV_A_T_STACKLSTT_H
#define MISIS2024S_23_09_KARIMOV_A_T_STACKLSTT_H


#include <initializer_list>
#include <stdexcept>

template <typename T>
class StackLstT {
public:
    StackLstT() = default;
    ~StackLstT() {
        while (!empty()) {
            pop();
        }
    }
    StackLstT(const StackLstT<T>& other) {
        if (!other.empty()) {
            Node* other_curr = other.head_;
            Node* this_curr = new Node{other_curr->value};
            head_ = this_curr;

            while (other_curr->next != nullptr) {
                other_curr = other_curr->next;
                this_curr->next = new Node{other_curr->value};
                this_curr = this_curr->next;
            }
        }
    }
    StackLstT(StackLstT<T>&& other) noexcept : head_(other.head_) {
        other.head_ = nullptr;
    }
    StackLstT(const std::initializer_list<T>& list) {
        for (const auto& elem : list) {
            push(elem);
        }
    }

    void push(const T& value) {
        Node* new_node = new Node{value};
        new_node->next = head_;
        head_ = new_node;
    }
    void pop() {
        if (empty()) {
            throw std::out_of_range("pop() called on empty stack");
        }
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
    }
    T& top() const {
        if (empty()) {
            throw std::out_of_range("top() called on empty stack");
        }
        return head_->value;
    }
    void swap(StackLstT<T>& other) {
        std::swap(head_, other.head_);
    }
    void merge(StackLstT<T>& other) {
        if (this == &other) {
            return;
        }
        if (other.empty()) {
            return;
        }
        Node* other_tail = other.head_;
        while (other_tail->next != nullptr) {
            other_tail = other_tail->next;
        }
        other_tail->next = head_;
        head_ = other.head_;
        other.head_ = nullptr;
    }

    bool empty() const {
        return head_ == nullptr;
    }
    std::ptrdiff_t size() const {
        std::ptrdiff_t count = 0;
        Node* curr = head_;
        while (curr != nullptr) {
            ++count;
            curr = curr->next;
        }
        return count;
    }

    bool operator==(const StackLstT<T>& rhs) const {
        if (size() != rhs.size()) {
            return false;
        }
        Node* this_curr = head_;
        Node* rhs_curr = rhs.head_;
        while (this_curr != nullptr) {
            if (this_curr->value != rhs_curr->value) {
                return false;
            }
            this_curr = this_curr->next;
            rhs_curr = rhs_curr->next;
        }
        return true;
    }
    bool operator!=(const StackLstT<T>& rhs) const {
        return !(*this == rhs);
    }

    StackLstT<T>& operator=(const StackLstT<T>& rhs) noexcept {
        if (this != &rhs) {
            StackLstT<T> temp(rhs);
            swap(temp);
        }
        return *this;
    }
    StackLstT<T>& operator=(StackLstT<T>&& other) {
        if (this != &other) {
            clear();
            head_ = other.head_;
            other.head_ = nullptr;
        }
        return *this;
    }

private:
    struct Node {
        T value;
        Node* next = nullptr;
    };

    void clear() {
        while (!empty()) {
            pop();
        }
    }

    Node* head_ = nullptr;
};


#endif //MISIS2024S_23_09_KARIMOV_A_T_STACKLSTT_H
