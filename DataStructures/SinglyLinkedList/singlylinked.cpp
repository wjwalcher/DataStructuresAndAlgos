/*
** Author: William Walcher
** Date: June 2018
** Implementation of a singly linked list
** using both a head and tail pointer, length tracking 
** O(1) front and back insertions
** O(1) front removal, O(n) back removal
** O(n) find, O(n) insertion/removal at specified index
*/


#include "singlylinked.h"
#include <iostream>

struct Node* head = NULL;
struct Node* tail = NULL;
int length = 0;

void insert(Node* node, int pos, int data) {
    if (length == 0) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
    } else {
        Node* cur = head;
        pos--;
        while (cur != NULL) {
            if (pos == 0) {
                Node* temp = cur->next;
                Node* newNode = new Node;
                newNode->data = data;
                newNode->next = temp;
                cur->next = newNode;
                length++;
                break;
            }
            cur = cur->next;
            pos--;
        }
    }
}

void insertFront(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        length++;
    } else {
        newNode->next = head;
        head = newNode;
        length++;
    }
}

void insertBack(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        length++;
    } else {
        tail->next = newNode;
        tail = newNode;
        length++;
    }
}

// TODO: remove the node with given data, if it exists
/*
void remove(int data) {
    Node* cur = head;
    if (head->data == data) {
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }
    while (cur->next != NULL) {
        if (cur->next->data == data) {
            // TODO
        }
        cur = cur->next;
    }
}
*/

void removeFront() {
    if (head != NULL) {
        if (length == 1) {
            delete head;
            head = NULL;
            tail = NULL;
            length--;
        } else {
            Node* temp = head;
            head = head->next;
            delete temp;
            length--;
        }
    }
}

void removeBack() {
    if (tail != NULL) {
        if (length == 1) {
            delete tail;
            head = NULL;
            tail = NULL;
            length--;
        } else {
            Node* cur = head;
            Node* prev;
            while (cur->next != NULL) {
                prev = cur;
                cur = cur->next;
            }
            tail = prev;
            tail->next = NULL;
            delete cur;
            length--;
        }
    }
}

int size() {
    return length;
}

int main () {
    // Test List Here
    insertFront(5);
    insertBack(11);
    removeBack();
    insertBack(50);
    removeFront();
    std::cout << "Current size is: " << length << std::endl;
    std::cout << "Printing node values..." << std::endl;
    Node* cur = head;
    while (cur != NULL) {
        std::cout << cur->data << std::endl;
        cur = cur->next;
    }
}