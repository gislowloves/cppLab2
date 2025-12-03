#ifndef STACK_H
#define STACK_H

#include "DynamicArray.h"
#include <cstdint>

template <typename T>
class Stack {
private:
    DynamicArray<T> data;
    std::int64_t mSize;
public:
    Stack(std::int64_t mSize);
    void push(T x);
    T top();
    T pop();
    bool isEmpty();
    void printStack();
    std::int64_t stSize();
    T someEshizuInStack(int64_t idx);
};

#endif
