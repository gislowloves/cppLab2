#include "stack.h"
#include "stack.cc"
#include "DynamicArray.cc"
#include "DynamicArray.h"
#include "queue.h"
#include "queue.cc"
#include <iostream>

int main(){
    Stack<int> stik(5);
    stik.push(1);
    stik.push(2);
    stik.printStack();

    std::cout<<stik.top()<<std::endl;
    std::cout<<stik.stSize()<<std::endl;

    Queue<int> que(5);
    que.enqueue(4);
    que.enqueue(8);
    que.enqueue(8);
    std::cout<<que.dequeue()<<std::endl;
    std::cout<<que.isEmpty()<<std::endl;
    std::cout<<que.size()<<std::endl;

    return 0;
}
