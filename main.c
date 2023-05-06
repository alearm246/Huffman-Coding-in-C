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
}