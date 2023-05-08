#include <stdio.h>
#include <stdlib.h>
#include "huffman_tree_node.h"

HuffmanTreeNode *createHuffmanTreeNode() {
    HuffmanTreeNode *node = (HuffmanTreeNode *) malloc(sizeof(HuffmanTreeNode));
    node->val = 0;
    node->freq = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int compareTo(HuffmanTreeNode *node, HuffmanTreeNode *otherNode) {
    return node->freq - otherNode->freq;
}

bool isLeafNode(HuffmanTreeNode *node) {
    return node->left == NULL && node->right == NULL;
}