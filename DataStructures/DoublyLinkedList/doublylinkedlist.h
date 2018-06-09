
typedef struct Node {
    int data;

    Node* next;
    Node* prev;
};

void insertFront(int data);
void insertBack(int data);
void insert(Node* node, int pos, int data); 
Node* find(int data);
void removeFront();
void removeBack();
void remove(Node* prev, Node* cur, int pos);
void remove(Node* prev, Node* cur, int data);