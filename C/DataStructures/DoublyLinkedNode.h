#pragma once
// #ifdef __ARRAYLISTS_H_
// #define __ARRAYLISTS_H_
#include <stdio.h>
#include<stdlib.h>
#include "../utils/utils.h"

typedef struct DoublyLinkedNode {
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
    newnode->element = 0;
    newnode->nextlink = NULL;
    newnode->previouslink = NULL;
    return newnode;
}
DoublyLinkedNode* DoublyLinkedNode_putnode(DoublyLinkedNode* node) {
    free(node);
}

// #endif