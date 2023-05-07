#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdbool.h>

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

typedef struct LinkedListIterator {
    LinkedList *list;
    Node *currentNode;
} LinkedListIterator;

void insert(LinkedList *list, int pos, int data);
void addFirst(LinkedList *list, int data);
void addLast(LinkedList *list, int data);
void printList(LinkedList *list);
Node *createNode(int data, Node* next, Node* prev);
int removeNode(LinkedList *list, int pos);
int removeFirst(LinkedList *list);
int removeLast(LinkedList *list);
void removeRange(LinkedList *list, int start, int stop);
bool removeByInt(LinkedList *list, int data);
int get(LinkedList *list, int pos);
int indexOf(LinkedList *list, int data);
int indexOfStartingAt(LinkedList *list, int data, int start);
int set(LinkedList *list, int pos, int data);
LinkedList *createLinkedList();
LinkedList *getSubList(LinkedList *list, int start, int stop);
bool equals(LinkedList *list1, LinkedList *list2);
void makeEmpty(LinkedList *list);
void destroyList(LinkedList *list);
Node *getNodeAtPos(LinkedList *list, int pos);
LinkedListIterator *createLinkedListIterator(LinkedList *list);
bool hasNext(LinkedListIterator *iterator);
int next(LinkedListIterator *iterator);
void resetIterator(LinkedListIterator *iterator);

#endif // LINKEDLIST_H