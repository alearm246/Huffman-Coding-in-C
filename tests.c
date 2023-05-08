#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linkedlist.h"
#include "priorityqueue.h"
#include "huffman_tree_node.h"

void populateList(LinkedList *list, int nums[], int size) {
    for (int i = 0; i < size; i++) {
        addLast(list, nums[i]);
    }
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
    int removeResult4 = 0;
    for (int i = 0; i < 3; i++) {
        removeResult4 = removeFirst(list17);
    }
    if (removeResult4 == 7 && list17->first == NULL && list17->last == NULL && list17->size == 0) {
        printf("Passed test 31: Removing from a list with multiple elements returns the data and removes the first node with loop\n");
    } else {
        printf("Failed test 31: Removing from a list with multiple elements does not return the data or remove the first node with loop\n");
    }
    destroyList(list17);

    // Test 31: Removing from an empty list returns -1
    LinkedList *list31 = createLinkedList();
    if (removeLast(list31) == -1) {
        printf("Passed test 31: Removing from an empty list returns -1\n");
    } else {
        printf("Failed test 31: Removing from an empty list should return -1\n");
    }
    destroyList(list31);

    // Test 32: Removing from a list with one element returns the data and leaves the list empty
    LinkedList *list32 = createLinkedList();
    addLast(list32, 5);
    if (removeLast(list32) == 5 && list32->size == 0 && list32->first == NULL && list32->last == NULL) {
        printf("Passed test 32: Removing from a list with one element returns the data and leaves the list empty\n");
    } else {
        printf("Failed test 32: Removing from a list with one element did not return the correct data or leave the list empty\n");
    }
    destroyList(list32);

    // Test 33: Removing from a list with multiple elements returns the data and removes the last node
    LinkedList *list33 = createLinkedList();
    int nums33[] = {1, 2, 3};
    populateList(list33, nums33, 3);
    if (removeLast(list33) == 3 && list33->size == 2 && list33->last->data == 2) {
        printf("Passed test 33: Removing from a list with multiple elements returns the data and removes the last node\n");
    } else {
        printf("Failed test 33: Removing from a list with multiple elements did not return the correct data or remove the last node\n");
    }
    destroyList(list33);

    // Test 34: Removing from a list with negative elements
    LinkedList *list34 = createLinkedList();
    addLast(list34, -1);
    addLast(list34, -2);
    addLast(list34, -3);
    if (removeLast(list34) == -3 && list34->size == 2 && list34->last->data == -2) {
        printf("Passed test 34: Removing from a list with negative elements\n");
    } else {
        printf("Failed test 34: Removing from a list with negative elements did not return the correct data or remove the last node\n");
    }
    destroyList(list34);

    // Test 35: Removing from a list with zero
    LinkedList *list35 = createLinkedList();
    addLast(list35, 0);
    addLast(list35, 0);
    addLast(list35, 0);
    if (removeLast(list35) == 0 && list35->size == 2 && list35->last->data == 0) {
        printf("Passed test 35: Removing from a list with zero\n");
    } else {
        printf("Failed test 35: Removing from a list with zero did not return the correct data or remove the last node\n");
    }
    destroyList(list35);

    // Test 36: Removing from an invalid position (position < 0)
    LinkedList *list36 = createLinkedList();
    addLast(list36, 1);
    if (removeLast(list36) == 1 && list36->size == 0 && list36->first == NULL && list36->last == NULL && removeLast(list36) == -1) {
        printf("Passed test 36: Removing from an invalid position (position < 0) does not remove any elements\n");
    } else {
        printf("Failed test 36: Removing from an invalid position (position < 0) should not remove any elements\n");
    }

    LinkedList *list37 = createLinkedList();
    int result37 = removeNode(list37, 0);
    if (result37 == -1 && list37->size == 0) {
        printf("Passed test 37: Removing from an empty list\n");
    } else {
        printf("Failed test 37: Removing from an empty list\n");
    }
    destroyList(list37);

    LinkedList *list38 = createLinkedList();
    addFirst(list38, 5);
    int result38 = removeNode(list38, 0);
    if (result38 == 5 && list38->size == 0 && list38->first == NULL && list38->last == NULL) {
        printf("Passed test 38: Removing the only element in a list\n");
    } else {
        printf("Failed test 38: Removing the only element in a list\n");
    }
    destroyList(list38);

    LinkedList *list39 = createLinkedList();
    int nums39[] = {1, 2, 3};
    populateList(list39, nums39, 3);
    int result39 = removeNode(list39, 0);
    if (result39 == 1 && list39->size == 2 && list39->first->data == 2) {
        printf("Passed test 39: Removing the first element in a list with multiple elements\n");
    } else {
        printf("Failed test 39: Removing the first element in a list with multiple elements\n");
    }
    destroyList(list39);

    LinkedList *list40 = createLinkedList();
    int nums40[] = {1, 2, 3};
    populateList(list40, nums40, 3);
    int result40 = removeNode(list40, 2);
    if (result40 == 3 && list40->size == 2 && list40->last->data == 2) {
        printf("Passed test 40: Removing the last element in a list with multiple elements\n");
    } else {
        printf("Failed test 40: Removing the last element in a list with multiple elements\n");
    }
    destroyList(list40);

    LinkedList *list41 = createLinkedList();
    int nums41[] = {1, 2, 3};
    populateList(list41, nums41, 3);
    int result41 = removeNode(list41, 1);
    if (result41 == 2 && list41->size == 2 && list41->first->data == 1 && list41->last->data == 3) {
        printf("Passed test 41: Removing an element in the middle of a list with multiple elements\n");
    } else {
        printf("Failed test 41: Removing an element in the middle of a list with multiple elements\n");
    }
    destroyList(list41);

    // Test 41: Removing element from an empty list should return false.
    LinkedList* list100 = createLinkedList();
    bool result100 = removeByInt(list100, 1);
    if (!result100 && list100->size == 0) {
        printf("Passed test 41: Removing from an empty list returns false\n");
    } else {
        printf("Failed test 41: Removing from an empty list should return false\n");
    }
    destroyList(list100);

    // Test 42: Removing the only element in the list should return true and make the list empty.
    LinkedList* list42 = createLinkedList();
    addFirst(list42, 1);
    bool result42 = removeByInt(list42, 1);
    if (result42 && list42->size == 0) {
        printf("Passed test 42: Removing the only element in the list should return true and make the list empty\n");
    } else {
        printf("Failed test 42: Removing the only element in the list should return true and make the list empty\n");
    }
    destroyList(list42);

    // Test 43: Removing the last element in the list should return true and remove the element.
    int nums43[] = {1, 2, 3};
    LinkedList* list43 = createLinkedList();
    populateList(list43, nums43, 3);
    bool result43 = removeByInt(list43, 3);
    if (result43 && list43->last->data == 2 && list43->size == 2) {
        printf("Passed test 43: Removing the last element in the list should return true and remove the element\n");
    } else {
        printf("Failed test 43: Removing the last element in the list should return true and remove the element\n");
    }
    destroyList(list43);

    // Test 44: Removing the first element in the list should return true and remove the element.
    int nums44[] = {1, 2, 3};
    LinkedList* list44 = createLinkedList();
    populateList(list44, nums44, 3);
    bool result44 = removeByInt(list44, 1);
    if (result44 && list44->first->data == 2 && list44->size == 2) {
        printf("Passed test 44: Removing the first element in the list should return true and remove the element\n");
    } else {
        printf("Failed test 44: Removing the first element in the list should return true and remove the element\n");
    }
    destroyList(list44);

    // Test 45: Removing an element in the middle of the list should return true and remove the element.
    int nums45[] = {1, 2, 3};
    LinkedList* list45 = createLinkedList();
    populateList(list45, nums45, 3);
    bool result45 = removeByInt(list45, 2);
    if (result45 && list45->first->data == 1 && list45->last->data == 3 && list45->size == 2) {
        printf("Passed test 45: Removing an element in the middle of the list should return true and remove the element\n");
    } else {
        printf("Failed test 45: Removing an element in the middle of the list should return true and remove the element\n");
    }
    destroyList(list45);

    // Test 46: Removing a non-existent value returns false and does not change the list
    LinkedList *list46 = createLinkedList();
    int nums46[] = {1, 2, 3};
    populateList(list46, nums46, 3);
    bool result46 = removeByInt(list46, 4);
    if (!result46 && list46->size == 3 && list46->first->data == 1 && list46->last->data == 3) {
        printf("Passed test 46: Removing a non-existent value returns false and does not change the list\n");
    } else {
        printf("Failed test 46: Removing a non-existent value should return false and not change the list\n");
    }
    destroyList(list46);

    // Test 47: Getting data at position 0 in a list of size 1 returns the correct data.
    int num47 = 5;
    LinkedList *list47 = createLinkedList();
    addFirst(list47, num47);
    if (get(list47, 0) == num47) {
        printf("Passed test 47: Getting data at position 0 in a list of size 1 returns the correct data.\n");
    } else {
        printf("Failed test 47: Getting data at position 0 in a list of size 1 does not return the correct data.\n");
    }
    destroyList(list47);

    // Test 48: Getting data at the last position in a list of size 3 returns the correct data.
    int nums48[] = {1, 2, 3};
    LinkedList *list48 = createLinkedList();
    populateList(list48, nums48, 3);
    if (get(list48, 2) == nums48[2]) {
        printf("Passed test 48: Getting data at the last position in a list of size 3 returns the correct data.\n");
    } else {
        printf("Failed test 48: Getting data at the last position in a list of size 3 does not return the correct data.\n");
    }
    destroyList(list48);

    // Test 49: Getting data at a negative position returns -1.
    int nums49[] = {1, 2, 3};
    LinkedList *list49 = createLinkedList();
    populateList(list49, nums49, 3);
    if (get(list49, -1) == -1) {
        printf("Passed test 49: Getting data at a negative position returns -1.\n");
    } else {
        printf("Failed test 49: Getting data at a negative position does not return -1.\n");
    }
    destroyList(list49);

    // Test 50: Getting data at a position larger than the list size returns -1.
    int nums50[] = {1, 2, 3};
    LinkedList *list50 = createLinkedList();
    populateList(list50, nums50, 3);
    if (get(list50, 5) == -1) {
        printf("Passed test 50: Getting data at a position larger than the list size returns -1.\n");
    } else {
        printf("Failed test 50: Getting data at a position larger than the list size does not return -1.\n");
    }
    destroyList(list50);

    // Test 50: Return index of a single element in list
    int num200 = 5;
    LinkedList *list200 = createLinkedList();
    addLast(list200, num200);
    if (indexOf(list200, num200) == 0) {
        printf("Passed test 50: Index of single element in list is correct\n");
    } else {
        printf("Failed test 50: Index of single element in list is not correct\n");
    }
    destroyList(list200);

    // Test 51: Return index of first element in list with multiple elements
    int nums51[] = {3, 5, 7, 9, 11};
    LinkedList *list51 = createLinkedList();
    populateList(list51, nums51, 5);
    if (indexOf(list51, nums51[0]) == 0) {
        printf("Passed test 51: Index of first element in list with multiple elements is correct\n");
    } else {
        printf("Failed test 51: Index of first element in list with multiple elements is not correct\n");
    }
    destroyList(list51);

    // Test 52: Return index of last element in list with multiple elements
    int nums52[] = {3, 5, 7, 9, 11};
    LinkedList *list52 = createLinkedList();
    populateList(list52, nums52, 5);
    if (indexOf(list52, nums52[4]) == 4) {
        printf("Passed test 52: Index of last element in list with multiple elements is correct\n");
    } else {
        printf("Failed test 52: Index of last element in list with multiple elements is not correct\n");
    }
    destroyList(list52);

    // Test 53: Return -1 for element not in list
    int nums53[] = {3, 5, 7, 9, 11};
    LinkedList *list53 = createLinkedList();
    populateList(list53, nums53, 5);
    if (indexOf(list53, 4) == -1) {
        printf("Passed test 53: Index of element not in list is -1\n");
    } else {
        printf("Failed test 53: Index of element not in list is not -1\n");
    }
    destroyList(list53);

    // Test 54: Return -1 for empty list
    LinkedList *list54 = createLinkedList();
    if (indexOf(list54, 5) == -1) {
        printf("Passed test 54: Index of element in empty list is -1\n");
    } else {
        printf("Failed test 54: Index of element in empty list is not -1\n");
    }
    destroyList(list54);

    // Test 54: Getting an element from the middle of the list
    int nums55[] = {1, 2, 3, 4, 5};
    LinkedList *list55 = createLinkedList();
    populateList(list55, nums55, 5);
    int data55 = get(list55, 2);
    if (data55 == 3) {
        printf("Passed test 54: Got an element from the middle of the list\n");
    } else {
        printf("Failed test 54: Did not get the correct element from the middle of the list\n");
    }
    destroyList(list55);

    // Test 57: Search for an element in an empty list should return -1
    LinkedList *list57 = createLinkedList();
    int index57 = indexOfStartingAt(list57, 5, 0);
    if (index57 == -1) {
        printf("Passed test 57: Search for an element in an empty list returns -1\n");
    } else {
        printf("Failed test 57: Search for an element in an empty list did not return -1\n");
    }
    destroyList(list57);

    // Test 58: Search for an element at position 0 in a list with one element
    LinkedList *list58 = createLinkedList();
    insert(list58, 0, 5);
    int index58 = indexOfStartingAt(list58, 5, 0);
    if (index58 == 0) {
        printf("Passed test 58: Search for an element at position 0 in a list with one element returns 0\n");
    } else {
        printf("Failed test 58: Search for an element at position 0 in a list with one element did not return 0\n");
    }
    destroyList(list58);

    // Test 59: Search for an element at the end of a list with multiple elements
    int nums59[] = {1, 2, 3, 4, 5};
    LinkedList *list59 = createLinkedList();
    populateList(list59, nums59, 5);
    int index59 = indexOfStartingAt(list59, 5, 4);
    if (index59 == 4) {
        printf("Passed test 59: Search for an element at the end of a list with multiple elements returns correct index\n");
    } else {
        printf("Failed test 59: Search for an element at the end of a list with multiple elements did not return correct index\n");
    }
    destroyList(list59);

    // Test 60: Search for an element that is not in the list
    int nums60[] = {1, 2, 3, 4, 5};
    LinkedList *list60 = createLinkedList();
    populateList(list60, nums60, 5);
    int index60 = indexOfStartingAt(list60, 6, 0);
    if (index60 == -1) {
        printf("Passed test 60: Search for an element that is not in the list returns -1\n");
    } else {
        printf("Failed test 60: Search for an element that is not in the list did not return -1\n");
    }
    destroyList(list60);

    // Test 61: Search for an element in the middle of a list with multiple elements
    int nums61[] = {1, 2, 3, 4, 5};
    LinkedList *list61 = createLinkedList();
    populateList(list61, nums61, 5);
    int index61 = indexOfStartingAt(list61, 3, 1);
    if (index61 == 2) {
        printf("Passed test 61: Search for an element in the middle of a list with multiple elements returns correct index\n");
    } else {
        printf("Failed test 61: Search for an element in the middle of a list with multiple elements did not return correct index\n");
    }
    destroyList(list61);

    // Test 62: Set a node at position 0 in an empty list
    LinkedList *list900 = createLinkedList();
    int num900 = set(list900, 0, 5);
    if (num900 == -1 && list900->size == 0) {
        printf("Passed test 62: Set a node at position 0 in an empty list\n");
    } else {
        printf("Failed test 62: Set a node at position 0 in an empty list\n");
    }
    destroyList(list900);

    // Test 63: Set a node at position 0 in a list with one node
    LinkedList *list62 = createLinkedList();
    addLast(list62, 10);
    int num62 = set(list62, 0, 5);
    if (num62 == 10 && list62->first->data == 5 && list62->last->data == 5 && list62->size == 1) {
        printf("Passed test 63: Set a node at position 0 in a list with one node\n");
    } else {
        printf("Failed test 63: Set a node at position 0 in a list with one node\n");
    }
    destroyList(list62);

    // Test 64: Set a node at position 0 in a list with multiple nodes
    LinkedList *list63 = createLinkedList();
    int nums63[] = {1, 2, 3};
    populateList(list63, nums63, 3);
    int num63 = set(list63, 0, 5);
    if (num63 == 1 && list63->first->data == 5 && list63->last->data == 3 && list63->size == 3) {
        printf("Passed test 64: Set a node at position 0 in a list with multiple nodes\n");
    } else {
        printf("Failed test 64: Set a node at position 0 in a list with multiple nodes\n");
    }
    destroyList(list63);

    // Test 65: Set a node at the last position in a list with multiple nodes
    LinkedList *list64 = createLinkedList();
    int nums64[] = {1, 2, 3};
    populateList(list64, nums64, 3);
    int num64 = set(list64, 2, 5);
    if (num64 == 3 && list64->first->data == 1 && list64->last->data == 5 && list64->size == 3) {
        printf("Passed test 65: Set a node at the last position in a list with multiple nodes\n");
    } else {
        printf("Failed test 65: Set a node at the last position in a list with multiple nodes\n");
    }
    destroyList(list64);

    // Test 66: Set a node at the middle position in a list with multiple nodes
    LinkedList *list65 = createLinkedList();
    int nums65[] = {1, 2, 3, 4, 5};
    populateList(list65, nums65, 5);
    int num65 = set(list65, 2, 10);
    if (num65 == 3 && list65->first->data == 1 && list65->last->data == 5 && list65->size == 5 && list65->first->next->next->data == 10) {
        printf("Passed test 66: Set a node at the middle position in a list with multiple nodes\n");
    } else {
        printf("Failed test 66: Set a node at the middle position in a list with multiple nodes\n");
    }
    destroyList(list65);

    // Test 67: Set a node at an invalid position in a list with multiple nodes
    LinkedList *list66 = createLinkedList();
    int nums66[] = {10, 20, 30, 40, 50};
    populateList(list66, nums66, 5);
    int num66 = set(list66, -1, 10);
    if (num66 == -1) {
        printf("Passed test 67: Set a node with a invalid position in a list with multiple nodes\n");
    } else {
        printf("Failed test 67: Set a node with a invalid position in a list with multiple nodes\n");
    }

    // Test 68: getSubList() returns NULL when given an invalid start index
    LinkedList *list68 = createLinkedList();
    addLast(list68, 10);
    addLast(list68, 20);
    addLast(list68, 30);
    LinkedList *subList68 = getSubList(list68, -1, 2);
    if (subList68 == NULL) {
        printf("Passed test 68: getSubList() returns NULL when given an invalid start index\n");
    } else {
        printf("Failed test 68: getSubList() should return NULL when given an invalid start index\n");
    }
    destroyList(list68);
    if (subList68 != NULL) {
        destroyList(subList68);
    }

    //Test 69: getSubList() returns NULL when given an invalid stop index
    LinkedList *list69 = createLinkedList();
    addLast(list69, 10);
    addLast(list69, 20);
    addLast(list69, 30);
    LinkedList *subList69 = getSubList(list69, 1, 4);
    if (subList69 == NULL) {
        printf("Passed test 69: getSubList() returns NULL when given an invalid stop index\n");
    } else {
        printf("Failed test 69: getSubList() should return NULL when given an invalid stop index\n");
    }
    destroyList(list69);
    if (subList69 != NULL) {
        destroyList(subList69);
    }

    // Test 70: getSubList() returns NULL when given an invalid range
    LinkedList *list70 = createLinkedList();
    addLast(list70, 10);
    addLast(list70, 20);
    addLast(list70, 30);
    LinkedList *subList70 = getSubList(list70, 2, 1);
    if (subList70 == NULL) {
        printf("Passed test 70: getSubList() returns NULL when given an invalid range\n");
    } else {
        printf("Failed test 70: getSubList() should return NULL when given an invalid range\n");
    }
    destroyList(list70);
    if (subList70 != NULL) {
        destroyList(subList70);
    }

    // Test 71: getSubList() returns the correct sublist when given a valid range
    LinkedList *list71 = createLinkedList();
    addLast(list71, 10);
    addLast(list71, 20);
    addLast(list71, 30);
    LinkedList *subList71 = getSubList(list71, 1, 2);
    if (subList71 != NULL && subList71->size == 1 && subList71->first->data == 20) {
        printf("Passed test 71: getSubList() returns the correct sublist when given a valid range\n");
    } else {
        printf("Failed test 71: getSubList() should return the correct sublist when given a valid range\n");
    }
    destroyList(list71);
    if (subList71 != NULL) {
        destroyList(subList71);
    }

    // Test 72: getSubList() returns the entire list when given a valid range that covers the entire list
    LinkedList *list72 = createLinkedList();
    addLast(list72, 10);
    addLast(list72, 20);
    addLast(list72, 30);
    LinkedList *subList72 = getSubList(list72, 0, 3);
    if (subList72 != NULL && subList72->size == 3 && subList72->first->data == 10 && subList72->last->data == 30) {
        printf("Passed test 72: getSubList() returns the entire list when given a valid range that covers the entire list\n");
    } else {
        printf("Failed test 72: getSubList() should return the entire list when given a valid range that covers the entire list\n");
    }
    destroyList(list72);
    if (subList72 != NULL) {
        destroyList(subList72);
    }

    // Test 73: equals returns true for two empty lists
    LinkedList *list73_1 = createLinkedList();
    LinkedList *list73_2 = createLinkedList();
    if (equals(list73_1, list73_2)) {
        printf("Passed test 73: equals returns true for two empty lists\n");
    } else {
        printf("Failed test 73: equals returns true for two empty lists\n");
    }
    destroyList(list73_1);
    destroyList(list73_2);

    // Test 74: equals returns false for empty list and non-empty list
    LinkedList *list74_1 = createLinkedList();
    LinkedList *list74_2 = createLinkedList();
    addLast(list74_2, 5);
    if (!equals(list74_1, list74_2)) {
        printf("Passed test 74: equals returns false for empty list and non-empty list\n");
    } else {
        printf("Failed test 74: equals returns false for empty list and non-empty list\n");
    }
    destroyList(list74_1);
    destroyList(list74_2);

    // Test 75: equals returns true for two lists with the same elements in the same order
    LinkedList *list75_1 = createLinkedList();
    LinkedList *list75_2 = createLinkedList();
    addLast(list75_1, 5);
    addLast(list75_1, 7);
    addLast(list75_1, 8);
    addLast(list75_2, 5);
    addLast(list75_2, 7);
    addLast(list75_2, 8);
    if (equals(list75_1, list75_2)) {
        printf("Passed test 75: equals returns true for two lists with the same elements in the same order\n");
    } else {
        printf("Failed test 75: equals returns true for two lists with the same elements in the same order\n");
    }
    destroyList(list75_1);
    destroyList(list75_2);

    // Test 76: equals returns false for two lists with the same elements in a different order
    LinkedList *list76_1 = createLinkedList();
    LinkedList *list76_2 = createLinkedList();
    addLast(list76_1, 5);
    addLast(list76_1, 7);
    addLast(list76_1, 8);
    addLast(list76_2, 5);
    addLast(list76_2, 8);
    addLast(list76_2, 7);
    if (!equals(list76_1, list76_2)) {
        printf("Passed test 76: equals returns false for two lists with the same elements in a different order\n");
    } else {
        printf("Failed test 76: equals returns false for two lists with the same elements in a different order\n");
    }
    destroyList(list76_1);
    destroyList(list76_2);

    // Test 77: equals returns false for two lists with different elements
    LinkedList *list77_1 = createLinkedList();
    LinkedList *list77_2 = createLinkedList();
    addLast(list77_1, 5);
    addLast(list77_1, 7);
    addLast(list77_1, 8);
    addLast(list77_2, 5);
    addLast(list77_2, 7);
    addLast(list77_2, 9);
    if (!equals(list77_1, list77_2)) {
        printf("Passed test 77: equals returns false for two lists with different elements.\n");
    } else {
        printf("Failed test 77: equals returns true for two lists with different elements.\n");
    }
    destroyList(list77_1);
    destroyList(list77_2);

    // Test 78: makeEmpty on empty list
    LinkedList *list78 = createLinkedList();
    makeEmpty(list78);
    if (list78->first == NULL && list78->last == NULL && list78->size == 0) {
        printf("Passed test 78: makeEmpty on empty list\n");
    } else {
        printf("Failed test 78: makeEmpty on empty list\n");
    }
    destroyList(list78);

    // Test 79: makeEmpty on list with one element
    LinkedList *list79 = createLinkedList();
    addLast(list79, 5);
    makeEmpty(list79);
    if (list79->first == NULL && list79->last == NULL && list79->size == 0) {
        printf("Passed test 79: makeEmpty on list with one element\n");
    } else {
        printf("Failed test 79: makeEmpty on list with one element\n");
    }
    destroyList(list79);

    // Test 80: makeEmpty on list with multiple elements
    LinkedList *list80 = createLinkedList();
    addLast(list80, 5);
    addLast(list80, 7);
    addLast(list80, 8);
    makeEmpty(list80);
    if (list80->first == NULL && list80->last == NULL && list80->size == 0) {
        printf("Passed test 80: makeEmpty on list with multiple elements\n");
    } else {
        printf("Failed test 80: makeEmpty on list with multiple elements\n");
    }
    destroyList(list80);

    // Test 81: Removing a range that includes the first element but not the last
    LinkedList *list81 = createLinkedList();
    int nums81[] = {5, 7, 8, 10, 12};
    populateList(list81, nums81, 5);
    removeRange(list81, 0, 2);
    int expectedSize81 = 3;
    int expectedFirst81 = 8;
    int expectedLast81 = 12;
    if (list81->first->data == expectedFirst81 && list81->last->data == expectedLast81 && list81->size == expectedSize81) {
        printf("Passed test 81: Removing a range that includes the first element but not the last\n");
    } else {
        printf("Failed test 81: Removing a range that includes the first element but not the last\n");
    }
    destroyList(list81);

    // Test 82: Removing a range that includes the last element but not the first
    LinkedList *list82 = createLinkedList();
    int nums82[] = {5, 7, 8, 10, 12};
    populateList(list82, nums82, 5);
    removeRange(list82, 2, 5);
    int expectedSize82 = 2;
    int expectedFirst82 = 5;
    int expectedLast82 = 7;
    if (list82->first->data == expectedFirst82 && list82->last->data == expectedLast82 && list82->size == expectedSize82) {
        printf("Passed test 82: Removing a range that includes the last element but not the first\n");
    } else {
        printf("Failed test 82: Removing a range that includes the last element but not the first\n");
    }
    destroyList(list82);

    // Test 83: Removing a range in the middle
    LinkedList *list83 = createLinkedList();
    int nums83[] = {5, 7, 8, 10, 12};
    populateList(list83, nums83, 5);
    removeRange(list83, 1, 4);
    int expectedSize83 = 2;
    int expectedFirst83 = 5;
    int expectedLast83 = 12;
    if (list83->first->data == expectedFirst83 && list83->last->data == expectedLast83 && list83->size == expectedSize83) {
        printf("Passed test 83: Removing a range in the middle\n");
    } else {
        printf("Failed test 83: Removing a range in the middle\n");
    }
    destroyList(list83);

    // Test 84: Removing the entire range
    LinkedList *list84 = createLinkedList();
    int nums84[] = {5, 7, 8, 10, 12};
    populateList(list84, nums84, 5);
    removeRange(list84, 0, 5);
    int expectedSize84 = 0;
    if (list84->first == NULL && list84->last == NULL && list84->size == expectedSize84) {
        printf("Passed test 84: Removing the entire range\n");
    } else {
        printf("Failed test 84: Removing the entire range\n");
    }
    destroyList(list84);

    // Test 86: Removing only the first element
    LinkedList *list86 = createLinkedList();
    int nums86[] = {5, 7, 8, 10, 12};
    populateList(list86, nums86, 5);
    removeRange(list86, 0, 1);
    int expectedSize86 = 4;
    int expectedFirst86 = 7;
    int expectedLast86 = 12;
    if (list86->first->data == expectedFirst86 && list86->last->data == expectedLast86 && list86->size == expectedSize86) {
        printf("Passed test 86: Removing only the first element\n");
    } else {
        printf("Failed test 86: Removing only the first element\n");
    }
    destroyList(list86);

    // Test 87: Removing only the last element
    LinkedList *list87 = createLinkedList();
    int nums87[] = {5, 7, 8, 10, 12};
    populateList(list87, nums87, 5);
    removeRange(list87, 4, 5);
    int expectedSize87 = 4;
    int expectedFirst87 = 5;
    int expectedLast87 = 10;
    if (list87->first->data == expectedFirst87 && list87->last->data == expectedLast87 && list87->size == expectedSize87) {
        printf("Passed test 87: Removing only the last element\n");
    } else {
        printf("Failed test 87: Removing only the last element\n");
    }
    destroyList(list87);

    // Test 88: Removing only the middle element
    LinkedList *list88 = createLinkedList();
    int nums88[] = {5, 7, 8, 10, 12};
    populateList(list88, nums88, 5);
    removeRange(list88, 2, 3);
    int expectedSize88 = 4;
    int expectedFirst88 = 5;
    int expectedLast88 = 12;
    if (list88->first->data == expectedFirst88 && list88->last->data == expectedLast88 && list88->size == expectedSize88) {
        printf("Passed test 88: Removing only the middle element\n");
    } else {
        printf("Failed test 88: Removing only the middle element\n");
    }
    destroyList(list88);
    
    // Test 85: Removing a range with invalid start and stop values
    LinkedList *list85 = createLinkedList();
    int nums85[] = {5, 7, 8, 10, 12};
    populateList(list85, nums85, 5);
    removeRange(list85, -2, 7); // Invalid start and stop values
    int expectedSize85 = 5;
    int expectedFirst85 = 5;
    int expectedLast85 = 12;
    if (list85->first->data == expectedFirst85 && list85->last->data == expectedLast85 && list85->size == expectedSize85) {
        printf("Passed test 85: Removing a range with invalid start and stop values\n");
    } else {
        printf("Failed test 85: Removing a range with invalid start and stop values\n");
    }
    destroyList(list85);
}

void priorityQueueTests() {
    //Test 1: Creating an empty priority queue
    PriorityQueue *queue1 = createPriorityQueue();
    if (queue1 != NULL && queue1->con != NULL && queue1->con->first == NULL &&
        queue1->con->last == NULL && queue1->con->size == 0) {
        printf("Passed test 1: Creating an empty priority queue\n");
    } else {
        printf("Failed test 1: Creating an empty priority queue\n");
    }
    destroyPriorityQueue(queue1);

    //Test 2: Enqueue a single element
    PriorityQueue *queue2 = createPriorityQueue();
    enqueue(queue2, 5);
    if (queue2 != NULL && queue2->con != NULL && queue2->con->first != NULL &&
        queue2->con->first->data == 5 && queue2->con->last->data == 5 &&
        queue2->con->size == 1) {
        printf("Passed test 2: Enqueue a single element\n");
    } else {
        printf("Failed test 2: Enqueue a single element\n");
    }
    destroyPriorityQueue(queue2);

    //Test 3: Enqueue elements in ascending order
    PriorityQueue *queue3 = createPriorityQueue();
    enqueue(queue3, 3);
    enqueue(queue3, 5);
    enqueue(queue3, 7);
    if (queue3 != NULL && queue3->con != NULL && queue3->con->first != NULL &&
        queue3->con->first->data == 3 && queue3->con->last->data == 7 &&
        queue3->con->size == 3) {
        printf("Passed test 3: Enqueue elements in ascending order\n");
    } else {
        printf("Failed test 3: Enqueue elements in ascending order\n");
    }
    destroyPriorityQueue(queue3);

    //Test 4: Enqueue elements in descending order
    PriorityQueue *queue4 = createPriorityQueue();
    enqueue(queue4, 7);
    enqueue(queue4, 5);
    enqueue(queue4, 3);
    if (queue4 != NULL && queue4->con != NULL && queue4->con->first != NULL &&
        queue4->con->first->data == 3 && queue4->con->last->data == 7 &&
        queue4->con->size == 3) {
        printf("Passed test 4: Enqueue elements in descending order\n");
    } else {
        printf("Failed test 4: Enqueue elements in descending order\n");
    }
    destroyPriorityQueue(queue4);

    //Test 5: Enqueue elements with the same value
    PriorityQueue *queue5 = createPriorityQueue();
    enqueue(queue5, 5);
    enqueue(queue5, 5);
    enqueue(queue5, 5);
    if (queue5 != NULL && queue5->con != NULL && queue5->con->first != NULL &&
        queue5->con->first->data == 5 && queue5->con->last->data == 5 &&
        queue5->con->size == 3) {
        printf("Passed test 5: Enqueue elements with the same value\n");
    } else {
        printf("Failed test 5: Enqueue elements with the same value\n");
    }
    destroyPriorityQueue(queue5);

    //Test 6: Enqueue elements in a mix of order and same values
    PriorityQueue *queue6 = createPriorityQueue();
    enqueue(queue6, 7);
    enqueue(queue6, 5);
    enqueue(queue6, 9);
    enqueue(queue6, 3);
    enqueue(queue6, 5);
    if (queue6 != NULL && queue6->con != NULL && queue6->con->first != NULL &&
        queue6->con->first->data == 3 && queue6->con->last->data == 9 &&
        queue6->con->size == 5) {
        printf("Passed test 6: Enqueue elements in a mix of order and same values\n");
    } else {
        printf("Failed test 6: Enqueue elements in a mix of order and same values\n");
    }
    destroyPriorityQueue(queue6);

    //Test 7: Dequeue from an empty priority queue
    PriorityQueue *queue7 = createPriorityQueue();
    int dequeuedValue7 = dequeue(queue7);
    if (dequeuedValue7 == -1) {
        printf("Passed test 7: Dequeue from an empty priority queue\n");
    } else {
        printf("Failed test 7: Dequeue from an empty priority queue\n");
    }
    destroyPriorityQueue(queue7);

    //Test 8: Dequeue a single element
    PriorityQueue *queue8 = createPriorityQueue();
    enqueue(queue8, 5);
    int dequeuedValue8 = dequeue(queue8);
    if (dequeuedValue8 == 5 && queue8->con->first == NULL && queue8->con->last == NULL && queue8->con->size == 0) {
        printf("Passed test 8: Dequeue a single element\n");
    } else {
        printf("Failed test 8: Dequeue a single element\n");
    }
    destroyPriorityQueue(queue8);

    //Test 9: Dequeue multiple elements in correct order
    PriorityQueue *queue9 = createPriorityQueue();
    enqueue(queue9, 3);
    enqueue(queue9, 7);
    enqueue(queue9, 5);
    int dequeuedValue9_1 = dequeue(queue9);
    int dequeuedValue9_2 = dequeue(queue9);
    int dequeuedValue9_3 = dequeue(queue9);
    if (dequeuedValue9_1 == 3 && dequeuedValue9_2 == 5 && dequeuedValue9_3 == 7) {
        printf("Passed test 9: Dequeue multiple elements in correct order\n");
    } else {
        printf("Failed test 9: Dequeue multiple elements in correct order\n");
    }
    destroyPriorityQueue(queue9);

    //Test 10: Dequeue elements with same value
    PriorityQueue *queue10 = createPriorityQueue();
    enqueue(queue10, 5);
    enqueue(queue10, 5);
    enqueue(queue10, 5);
    int dequeuedValue10_1 = dequeue(queue10);
    int dequeuedValue10_2 = dequeue(queue10);
    int dequeuedValue10_3 = dequeue(queue10);
    if (dequeuedValue10_1 == 5 && dequeuedValue10_2 == 5 && dequeuedValue10_3 == 5) {
        printf("Passed test 10: Dequeue elements with same value\n");
    } else {
        printf("Failed test 10: Dequeue elements with same value\n");
    }
    destroyPriorityQueue(queue10);

    //Test 11: Dequeue elements in a mix of order and same values
    PriorityQueue *queue11 = createPriorityQueue();
    enqueue(queue11, 9);
    enqueue(queue11, 5);
    enqueue(queue11, 3);
    enqueue(queue11, 7);
    enqueue(queue11, 5);
    int dequeuedValue11_1 = dequeue(queue11);
    int dequeuedValue11_2 = dequeue(queue11);
    int dequeuedValue11_3 = dequeue(queue11);
    int dequeuedValue11_4 = dequeue(queue11);
    int dequeuedValue11_5 = dequeue(queue11);
    if (dequeuedValue11_1 == 3 && dequeuedValue11_2 == 5 && dequeuedValue11_3 == 5 && dequeuedValue11_4 == 7 && dequeuedValue11_5 == 9) {
        printf("Passed test 11: Dequeue elements in a mix of order and same values\n");
    } else {
        printf("Failed test 11: Dequeue elements in a mix of order and same values\n");
    }
    destroyPriorityQueue(queue11);

    //Test 12: Peek at an empty priority queue
    PriorityQueue *queue12 = createPriorityQueue();
    int peekValue12 = peek(queue12);
    if (peekValue12 == -1) {
        printf("Passed test 12: Peek at an empty priority queue\n");
    } else {
        printf("Failed test 12: Peek at an empty priority queue\n");
    }
    destroyPriorityQueue(queue12);

    //Test 13: Peek at a priority queue with a single element
    PriorityQueue *queue13 = createPriorityQueue();
    enqueue(queue13, 5);
    int peekValue13 = peek(queue13);
    if (peekValue13 == 5) {
        printf("Passed test 13: Peek at a priority queue with a single element\n");
    } else {
        printf("Failed test 13: Peek at a priority queue with a single element\n");
    }
    destroyPriorityQueue(queue13);

    //Test 14: Peek at a priority queue with multiple elements
    PriorityQueue *queue14 = createPriorityQueue();
    enqueue(queue14, 3);
    enqueue(queue14, 7);
    enqueue(queue14, 5);
    int peekValue14 = peek(queue14);
    if (peekValue14 == 3) {
        printf("Passed test 14: Peek at a priority queue with multiple elements\n");
    } else {
        printf("Failed test 14: Peek at a priority queue with multiple elements\n");
    }
    destroyPriorityQueue(queue14);

    //Test 15: Peek at a priority queue with elements of the same value
    PriorityQueue *queue15 = createPriorityQueue();
    enqueue(queue15, 5);
    enqueue(queue15, 5);
    enqueue(queue15, 5);
    int peekValue15 = peek(queue15);
    if (peekValue15 == 5) {
        printf("Passed test 15: Peek at a priority queue with elements of the same value\n");
    } else {
        printf("Failed test 15: Peek at a priority queue with elements of the same value\n");
    }
    destroyPriorityQueue(queue15);

    //Test 16: Peek at a priority queue with a mix of order and same values
    PriorityQueue *queue16 = createPriorityQueue();
    enqueue(queue16, 9);
    enqueue(queue16, 5);
    enqueue(queue16, 3);
    enqueue(queue16, 7);
    enqueue(queue16, 5);
    int peekValue16 = peek(queue16);
    if (peekValue16 == 3) {
        printf("Passed test 16: Peek at a priority queue with a mix of order and same values\n");
    } else {
        printf("Failed test 16: Peek at a priority queue with a mix of order and same values\n");
    }
    destroyPriorityQueue(queue16);

    //Test 17: Check if an empty priority queue is empty
    PriorityQueue *queue17 = createPriorityQueue();
    bool emptyResult17 = isEmpty(queue17);
    if (emptyResult17) {
        printf("Passed test 17: Check if an empty priority queue is empty\n");
    } else {
        printf("Failed test 17: Check if an empty priority queue is empty\n");
    }
    destroyPriorityQueue(queue17);

    //Test 18: Check if a priority queue with a single element is empty
    PriorityQueue *queue18 = createPriorityQueue();
    enqueue(queue18, 5);
    bool emptyResult18 = isEmpty(queue18);
    if (!emptyResult18) {
        printf("Passed test 18: Check if a priority queue with a single element is empty\n");
    } else {
        printf("Failed test 18: Check if a priority queue with a single element is empty\n");
    }
    destroyPriorityQueue(queue18);

    //Test 19: Check if a priority queue with multiple elements is empty
    PriorityQueue *queue19 = createPriorityQueue();
    enqueue(queue19, 3);
    enqueue(queue19, 7);
    enqueue(queue19, 5);
    bool emptyResult19 = isEmpty(queue19);
    if (!emptyResult19) {
        printf("Passed test 19: Check if a priority queue with multiple elements is empty\n");
    } else {
        printf("Failed test 19: Check if a priority queue with multiple elements is empty\n");
    }
    destroyPriorityQueue(queue19);

    //Test 20: Check if a priority queue becomes empty after dequeueing all elements
    PriorityQueue *queue20 = createPriorityQueue();
    enqueue(queue20, 3);
    enqueue(queue20, 7);
    enqueue(queue20, 5);
    dequeue(queue20);
    dequeue(queue20);
    dequeue(queue20);
    bool emptyResult20 = isEmpty(queue20);
    if (emptyResult20) {
        printf("Passed test 20: Check if a priority queue becomes empty after dequeueing all elements\n");
    } else {
        printf("Failed test 20: Check if a priority queue becomes empty after dequeueing all elements\n");
    }
    destroyPriorityQueue(queue20);

    //Test 21: Check the size of an empty priority queue
    PriorityQueue *queue21 = createPriorityQueue();
    int sizeResult21 = size(queue21);
    if (sizeResult21 == 0) {
        printf("Passed test 21: Check the size of an empty priority queue\n");
    } else {
        printf("Failed test 21: Check the size of an empty priority queue\n");
    }
    destroyPriorityQueue(queue21);

    //Test 22: Check the size of a priority queue with a single element
    PriorityQueue *queue22 = createPriorityQueue();
    enqueue(queue22, 5);
    int sizeResult22 = size(queue22);
    if (sizeResult22 == 1) {
        printf("Passed test 22: Check the size of a priority queue with a single element\n");
    } else {
        printf("Failed test 22: Check the size of a priority queue with a single element\n");
    }
    destroyPriorityQueue(queue22);

    //Test 23: Check the size of a priority queue with multiple elements
    PriorityQueue *queue23 = createPriorityQueue();
    enqueue(queue23, 3);
    enqueue(queue23, 5);
    enqueue(queue23, 7);
    int sizeResult23 = size(queue23);
    if (sizeResult23 == 3) {
        printf("Passed test 23: Check the size of a priority queue with multiple elements\n");
    } else {
        printf("Failed test 23: Check the size of a priority queue with multiple elements\n");
    }
    destroyPriorityQueue(queue23);

    //Test 24: Check the size of a priority queue after dequeueing some elements
    PriorityQueue *queue24 = createPriorityQueue();
    enqueue(queue24, 3);
    enqueue(queue24, 5);
    enqueue(queue24, 7);
    dequeue(queue24);
    int sizeResult24 = size(queue24);
    if (sizeResult24 == 2) {
        printf("Passed test 24: Check the size of a priority queue after dequeueing some elements\n");
    } else {
        printf("Failed test 24: Check the size of a priority queue after dequeueing some elements\n");
    }
    destroyPriorityQueue(queue24);

}

void huffmanTreeNodeTests() {
    // Test 1: Creating a new Huffman tree node
    HuffmanTreeNode *node1 = createHuffmanTreeNode();
    if (node1 != NULL) {
        printf("Passed test 1: createHuffmanTreeNode() returns a non-null pointer\n");
    } else {
        printf("Failed test 1: createHuffmanTreeNode() returns a null pointer\n");
    }

    // Test 2: The newly created node should have val set to 0
    if (node1->val == 0) {
        printf("Passed test 2: createHuffmanTreeNode() initializes val to 0\n");
    } else {
        printf("Failed test 2: createHuffmanTreeNode() does not initialize val to 0\n");
    }

    // Test 3: The newly created node should have freq set to 0
    if (node1->freq == 0) {
        printf("Passed test 3: createHuffmanTreeNode() initializes freq to 0\n");
    } else {
        printf("Failed test 3: createHuffmanTreeNode() does not initialize freq to 0\n");
    }

    // Test 4: The newly created node should have left and right child pointers set to NULL
    if (node1->left == NULL && node1->right == NULL) {
        printf("Passed test 4: createHuffmanTreeNode() initializes left and right pointers to NULL\n");
    } else {
        printf("Failed test 4: createHuffmanTreeNode() does not initialize left and right pointers to NULL\n");
    }

    // Free the memory allocated for the node
    free(node1);

    // Test 5: Compare two nodes with equal frequencies
    HuffmanTreeNode *node5 = createHuffmanTreeNode();
    HuffmanTreeNode *node6 = createHuffmanTreeNode();
    node5->freq = 5;
    node6->freq = 5;
    if (compareTo(node5, node6) == 0) {
        printf("Passed test 5: compareTo() returns 0 when two nodes have equal frequencies\n");
    } else {
        printf("Failed test 5: compareTo() doesn't return 0 when two nodes have equal frequencies\n");
    }
    free(node5);
    free(node6);

    // Test 6: Compare two nodes where the first node has a higher frequency
    HuffmanTreeNode *node7 = createHuffmanTreeNode();
    HuffmanTreeNode *node8 = createHuffmanTreeNode();
    node7->freq = 10;
    node8->freq = 5;
    if (compareTo(node7, node8) > 0) {
        printf("Passed test 6: compareTo() returns a positive value when the first node has a higher frequency\n");
    } else {
        printf("Failed test 6: compareTo() doesn't return a positive value when the first node has a higher frequency\n");
    }
    free(node7);
    free(node8);

    // Test 7: Compare two nodes where the first node has a lower frequency
    HuffmanTreeNode *node9 = createHuffmanTreeNode();
    HuffmanTreeNode *node10 = createHuffmanTreeNode();
    node9->freq = 3;
    node10->freq = 7;
    if (compareTo(node9, node10) < 0) {
        printf("Passed test 7: compareTo() returns a negative value when the first node has a lower frequency\n");
    } else {
        printf("Failed test 7: compareTo() doesn't return a negative value when the first node has a lower frequency\n");
    }
    free(node9);
    free(node10);

    // Test 8: Check if a newly created node is a leaf node
    HuffmanTreeNode *node11 = createHuffmanTreeNode();
    if (isLeafNode(node11)) {
        printf("Passed test 8: isLeafNode() returns true for a newly created node\n");
    } else {
        printf("Failed test 8: isLeafNode() doesn't return true for a newly created node\n");
    }
    free(node11);

    // Test 9: Check if a node with only a left child is not a leaf node
    HuffmanTreeNode *node12 = createHuffmanTreeNode();
    HuffmanTreeNode *node13 = createHuffmanTreeNode();
    node12->left = node13;
    if (!isLeafNode(node12)) {
        printf("Passed test 9: isLeafNode() returns false for a node with only a left child\n");
    } else {
        printf("Failed test 9: isLeafNode() doesn't return false for a node with only a left child\n");
    }
    free(node12);
    free(node13);

    // Test 10: Check if a node with only a right child is not a leaf node
    HuffmanTreeNode *node14 = createHuffmanTreeNode();
    HuffmanTreeNode *node15 = createHuffmanTreeNode();
    node14->right = node15;
    if (!isLeafNode(node14)) {
        printf("Passed test 10: isLeafNode() returns false for a node with only a right child\n");
    } else {
        printf("Failed test 10: isLeafNode() doesn't return false for a node with only a right child\n");
    }
    free(node14);
    free(node15);

    // Test 11: Check if a node with both left and right children is not a leaf node
    HuffmanTreeNode *node16 = createHuffmanTreeNode();
    HuffmanTreeNode *node17 = createHuffmanTreeNode();
    HuffmanTreeNode *node18 = createHuffmanTreeNode();
    node16->left = node17;
    node16->right = node18;
    if (!isLeafNode(node16)) {
        printf("Passed test 11: isLeafNode() returns false for a node with both left and right children\n");
    } else {
        printf("Failed test 11: isLeafNode() doesn't return false for a node with both left and right children\n");
    }
    free(node16);
    free(node17);
    free(node18);

}