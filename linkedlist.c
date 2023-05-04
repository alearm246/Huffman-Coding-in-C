#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

Node *createNode(int data, struct Node *next, struct Node *prev) {
  struct Node *node = (struct Node *) malloc(sizeof(struct Node));
  node->next = next;
  node->prev = prev;
  node->data = data;
  return node;
}

LinkedList *createLinkedList() {
    LinkedList *list = (LinkedList *) malloc(sizeof(struct LinkedList));
    list->first = NULL;
    list->last = NULL;
    list->size = 0;
    return list;
}

Node* getNodeAtPos(LinkedList *list, int pos) {
    Node* temp = list->first;
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

void addLast(struct LinkedList *list, int data) {
  if (list->size == 0) {
    addFirst(list, data);
  } else {
    struct Node *node = createNode(data, NULL, list->last);
    list->last = node;
    list->last->prev->next = node;
    list->size++;
  }
}
void insert(struct LinkedList *list, int pos, int data) {
  if (list->size == 0) {
    addFirst(list, data);
  } else if (pos == list->size) {
    addLast(list, data);
  } else {
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
    if (pos < 0 || pos >= list->size) {
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

int get(LinkedList *list, int pos) {
    return getNodeAtPos(list, pos)->data;
}



void printList(struct LinkedList *list) {
  struct Node *temp = list->first;
  printf("[%d", temp->data);
  temp = temp->next;
  while (temp != NULL) {
    printf(", %d", temp->data);
    temp = temp->next;
  }
  printf("]");
}
