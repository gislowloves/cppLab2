#include <iostream>
#include <stdexcept>

#include "DynamicArray.h"

template <typename T>
DynamicArray<T>::DynamicArray(std::int64_t capacity) {
    if (capacity < 0) {
        throw std::invalid_argument("Capacity < 0");
    }
    this->capacity = capacity;
    data = new T[capacity]();
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] data;
}

template <typename T>
void DynamicArray<T>::push_front( T x) {
    if (size + 1 > capacity) {
        std::int64_t newCapacity = capacity * 2;
        T* tempArray = new T[newCapacity];
        for (int i = size; i > 0; --i) {
            tempArray[i] = data[i-1];
        }
        delete[] data;
        data = tempArray;
        capacity = newCapacity;
    } else {
        for (int i = size; i > 0; --i) {
            data[i] = data[i-1];
        }
    }
    data[0] = x;
    ++size;
}

template <typename T>
void DynamicArray<T>::push_back(T x) {
    if (size + 1 >= capacity) {
    std::int64_t newCapacity = capacity * 2;
    T* tempArray = new T[newCapacity];
    for (int i = 0; i < size; ++i) {
      tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
  }
  data[size] = x;
  ++size;
}

template <typename T>
T DynamicArray<T>::front()  {
    if (isEmpty()) {
        throw std::invalid_argument("Empty array");
    }
    return data[0];
}

template <typename T>
T DynamicArray<T>::back()  {
    if (isEmpty()) {
        throw std::invalid_argument("Empty array");
    }
    return data[size - 1];
}

template <typename T>
void DynamicArray<T>::insert(std::int64_t idx,  T x) {
    if (idx < 0 || idx > size) {
        throw std::out_of_range("Index out of bounds");
    }

    if (size + 1 > capacity) {
        std::int64_t newCapacity = capacity * 2;
        T* tempArray = new T[newCapacity];
        for (int i = 0; i < idx; ++i) {
            tempArray[i] = data[i];
        }
        for (int i = size; i > idx; --i) {
            tempArray[i] = data[i-1];
        }
        delete[] data;
        data = tempArray;
        capacity = newCapacity;
    } else {
        for (int i = size; i > idx; --i) {
            data[i] = data[i-1];
        }
    }
    data[idx] = x;
    ++size;
}

template <typename T>
void DynamicArray<T>::erase(std::int64_t idx) {
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of range");
    }
    for (int i = idx; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

template <typename T>
void DynamicArray<T>::erase_after(std::int64_t idx) {
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index out of range");
    }
    size = idx + 1;
}

template <typename T>
void DynamicArray<T>::increase_capacity(std::int64_t newCapacity) {
    if (newCapacity < capacity) {
        std::cout << "You are a little silly" << std::endl;
    }
    T* tempArray = new T[newCapacity];
    for (int i = 0; i < size; ++i){
         tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
}

template <typename T>
void DynamicArray<T>::decrease_capacity(std::int64_t newCapacity) {
    if (newCapacity > capacity) {
        std::cout << "You are a little silly" << std::endl;
    }
    if (newCapacity < size) size = newCapacity;
    T* tempArray = new T[newCapacity];
    for (int i = 0; i < size; ++i) {
        tempArray[i] = data[i];
    }
    delete[] data;
    data = tempArray;
    capacity = newCapacity;
}

template <typename T>
void DynamicArray<T>::printData()  {
    if (isEmpty()) return;
    for (int i = 0; i < size; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
std::int64_t DynamicArray<T>::get_size(){
    return size;
}
