/*
** Author: William Walcher
** Date: June 2018
** Implementation of a doubly linked list, using both head 
** and tail pointers, length tracking. 
** O(1) front and back insert/removal, 
** O(n) find and insert/remove at index. 
*/ 

#include "doublylinkedlist.h"

Node* head = NULL;
Node* tail = NULL;
int length = 0;

void insertFront(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        head->prev = NULL;
        tail->next = NULL;
        length++;
    } else {
        Node* temp = head;
        head->prev = newNode;
        head = newNode;
        head->next = temp;
        head->prev = NULL;
    }
}

void insertBack(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    if (tail == NULL) {
        tail = newNode;
        head = newNode;
        head->prev = NULL;
        tail->next = NULL;
        length++;
    }
}

void removeFront() {
    if (length == 1) {
        delete head;
        delete tail;
        length--;
        head = NULL;
        tail = NULL;
    } else {
        Node* temp = head;
        head = head->next; 
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
}

void removeBack() {
     if (length == 1) {
        delete head;
        delete tail;
        length--;
        head = NULL;
        tail = NULL;
    } else {
        Node* temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
}

