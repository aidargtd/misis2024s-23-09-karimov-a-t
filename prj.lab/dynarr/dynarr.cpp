#include "dynarr.hpp"

// Default Constructor
DynArr::DynArr() {
    size_ = 0;
    capacity_ = 0;
    data_ = nullptr;
}

// Copy Constructor
DynArr::DynArr(const DynArr& a) {
    size_ = a.size();
    capacity_ = size_;
    data_ = nullptr;
    if (size_ != 0)
        data_ = new float[size_];
    else
        data_ = nullptr;
    for (int i = 0; i < size_; ++i)
        data_[i] = a.data_[i];
}

// Constructor by size
DynArr::DynArr(const std::ptrdiff_t& size) {
    size_ = size;
    capacity_ = size;
    if (size != 0) {
        data_ = new float[size];
        for (int i = 0; i < size; i++) data_[i] = 0;
    } else
        data_ = nullptr;
}

// Function to get size value
std::ptrdiff_t DynArr::size() const noexcept {
    return size_;
}

// Function to resize dynarr
void DynArr::Resize(const std::ptrdiff_t size) {
    if (size > capacity_) {
        float* newData = new float[size];
        for (std::ptrdiff_t ind = 0; ind < capacity_; ind++) newData[ind] = data_[ind];
        delete[] data_;
        data_ = newData;
        capacity_ = size;
    }
    size_ = size;
}

// Operator to access elements by index
float& DynArr::operator[](std::ptrdiff_t idx) {
    return data_[idx];
}

// Destructor
DynArr::~DynArr() {
    delete[] data_;
}

// Overloading the << operator for printing DynArr objects
std::ostream& operator<<(std::ostream& ostr, DynArr a) {
    for (int i = 0; i < a.size(); ++i) {
        ostr << a[i] << ' ';
    }
    return ostr;
}
