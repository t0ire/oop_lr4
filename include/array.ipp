namespace figures {

template<typename T>
Array<T>::Array() : capacity_(0), data_(nullptr) {}

template<typename T>
Array<T>::Array(const size_t& n, T value) : capacity_(n), data_(new T[n]) {
    for (size_t i = 0; i < capacity_; ++i) {
        data_[i] = value;
    }
}

template<typename T>
Array<T>::Array(const Array& other) : capacity_(other.capacity_), data_(new T[other.capacity_]) {
    for (size_t i = 0; i < capacity_; ++i) {
        data_[i] = other.data_[i];
    }
}

template<typename T>
Array<T>::Array(Array&& other) noexcept : capacity_(other.capacity_), data_(other.data_) {
    other.data_ = nullptr;
    other.capacity_ = 0;
}

template<typename T>
Array<T>::~Array() noexcept {
    delete[] data_;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] data_;
        
        capacity_ = other.capacity_;
        data_ = new T[capacity_];
        for (size_t i = 0; i < capacity_; ++i) {
            data_[i] = other.data_[i];
        }
    }
    return *this;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] data_;
        
        capacity_ = other.capacity_;
        data_ = other.data_;
        other.data_ = nullptr;
        other.capacity_ = 0;
    }
    return *this;
}

template<typename T>
size_t Array<T>::capacity() const { return capacity_; }

template<typename T>
size_t Array<T>::size() const { return capacity_; }

template<typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= capacity_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template<typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= capacity_) {
        throw std::out_of_range("Index out of range");
    }
    return data_[index];
}

template<typename T>
void Array<T>::resize(size_t new_size) {
    if (new_size == capacity_) return;
    
    T* new_data = new T[new_size];
    size_t copy_size = std::min(capacity_, new_size);
    
    for (size_t i = 0; i < copy_size; ++i) {
        new_data[i] = data_[i];  
    }
    
    for (size_t i = copy_size; i < new_size; ++i) {
        new_data[i] = T{};  
    }
    
    delete[] data_;
    data_ = new_data;
    capacity_ = new_size;
}

template<typename T>
void Array<T>::clear() {
    delete[] data_;
    data_ = nullptr;
    capacity_ = 0;
}

}