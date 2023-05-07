#include <stdbool.h>
#include "linkedlist.h"

typedef struct PriorityQueue {
    LinkedList *con;
} PriorityQueue;

PriorityQueue *createPriorityQueue();
void enqueue(PriorityQueue *queue, int data);
int dequeue(PriorityQueue *queue);
int peek(PriorityQueue *queue);
bool isEmpty(PriorityQueue *queue);
int size(PriorityQueue *queue);
void destroyPriorityQueue(PriorityQueue *queue);