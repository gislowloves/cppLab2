#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"
#include <cstdint>

template <typename T>
class Queue {
private:
    Stack<T> stik1;
    Stack<T> stik2;
    void transfer();
public:
    Queue(std::int64_t capacity);
    void enqueue(T x);
    T dequeue();
    bool isEmpty();
    std::int64_t size();
    void printQueue();
};

#endif
