/*
** Array based implementation of a stack 
*/
#ifndef STACK_H
#define STACK_H

class Stack {
    struct stack {
        int* stack;
        int MAX_ITEMS;
        int current_items;
        int index;
    };
        
    public:
        struct stack myStack;
        ~Stack();
        void push(int val);
        void pop();
        int peek();
        void new_Stack(int size); // Initializes a stack of size n, returning a pointer to the bottom 
};

#endif