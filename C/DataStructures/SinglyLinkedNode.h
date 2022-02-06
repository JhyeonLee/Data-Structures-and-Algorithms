 #pragma once
// #ifdef __SINGLYLINKEDNODE_H__
// #define __SINGLYLINKEDNODE_H__
#include<stdlib.h>
#include "../utils/utils.h"
#include "./Node.h"

typedef struct SinglyLinkedNode {
    void* element;
    struct SinglyLinkedNode* link;
} SinglyLinkedNode;

SinglyLinkedNode* SinglyLinkedNode_getnode() {
    SinglyLinkedNode* newnode = (SinglyLinkedNode*)malloc(sizeof(SinglyLinkedNode));
    if (newnode == NULL){
        notEnoughMemory();
        return NULL;
    }
    newnode->element = NULL;
    newnode->link = NULL;
    return newnode;
}

void SinglyLinkedNode_putnode(SinglyLinkedNode* node) {
    free(node);
}
// #endif