#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main() {
    LinkedList *list = createLinkedList();
    addLast(list, 5);
    addLast(list, 10);
    addLast(list, 15);
    addLast(list, 20);
    int data = removeNode(list, 2);
    printf("data that was removed: %d\n", data);
    printList(list);
    printf("get: %d", get(list, 2));
    return 0;
}