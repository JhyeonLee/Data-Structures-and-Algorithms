 #pragma once
// #ifdef __LINKEDBINARYTREENODE_H__
// #define __LINKEDBINARYTREENODE_H__
#include<stdlib.h>
#include "../utils/utils.h"

typedef struct LinkedBinaryTreeNode {
    int key;
    int element;
    struct LinkedBinaryTreeNode* parent;
    struct LinkedBinaryTreeNode* leftChild;
    struct LinkedBinaryTreeNode* rightChild;
} LinkedBinaryTreeNode;

LinkedBinaryTreeNode* LinkedBinaryTreeNode_getNode() {
    LinkedBinaryTreeNode* newnode = (LinkedBinaryTreeNode*)malloc(sizeof(LinkedBinaryTreeNode));
    if (newnode == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newnode->key = 0;
    newnode->element = 0;
    newnode->parent = NULL;
    newnode->leftChild = NULL;
    newnode->rightChild = NULL;
    return newnode;
}

void LinkedBinaryTreeNode_putNode(LinkedBinaryTreeNode* node) {
    free(node);
}

// #endif