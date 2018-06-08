#include "singlylinked.h"
#include <iostream>

head = NULL;
tail = NULL;
length = 0;

void insert(Node* node, int pos, int data) {
    if (length == 0) {
        Node newNode = new Node
        head = 
    } else {
        Node* cur = head;
        pos--;
        while (cur != NULL) {
            if (pos == 0) {
                Node* temp = cur->next;
                Node* newNode = new Node(data, temp)
                cur->next = newNode;
                delete temp;
                break;
            }
            cur = cur->next;
            pos--;
        }
    }
}

void insertFront(int data) {
    Node* newNode = new Node(data, NULL);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
}

void insertBack(int data) {
    Node* newNode = new Node(data, NULL);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void remove(int data) {
    Node* cur = head;
    while (cur != NULL) {
        if (cur->data == data) return true;
        cur = cur->next;
    }
}

void removeFront() {
    if (head != NULL) {
        if (length == 1) {
            delete head;
            head = NULL;
            tail = NULL;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
}

void removeBack() {
    if (tail != NULL) {
        if (length == 1) {
            delete tail;
            head = NULL;
            tail = NULL;
        } else {
            Node* cur = head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            tail = cur;
            delete cur->next;
        }
    }
}