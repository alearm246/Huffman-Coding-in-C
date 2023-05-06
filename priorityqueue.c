#include <stdlib.h>
#include <stdbool.h>
#include "priorityqueue.h"
#include "linkedlist.h"

PriorityQueue *createPriorityQueue() {
    PriorityQueue *newQueue = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    newQueue->con = createLinkedList();
    return newQueue;
}

bool enqueue(PriorityQueue *queue, int data) {
    
}

int dequeue(PriorityQueue *queue) {
    return removeFirst(queue->con);
}

int peek(PriorityQueue *queue) {
    return get(queue->con, 0);
}

bool isEmpty(PriorityQueue *queue) {
    return size(queue) == 0;
}

int size(PriorityQueue *queue) {
    return queue->con->size;
}