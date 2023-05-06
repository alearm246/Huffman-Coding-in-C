#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void populateList(LinkedList *list, int nums[], int size) {
    for (int i = 0; i < size; i++) {
        addLast(list, nums[i]);
    }
}

void linkedListTests();

int main() {
    linkedListTests();
}

void linkedListTests() {
    //tests 1 - 2 createLinkedList()
    LinkedList *list = createLinkedList();
    if (list != NULL) {
        printf("Passed test 1 createLinkedList() list is not null when creating\n");
    } else {
        printf("Failed test 1 list is null when created\n");
    }

    if (list->first == NULL && list->last == NULL && list->size == 0) {
        printf("Passed test 2 createLinkedList() list was properly initialized\n");
    } else {
        printf("Failed test 2 createLinkedList() list was not properly initialized\n");
    }

    //tests 2 - 6 createNode()
    Node *node = createNode(2, NULL, NULL);
    if (node != NULL) {
        printf("Passed test 3 createNode() list is not null when creating\n");
    } else {
        printf("Failed test 3 createNode() list is null when creating\n");
    }

    if (node->data == 2) {
        printf("Passed test 4 createNode() list data was succesfully initialized\n");
    } else {
        printf("Failed test 4 createNode() list data was not succesfully initialized\n");
    }

    if (node->next == NULL && node->prev == NULL) {
        printf("Passed test 5 createNode() list next and prev was properly set to null\n");
    } else {
        printf("Failed test 5 createNode() list next and/or prev was not properly set to null\n");
    }

    Node *node2 = createNode(5, NULL, NULL);
    Node *node3 = createNode(10, node, node2);
    if (node3->next == node && node3->prev == node2) {
        printf("Passed test 6 createNode() list next and prev were properly set to the nodes\n");
    } else {
        printf("Failed test 6 craeteNode() list next and prev were properly set to the nodes\n");
    }
    free(node);
    free(node2);
    free(node3);

    //tests 7 - 11 addLast
    addLast(list, 5);
    if (list->first == list->last && list->size == 1 && list->first->data == 5 && list->last->data == 5
                && list->first->next == NULL && list->last->next == NULL && list->first->prev == NULL
                && list->last->prev == NULL) {
        printf("Passed test 7 addLast() added node to the end of the list when list was empty\n");
    } else {
        printf("Failed test 7 addLast() added node to the end of the list when list was empty\n");
    }

    addLast(list, 10);
    Node* lastNode = getNodeAtPos(list, list->size - 1);
    if (list->first->next == lastNode && list->last == lastNode && list->size == 2 && list->last->data == 10) {
        printf("Passed test 8 addLast() added node to the end of the list when there is one node\n");
    } else {
        printf("Failed test 8 addLast() added node to the end of the list when there is one node\n");
    }

    addLast(list, 99);
    addLast(list, 22);
    addLast(list, 100);
    Node* lastNode1 = getNodeAtPos(list, list->size - 1);
    Node* prevNode = getNodeAtPos(list, list->size - 2);
    if (list->last == lastNode1 && list->size == 5 && list->last->data == 100 && list->last->prev == prevNode) {
        printf("Passed test 9 addLast()\n");
    } else {
        printf("Failed test 9 addLast()\n");
    }

    addLast(list, -10);
    if (list->last->data == -10 && list->size == 6) {
        printf("Passed test 10 addLast() adding a negative number\n");
    } else {
        printf("Failed test 10 addLast() adding a negative number\n");
    }

    addLast(list, 0);
    if (list->last->data == 0 && list->size == 7) {
        printf("Passed test 11 addLast() adding zero\n");
    } else {
        printf("Failed test 11 addLast() adding zero\n");
    }
    destroyList(list);

    //test 12 - 16 addFirst()
    LinkedList *list2 = createLinkedList();
    addFirst(list2, 10);
    if (list2->first == list2->last && list2->size == 1 && list2->first->next == NULL && list2->last->next == NULL
                && list2->first->prev == NULL && list2->last->prev == NULL && list2->first->data == 10
                && list2->first->data == 10 && list2->last->data == 10) {
        printf("Passed test 12 addFirst() adding node to empty list\n");
    } else {
        printf("Failed test 12 addFirst() adding node to empty list\n");
    }

    addFirst(list2, 20);
    Node *firstNode = getNodeAtPos(list2, 0);
    Node *prevFirstNode = getNodeAtPos(list2, 1);
    if (list2->first == firstNode && list2->first->data == 20 && list2->size == 2 &&  list2->first->next == prevFirstNode
                && list2->first->prev == NULL && prevFirstNode->prev == list2->first) {
        printf("Passed test 13 addFirst() adding node when there is one element\n");
    } else {
        printf("Failed test 13 addFirst() adding node when there is one element\n");
    }

    addFirst(list2, 60);
    addFirst(list2, 500);
    Node *firstNode1 = getNodeAtPos(list2, 0);
    Node *prevFirstNode2 = getNodeAtPos(list2, 1);
    if (list2->first == firstNode1 & list2->size == 4 && list2->first->data == 500 && list2->first->next == prevFirstNode2
                && list2->first->prev == NULL && list2->first->next->prev == list2->first) {
        printf("Passed test 14 addFirst() adding node when there is more than one element\n");
    } else {
        printf("Failed test 14 addFirst() adding node when there is more than one element\n");
    }

    addFirst(list2, 0);
    if (list2->first->data == 0 && list2->size == 5) {
        printf("Passed test 15 addFirst() adding 0 to list\n");
    } else {
        printf("Failed test 15 addFirst() adding 0 to list\n");
    }

    addFirst(list2, -4);
    if (list2->first->data == -4 && list2->size == 6) {
        printf("Passed test 16 addFirst() adding negative numbers\n");
    } else {
        printf("Failed test 16 addFirst() adding negative numbers\n");
    }
    destroyList(list2);

    // Test 1: Check for getting node at position 0 in list of size 1
    LinkedList *list3 = createLinkedList();
    addLast(list3, 5);
    Node *node5 = getNodeAtPos(list3, 0);
    if (node5->data == 5) {
        printf("Passed test 17: getNodeAtPos returns correct node for position 0 in list of size 1.\n");
    } else {
        printf("Failed test 17: getNodeAtPos does not return correct node for position 0 in list of size 1.\n");
    }
    destroyList(list3);

    // Test 2: Check for getting node at the end of the list
    int nums[] = {5, 10, 15, 20};
    int size = sizeof(nums) / sizeof(nums[0]);
    LinkedList *list4 = createLinkedList();
    populateList(list4, nums, size);
    Node *lastNode3 = getNodeAtPos(list4, size - 1);
    if (lastNode3->data == 20) {
        printf("Passed test 18: getNodeAtPos returns correct node for last position in list.\n");
    } else {
        printf("Failed test 18: getNodeAtPos does not return correct node for last position in list.\n");
    }
    destroyList(list4);

    // Test 3: Check for getting node at an invalid position (negative)
    LinkedList *list5 = createLinkedList();
    Node *invalidNode = getNodeAtPos(list5, -1);
    if (invalidNode == NULL) {
        printf("Passed test 19: getNodeAtPos returns NULL for negative position.\n");
    } else {
        printf("Failed test 19: getNodeAtPos does not return NULL for negative position.\n");
    }
    destroyList(list5);

    // Test 4: Check for getting node at an invalid position (larger than list size)
    LinkedList *list6 = createLinkedList();
    addLast(list6, 5);
    Node *invalidNode2 = getNodeAtPos(list6, 1);
    if (invalidNode2 == NULL) {
        printf("Passed test 20: getNodeAtPos returns NULL for position larger than list size.\n");
    } else {
        printf("Failed test 20: getNodeAtPos does not return NULL for position larger than list size.\n");
    }
    destroyList(list6);

    // Test 5: Check for getting node at a valid position in a larger list
    int nums2[] = {5, 10, 15, 20, 25, 30, 35};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    LinkedList *list7 = createLinkedList();
    populateList(list7, nums2, size2);
    Node *node6 = getNodeAtPos(list7, 3);
    if (node6->data == 20) {
        printf("Passed test 21: getNodeAtPos returns correct node for valid position in larger list.\n");
    } else {
        printf("Failed test 21: getNodeAtPos does not return correct node for valid position in larger list.\n");
    }
    destroyList(list7);

    // Test 23: Insert at position 0 in an empty list
    LinkedList *list8 = createLinkedList();
    insert(list8, 0, 5);
    if (list8->first->data == 5 && list8->last->data == 5 && list8->size == 1) {
        printf("Passed test 23: Insert at position 0 in an empty list\n");
    } else {
        printf("Failed test 23: Insert at position 0 in an empty list\n");
    }
    destroyList(list8);

    // Test 24: Insert at position 0 in a non-empty list
    int nums1[] = {1, 2, 3, 4};
    LinkedList *list9 = createLinkedList();
    populateList(list9, nums1, 4);
    insert(list9, 0, 5);
    if (list9->first->data == 5 && list9->first->next->data == 1 && list9->size == 5) {
        printf("Passed test 24: Insert at position 0 in a non-empty list\n");
    } else {
        printf("Failed test 24: Insert at position 0 in a non-empty list\n");
    }
    destroyList(list9);

    // Test 25: Insert at the back of the list
    int nums3[] = {1, 2, 3, 4};
    LinkedList *list10 = createLinkedList();
    populateList(list10, nums3, 4);
    insert(list10, 4, 5);
    if (list10->last->data == 5 && list10->last->prev->data == 4 && list10->size == 5) {
        printf("Passed test 25: Insert at the back of the list\n");
    } else {
        printf("Failed test 25: Insert at the back of the list\n");
    }
    destroyList(list10);

    // Test 26: Insert at the middle of the list
    int nums4[] = {1, 2, 4, 5};
    LinkedList *list11 = createLinkedList();
    populateList(list11, nums4, 4);
    insert(list11, 2, 3);
    if (list11->first->next->next->data == 3 && list11->first->next->next->prev->data == 2 && list11->size == 5) {
        printf("Passed test 26: Insert at the middle of the list\n");
    } else {
        printf("Failed test 26: Insert at the middle of the list\n");
    }
    destroyList(list11);

    // Test 27: Insert at an invalid position (position < 0)
    LinkedList *list12 = createLinkedList();
    insert(list12, -1, 5);
    if (list12->size == 0) {
        printf("Passed test 27: Insert at an invalid position (position < 0)\n");
    } else {
        printf("Failed test 27: Insert at an invalid position (position < 0)\n");
    }
    destroyList(list12);

    // Test 28: Insert at an invalid position (position >= size)
    int nums5[] = {1, 2, 3};
    LinkedList *list13 = createLinkedList();
    populateList(list13, nums5, 3);
    insert(list13, 4, 4);
    if (list13->size == 3) {
        printf("Passed test 28: Insert at an invalid position (position >= size)\n");
    } else {
        printf("Failed test 28: Insert at an invalid position (position >= size)\n");
    }
    destroyList(list13);

    // Test 29: Removing from an empty list should return -1
    LinkedList *list14 = createLinkedList();
    int removeResult1 = removeFirst(list14);
    if (removeResult1 == -1 && list14->first == NULL && list14->last == NULL && list14->size == 0) {
        printf("Passed test 29: Removing from an empty list returns -1\n");
    } else {
        printf("Failed test 29: Removing from an empty list does not return -1\n");
    }
    destroyList(list14);

    // Test 30: Removing from a list with one element should return the data from the node and leave the list empty
    LinkedList *list15 = createLinkedList();
    addFirst(list15, 5);
    int removeResult2 = removeFirst(list15);
    if (removeResult2 == 5 && list15->first == NULL && list15->last == NULL && list15->size == 0) {
        printf("Passed test 30: Removing from a list with one element returns the data and leaves the list empty\n");
    } else {
        printf("Failed test 30: Removing from a list with one element does not return the data or leave the list empty\n");
    }
    destroyList(list15);

    // Test 31: Removing from a list with multiple elements should return the data from the first node and remove that node from the list
    int nums6[] = {1, 2, 3};
    LinkedList *list16 = createLinkedList();
    populateList(list16, nums6, 3);
    int removeResult3 = removeFirst(list16);
    if (removeResult3 == 1 && list16->first->data == 2 && list16->last->data == 3 && list16->size == 2) {
        printf("Passed test 31: Removing from a list with multiple elements returns the data and removes the first node\n");
    } else {
        printf("Failed test 31: Removing from a list with multiple elements does not return the data or remove the first node\n");
    }
    destroyList(list16);

    int nums7[] = {5, 6, 7};
    LinkedList *list17 = createLinkedList();
    populateList(list17, nums7, 3);
    removeFirst(list17);
    removeFirst(list17);
    int removeResult4 = removeFirst(list17);
    if (removeResult4 == 7 && list17->first == NULL && list17->last == NULL && list17->size == 0) {
        printf("Passed test 31: Removing from a list with multiple elements returns the data and removes the first node\n");
    } else {
        printf("Failed test 31: Removing from a list with multiple elements does not return the data or remove the first node\n");
    }
    printList(list);
    destroyList(list17);

}