/*
** Array based stack implementation
** O(n) push, pop, peek operations
** O(n) space complexity
*/

#include <iostream>
#include "stack.h"

Stack myStack;

// Constructs a new stack of given size
void Stack::new_Stack(int size) {
    myStack.stack = new int[size];
    myStack.MAX_ITEMS = size;
    myStack.current_items = 0;
    myStack.index = -1;
}

void Stack::push(int val) {
    myStack.index++;
    if (myStack.index > myStack.MAX_ITEMS) return;
    myStack.stack[myStack.index] = val;
    myStack.current_items++;
}

void Stack::pop() {
    if (myStack.current_items > 0) {
        myStack.index--;
    }
}

int Stack::peek() {
    if (myStack.current_items > 0) {
        return myStack.stack[myStack.index];
    }
}

Stack::~Stack() {
    delete [] myStack.stack;
}

int main(){
    myStack.new_Stack(10);
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);
    std::cout << myStack.peek() << std::endl;
    myStack.pop();
    std::cout << myStack.peek() << std::endl;
    myStack.pop();
    std::cout << myStack.peek() << std::endl;
    myStack.pop();
    std::cout << myStack.peek() << std::endl;
    myStack.pop();
    std::cout << myStack.peek() << std::endl;
    myStack.pop();
}

