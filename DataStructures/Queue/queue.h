#ifndef QUEUE_H
#define QUEUE_H

class Queue {
    struct queue {
        int* queue;
        int MAX_SIZE;
        int current_size;
        int front;
        int back;
    };

    public:
        struct queue myQueue;
        void new_Queue(int size);
        ~Queue();
        void enqueue(int data);
        void dequeue();
        int peek();
        bool isEmpty();

};

#endif