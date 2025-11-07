#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>

namespace figures {

template<typename T>
class Array {
private:
    size_t capacity_;
    std::shared_ptr<T[]> data_;

public:
    Array();
    Array(const size_t& n, T value = T{});
    Array(const Array& other);
    Array(Array&& other) noexcept;
    ~Array() noexcept;

    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
    
    size_t capacity() const;
    size_t size() const;
    
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    
    void resize(size_t new_size);
    void clear();
};

}

#include "array.ipp"