 #pragma once
// #ifdef __SINGLYLINKEDNODE_H__
// #define __SINGLYLINKEDNODE_H__
#include<stdlib.h>
#include "../utils/utils.h"
#include "./LinkedBinaryTreeNode.h"

typedef struct SinglyLinkedNode {
    int key;
    int element;
    struct SinglyLinkedNode* link;
} SinglyLinkedNode;

typedef struct SinglyLinkedNode_biT {
    LinkedBinaryTreeNode* value;
    struct SinglyLinkedNode_biT* link;
} SinglyLinkedNode_biT;

SinglyLinkedNode* SinglyLinkedNode_getnode() {
    SinglyLinkedNode* newnode = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
    if (newnode == NULL){
        notEnoughMemory();
        return NULL;
    }
    newnode->key = 0;
    newnode->element = 0;
    newnode->link = NULL;
    return newnode;
}
void SinglyLinkedNode_putnode(SinglyLinkedNode* node) {
    free(node);
}

SinglyLinkedNode_biT* SinglyLinkedNode_biT_getnode() {
    SinglyLinkedNode_biT* newnode = (SinglyLinkedNode_biT*)malloc(sizeof(SinglyLinkedNode_biT));
    if (newnode == NULL){
        notEnoughMemory();
        return NULL;
    }
    newnode->value = NULL;
    newnode->link = NULL;
    return newnode;
}
void SinglyLinkedNode_biT_putnode(SinglyLinkedNode_biT* node) {
    free(node);
}
// #endif