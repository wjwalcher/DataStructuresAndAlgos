
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