#include <stdlib.h>
#include <stdbool.h>
#include "priorityqueue.h"
#include "linkedlist.h"

PriorityQueue *createPriorityQueue() {
    PriorityQueue *newQueue = (PriorityQueue *) malloc(sizeof(PriorityQueue));
    newQueue->con = createLinkedList();
    return newQueue;
}

int searchForSpotToInsert(PriorityQueue *queue, int data) {
    LinkedListIterator *iterator = createLinkedListIterator(queue->con);
    int index = 0;
    while (hasNext(iterator)) {
        int value = next(iterator);
        if (data < value) {
            free(iterator);
            return index;
        } else if (data == value) {
            while (hasNext(iterator) && data == value) {
                value = next(iterator);
                index++;
            }
            free(iterator);
            return index;
        } 
        index++;
    }
    free(iterator);
    return size(queue);
}

void enqueue(PriorityQueue *queue, int data) {
   int index = searchForSpotToInsert(queue, data);
   insert(queue->con, index, data);
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

void destroyPriorityQueue(PriorityQueue *queue) {
    destroyList(queue->con);
    free(queue);
}