#pragma once
// #ifdef __DOUBLYLINKENODE_H__
// #define __DOUBLYLINKENODE_H__
#include<stdlib.h>
#include "../utils/utils.h"

typedef struct DoublyLinkedNode {
    int key;
    int element;
    struct DoublyLinkedNode* nextlink;
    struct DoublyLinkedNode* previouslink;
} DoublyLinkedNode;

DoublyLinkedNode* DoublyLinkedNode_getnode() {
    DoublyLinkedNode* newnode = (DoublyLinkedNode*)malloc(sizeof(DoublyLinkedNode));
    if(newnode == NULL){
        notEnoughMemory();
        return NULL;
    }
    newnode->key = 0;
    newnode->element = 0;
    newnode->nextlink = NULL;
    newnode->previouslink = NULL;
    return newnode;
}
DoublyLinkedNode* DoublyLinkedNode_putnode(DoublyLinkedNode* node) {
    free(node);
}

// #endif