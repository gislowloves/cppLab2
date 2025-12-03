#include "queue.h"
#include <stdexcept>
#include <iostream>

template <typename T>
Queue<T>::Queue(std::int64_t capacity)
    : stik1(capacity), stik2(capacity) {}

template <typename T>
void Queue<T>::transfer(){
    while(!stik1.isEmpty()){
        stik2.push(stik1.pop());
    }
}

template <typename T>
void Queue<T>::enqueue(T x){
    stik1.push(x);
}

template <typename T>
T Queue<T>::dequeue(){
    if(stik2.isEmpty()){
        if(stik1.isEmpty()){
            throw std::out_of_range("No hedgehogs in the queue((");
        }
    }
    transfer();
    return stik2.pop();
}

template <typename T>
bool Queue<T>::isEmpty(){
    return (stik1.stSize()+stik2.stSize()==0);
}

template <typename T>
std::int64_t Queue<T>::size(){
    return stik1.stSize()+stik2.stSize();
}

template <typename T>
void Queue<T>::printQueue(){
    if(!stik2.isEmpty()){
        for(int i = stik2.stSize()-1; i >= 0; i--){
            std::cout<< stik2.someEshizuInStack(i)<<" ";
        }
    }
    if(!stik1.isEmpty()){
        for(int i = 0; i < stik1.stSize(); i++){
            std::cout<< stik1.someEshizuInStack(i)<<" ";
        }
    }
    std::cout<<std::endl;
}
