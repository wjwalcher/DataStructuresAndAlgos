#ifndef SINGLYLINKED_H
#define SINGLYLINKED_H

class singlylinked {

    struct Node {
        int data;
        Node* next;
    };

    public:
        void insert(int pos, int data);
        void insertFront(int data);
        void insertBack(int data);
        void remove(int data);
        void removeFront();
        void removeBack();
    private:
        int length;
        Node* head;
        Node* tail;
};

#endif