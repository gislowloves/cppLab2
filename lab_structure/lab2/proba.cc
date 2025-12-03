#include "stack.h"
#include "stack.cc"
#include "DynamicArray.cc"
#include "DynamicArray.h"
#include "queue.h"
#include "queue.cc"
#include <iostream>
#include <string>

int main(){
    Stack<std::string> stik(5);
    stik.push("m");
    stik.push("p");
    stik.printStack();

    std::cout<<stik.top()<<std::endl;
    std::cout<<stik.stSize()<<std::endl;

    Queue<int> que(5);
    que.enqueue(4);
    que.enqueue(8);
    que.printQueue();
    que.enqueue(9);
    que.dequeue();
    que.printQueue();
    std::cout<<que.isEmpty()<<std::endl;
    std::cout<<que.size()<<std::endl;

    return 0;
}
