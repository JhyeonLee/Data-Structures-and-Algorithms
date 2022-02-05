 #pragma once
// #ifdef __SEQUENTIALBINARYTREENODE_H__
// #define __SEQUENTIALBINARYTREENODE_H__
#include<stdlib.h>
#include "../utils/utils.h"

typedef struct SequentialBinaryTreeNode {
    int key;
    int element;
    int parent;
    int leftChild;
    int rightChild;
} SequentialBinaryTreeNode;

SequentialBinaryTreeNode* SequentialBinaryTreeNode_getNode() {
    SequentialBinaryTreeNode* newnode = (SequentialBinaryTreeNode*)malloc(sizeof(SequentialBinaryTreeNode));
    if (newnode == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newnode->key = 0;
    newnode->element = 0;
    newnode->parent = 0;
    newnode->leftChild = 0;
    newnode->rightChild = 0;
    return newnode;
}

void SequentialBinaryTreeNode_putnode(SequentialBinaryTreeNode* node) {
    free(node);
}

// #endif