#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "linkedlist.h"

Node *createNode(int data, Node *next, Node *prev) {
  Node *node = (Node *) malloc(sizeof(Node));
  node->next = next;
  node->prev = prev;
  node->data = data;
  return node;
}

LinkedList *createLinkedList() {
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

Node *getNodeAtPos(LinkedList *list, int pos) {
    if (pos < 0 || pos >= list->size) {
        return NULL;
    }
    Node *temp = list->first;
    for (int i = 0; i < pos; i++) {
        temp = temp->next;
    }
    return temp;
}

void addFirst(LinkedList *list, int data) {
    if (list->size == 0) {
        struct Node *node = createNode(data, NULL, NULL);
        list->first = node;
        list->last = node;
    } else {
        struct Node *node = createNode(data, list->first, NULL);
        list->first = node;
        list->first->next->prev = node;
    }
    list->size++;
}

void addLast(LinkedList *list, int data) {
  if (list->size == 0) {
    addFirst(list, data);
  } else {
    struct Node *node = createNode(data, NULL, list->last);
    list->last = node;
    list->last->prev->next = node;
    list->size++;
  }
}

void insert(LinkedList *list, int pos, int data) {
    if (pos == 0) {
        addFirst(list, data);
    } else if (pos == list->size) {
        addLast(list, data);
    } else if (pos > 0 && pos < list->size) {
        struct Node *temp = list->first;
        int index = 0;
        while (temp != NULL) {
            if (index == pos) {
                struct Node *node = createNode(data, temp, temp->prev);
                temp->prev->next = node; 
                temp->prev = node;
                break;
            }
            temp = temp->next;
            index++;
        }
        list->size++;
    }
}

int removeFirst(LinkedList *list) {
    if (list->size == 0) {
        return -1;
    }
    int data = list->first->data;
    if (list->size == 1) {
        Node *node = list->first;
        list->first = NULL;
        list->last = NULL;
        free(node);
    } else {
        list->first = list->first->next;
        list->first->prev->next = NULL;
        free(list->first->prev);
        list->first->prev = NULL;
    }
    list->size--;
    return data;
}

int removeLast(LinkedList *list) {
    if (list->size == 0) {
        return -1;
    }
    int data = list->last->data;
    if (list->size == 1) {
        Node *node = list->last;
        list->first = NULL;
        list->last = NULL;
        free(node);
    } else {
        list->last = list->last->prev;
        list->last->next->prev = NULL;
        free(list->last->next);
        list->last->next = NULL;
    }
    list->size--;
    return data;
}

int removeNode(LinkedList *list, int pos) {
    if (pos < 0 || pos >= list->size || list->size == 0) {
        return -1;
    }
    int data;
    if (pos == 0) {
        data = removeFirst(list);
    } else if (pos == list->size - 1) {
        data = removeLast(list);
    } else {
        int index = 0;
        Node *node = getNodeAtPos(list, pos);
        data = node->data;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        node->prev = NULL;
        node->next = NULL;
        free(node);
        list->size--;
    }
    return data;
}

bool removeByInt(LinkedList *list, int data) {
    int index = 0;
    Node *temp = list->first;
    int oldSize = list->size;
    while (temp != NULL) {
        if (temp->data == data) {
            removeNode(list, index);
            break;
        } else {
            index++;
        }
        temp = temp->next;
    }
    return list->size != oldSize;
}


int get(LinkedList *list, int pos) {
    if (pos < 0 || pos >= list->size) {
        return -1;
    }
    return getNodeAtPos(list, pos)->data;
}

int indexOf(LinkedList *list, int data) {
    Node *temp = list->first;
    int index = 0;
    while (temp != NULL) {
        if (temp->data == data) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int indexOfStartingAt(LinkedList *list, int data, int pos) {
    if (pos < 0 || pos >= list->size) {
        return -1;
    }
    Node *temp = list->first;
    int index = 0;
    while (temp != NULL) {
        if (index >= pos) {
            if (temp->data == data) {
                return index;
            }
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int set(LinkedList *list, int pos, int data) {
    if (pos < 0 || pos >=list->size) {
        return -1;
    }
    Node *node = getNodeAtPos(list, pos);
    int oldData = node->data;
    node->data = data;
    return oldData;
}

LinkedList *getSubList(LinkedList *list, int start, int stop) {
    if (start < 0 || start > list->size || stop < start || stop > list->size) {
        return NULL;
    }
    LinkedList *subList = createLinkedList();
    Node *temp = list->first;
    for (int i = 0; i < stop; i++) {
        if (i >= start) {
            addLast(subList, temp->data);
        }
        temp = temp->next;
    }
    return subList;
}

bool equals(LinkedList *list1, LinkedList *list2) {
    if (list1->size != list2->size) {
        return false;
    }
    Node *temp1 = list1->first;
    Node *temp2 = list2->first;
    while (temp1 != NULL) {
        if (temp1->data != temp2->data) {
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}

void makeEmpty(LinkedList *list) {
    if (list != NULL) {
        Node *temp = list->first;
        while (temp != NULL) {
            Node *prevNode = temp;
            temp = temp->next;
            free(prevNode);
        }
        list->first = NULL;
        list->last = NULL;
        list->size = 0;
    }
}

void destroyList(LinkedList *list) {
    Node *temp = list->first;
    while (temp != NULL) {
        Node *prevNode = temp;
        temp = temp->next;
        free(prevNode);
    }
    free(list);
}

void removeRange(LinkedList *list, int start, int stop) {
    if (start < 0 || start > list->size || stop < start || stop > list->size) {
        return;
    }
    if (start == 0) {
        for (int i = 0; i < stop; i++) {
            removeFirst(list);
        }
    } else {
        Node *temp = list->first;
        int oldSize = list->size;
        int newStop = stop == list->size ? stop - 1 : stop;
        for (int i = 0; i < newStop; i++) {
            if (i >= start) {
                Node *currentNode = temp;
                temp->next->prev = temp->prev;
                temp->prev->next = temp->next;
                free(currentNode);
                list->size--;
            }
            temp = temp->next;
        }
        if (stop == oldSize) {
            removeLast(list);
        }
    }
}

LinkedListIterator *createLinkedListIterator(LinkedList *list) {
    LinkedListIterator *iterator = (LinkedListIterator *) malloc(sizeof(LinkedListIterator));
    iterator->list = list;
    iterator->currentNode = list->first;
    return iterator;
}

bool hasNext(LinkedListIterator *iterator) {
    return iterator->currentNode != NULL;
}

int next(LinkedListIterator *iterator) {
    int data = iterator->currentNode->data;
    iterator->currentNode = iterator->currentNode->next;
    return data;
}

void resetIterator(LinkedListIterator *iterator) {
    iterator->currentNode = iterator->list->first;
}

void printList(LinkedList *list) {
    Node *temp = list->first;
    printf("[");
    if (list->first != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
        while (temp != NULL) {
            printf(", %d", temp->data);
            temp = temp->next;
        }
    }
    printf("]");
}
