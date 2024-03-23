#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <cstddef>
#include <iostream>

class DynArr {
public:
    // Default Constructor
    DynArr();

    // Copy Constructor
    DynArr(const DynArr& a);

    // Constructor by size
    DynArr(const std::ptrdiff_t& size);

    // Function to get size value
    [[nodiscard]] std::ptrdiff_t size() const noexcept;

    // Function to resize dynarr
    void Resize(const std::ptrdiff_t size);

    // Operator to access elements by index
    float& operator[](std::ptrdiff_t idx);

    // Destructor
    ~DynArr();

private:
    std::ptrdiff_t size_ = 0;
    std::ptrdiff_t capacity_ = 0;
    float* data_ = nullptr;
};

// Overloading the << operator for printing DynArr objects
std::ostream& operator<<(std::ostream& ostr, DynArr a);

#endif // DYNARR_HPP
