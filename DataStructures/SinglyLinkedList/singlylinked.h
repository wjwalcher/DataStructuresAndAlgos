/*
** Author: William Walcher
** Date: June 2018
** Implementation of a singly linked list
** using both a head and tail pointer 
** O(1) front and back insertions
** O(1) front removal, O(n) back removal
** O(n) find, O(n) removal at specified index
*/

struct Node {
   int data;
   Node* next;
};

   
void insert(int pos, int data);
void insertFront(int data);
void insertBack(int data);
void remove(int data);
void removeFront();
void removeBack();
int size();