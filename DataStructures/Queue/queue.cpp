/*
** Simple array-based queue implementation
** O(1) enqueue and dequeue, peek
** O(n) space complexity
*/

#include "queue.h"
#include <iostream>

Queue myQueue;

void Queue::new_Queue(int size) {
    myQueue.queue = new int[size];
    myQueue.MAX_SIZE = size;
    myQueue.current_size = 0;
    myQueue.front = -1;
    myQueue.back = -1;
}

bool Queue::isEmpty() {
    return (myQueue.front == -1 && myQueue.back == -1);
}

Queue::~Queue() {
    delete myQueue.queue;
}

void Queue::enqueue(int data) {
    if (myQueue.back == -1) {
        myQueue.back = 0;
        myQueue.front = 0;
    } else {
        myQueue.back = (myQueue.back + 1) % myQueue.MAX_SIZE; // Circular 
    }
    myQueue.queue[myQueue.back] = data;
    myQueue.current_size++;
}

void Queue::dequeue() {
    if (!isEmpty()) {
        myQueue.front++;
        myQueue.current_size--;
    }
}

int Queue::peek() {
    return myQueue.queue[myQueue.front];
}

int main() {
    myQueue.new_Queue(10);
    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.enqueue(5);
    std::cout << myQueue.peek() << std::endl;
    myQueue.dequeue();
    std::cout << myQueue.peek() << std::endl;
    myQueue.dequeue();
    std::cout << myQueue.peek() << std::endl;
    myQueue.dequeue();
    std::cout << myQueue.peek() << std::endl;
    myQueue.dequeue();
    std::cout << myQueue.peek() << std::endl;
    myQueue.dequeue();
}