#include <stdexcept>

#include "stack.h"

template <typename T>
Stack<T>::Stack(std::int64_t mSize)
    : data(mSize), mSize(mSize) {}

template <typename T>
void Stack<T>::push(T x){
    if(data.get_size()>=mSize){
        throw std::overflow_error("Too many hedgehogs!!");
    }
    data.push_back(x);

}

template <typename T>
T Stack<T>::top(){
    if (isEmpty()) {
        throw std::invalid_argument("You went out of hedgehog's valley((");
    }
    return data.back();
}

template <typename T>
T Stack<T>::pop(){
    if (isEmpty()) {
        throw std::invalid_argument("You went out of hedgehog's valley((");
    }
    T value = data.back();
    data.erase(data.get_size()-1);
    return value;
}

template <typename T>
bool Stack<T>::isEmpty(){
    return data.get_size()==0;
}

template <typename T>
void Stack<T>::printStack(){
    return data.printData();
}

template <typename T>
std::int64_t Stack<T>::stSize(){
    return data.get_size();
}

template <typename T>
T Stack<T>::someEshizuInStack(int64_t idx){
    return data.someEshizu(idx);
}
