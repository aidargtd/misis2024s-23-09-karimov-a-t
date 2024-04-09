#ifndef STACKARR_HPP
#define STACKARR_HPP

#include <algorithm> // for std::swap
#include <stdexcept> // for std::out_of_range

template <typename T>
class StackArrT {
public:
    StackArrT() : size_(0), i_top_(-1), data_(nullptr) {}

    ~StackArrT() {
        delete[] data_;
    }

    StackArrT(const StackArrT<T>& other) : size_(other.size_), i_top_(other.i_top_), data_(new T[other.size_]) {
        std::copy(other.data_, other.data_ + other.size_, data_);
    }

    StackArrT(StackArrT<T>&& other) noexcept : size_(other.size_), i_top_(other.i_top_), data_(other.data_) {
        other.data_ = nullptr;
        other.size_ = 0;
        other.i_top_ = -1;
    }

    void push(const T& value) {
        if (i_top_ + 1 == size_) {
            // Need to expand the array
            size_ = size_ == 0 ? 1 : size_ * 2;
            T* newData = new T[size_];
            std::copy(data_, data_ + i_top_ + 1, newData);
            delete[] data_;
            data_ = newData;
        }
        data_[++i_top_] = value;
    }

    void pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        --i_top_;
    }

    T& top() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return data_[i_top_];
    }

    void swap(StackArrT<T>& other) {
        std::swap(size_, other.size_);
        std::swap(i_top_, other.i_top_);
        std::swap(data_, other.data_);
    }

    void merge(StackArrT<T>& other) {
        while (!other.empty()) {
            this->push(other.top());
            other.pop();
        }
    }

    bool empty() const {
        return i_top_ == -1;
    }

    std::ptrdiff_t size() const {
        return i_top_ + 1;
    }

    bool operator==(const StackArrT<T>& rhs) const {
        if (size() != rhs.size()) return false;
        for (std::ptrdiff_t i = 0; i <= i_top_; ++i) {
            if (data_[i] != rhs.data_[i]) return false;
        }
        return true;
    }

    bool operator!=(const StackArrT<T>& rhs) const {
        return !(*this == rhs);
    }

    StackArrT<T>& operator=(const StackArrT<T>& rhs) noexcept {
        if (this != &rhs) {
            StackArrT<T> temp(rhs);
            swap(temp);
        }
        return *this;
    }

    StackArrT<T>& operator=(StackArrT<T>&& other) noexcept {
        if (this != &other) {
            delete[] data_;
            data_ = other.data_;
            size_ = other.size_;
            i_top_ = other.i_top_;

            other.data_ = nullptr;
            other.size_ = 0;
            other.i_top_ = -1;
        }
        return *this;
    }

private:
    std::ptrdiff_t size_;
    std::ptrdiff_t i_top_;
    T* data_;
};
