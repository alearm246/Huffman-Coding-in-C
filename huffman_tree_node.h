#ifndef HUFFMANTREENODE_H
#define HUFFMANTREENODE_H

#include <stdbool.h>

typedef struct HuffmanTreeNode {
    int val;
    int freq;
    struct HuffmanTreeNode *left;
    struct HuffmanTreeNode *right;
} HuffmanTreeNode;

HuffmanTreeNode *createHuffmanTreeNode();
int compareTo(HuffmanTreeNode *node, HuffmanTreeNode *otherNode);
bool isLeafNode(HuffmanTreeNode *node);

#endif