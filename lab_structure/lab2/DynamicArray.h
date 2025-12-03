#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <cstdint>

template <typename T>
class DynamicArray {
private:
    T* data;
    std::int64_t size = 0;
    std::int64_t capacity;

    bool isEmpty() {
        return size == 0;
    }

public:
    DynamicArray(std::int64_t capacity);
    ~DynamicArray();

    void push_back(T x);
    void push_front(T x);
    T front();
    T back();
    void insert(std::int64_t idx, T x);
    void erase(std::int64_t idx);
    void erase_after(std::int64_t idx);
    void increase_capacity(std::int64_t newCapacity);
    void decrease_capacity(std::int64_t newCapacity);
    void printData();
    std::int64_t get_size();

};

#endif
