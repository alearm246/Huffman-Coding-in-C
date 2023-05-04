typedef struct Node Node;

typedef struct Node {
    int data;
    Node *next;
    Node *prev;
} Node;

typedef struct LinkedList {
    Node *first;
    Node *last;
    int size;
} LinkedList;

void insert(LinkedList *list, int pos, int data);
void addFirst(LinkedList *list, int data);
void addLast(LinkedList *list, int data);
void printList(LinkedList *list);
Node *createNode(int data, Node* next, Node* prev);
int removeNode(LinkedList *list, int pos);
int removeFirst(LinkedList *list);
int removeLast(LinkedList *list);
int get(LinkedList *list, int pos);
LinkedList *createLinkedList();