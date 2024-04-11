#include <initializer_list>
#include <stdexcept>
#include <algorithm>

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
        other.size_ = 0;
        other.i_top_ = -1;
        other.data_ = nullptr;
    }

    StackArrT(const std::initializer_list<T>& list) : size_(list.size()), i_top_(list.size() - 1), data_(new T[list.size()]) {
        std::copy(list.begin(), list.end(), data_);
    }

    void push(const T& value) {
        if (i_top_ + 1 >= size_) this->resize(size_ * 2 + 1);
        data_[++i_top_] = value;
    }

    void pop() {
        if (this->empty()) throw std::underflow_error("Stack is empty");
        --i_top_;
    }

    T& top() const {
        if (this->empty()) throw std::underflow_error("Stack is empty");
        return data_[i_top_];
    }

    void swap(StackArrT<T>& other) {
        std::swap(size_, other.size_);
        std::swap(i_top_, other.i_top_);
        std::swap(data_, other.data_);
    }

    void merge(StackArrT<T>& other) {
        if (other.empty()) return;
        std::ptrdiff_t newSize = size_ + other.size_;
        T* newData = new T[newSize];
        std::copy(data_, data_ + size_, newData);
        std::copy(other.data_, other.data_ + other.size_, newData + size_);
        delete[] data_;
        data_ = newData;
        size_ = newSize;
        i_top_ = size_ - 1;
        other.size_ = 0; // Устанавливаем размер other в 0, чтобы он стал пустым
        other.i_top_ = -1; // Устанавливаем i_top_ other в -1, чтобы он стал пустым
    }

    [[nodiscard]] bool empty() const {
        return size_ == 0; // Если размер стека равен 0, значит, он пуст
    }

    [[nodiscard]] std::ptrdiff_t size() const {
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
            T* newData = new T[rhs.size_];
            std::copy(rhs.data_, rhs.data_ + rhs.size_, newData);
            delete[] data_;
            data_ = newData;
            size_ = rhs.size_;
            i_top_ = rhs.i_top_;
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
    std::ptrdiff_t size_;   //!< общий размер выделенного массива
    std::ptrdiff_t i_top_; //!< индекс верхнего элемента
    T* data_;   //!< элементы стека

    void resize(std::ptrdiff_t newSize) {
        if (newSize <= size_) return;
        T* newData = new T[newSize];
        std::copy(data_, data_ + size_, newData);
        delete[] data_;
        data_ = newData;
        size_ = newSize;
    }
};
