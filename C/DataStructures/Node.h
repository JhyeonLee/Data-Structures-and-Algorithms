 #pragma once
// #ifdef __NODE_H__
// #define __NODE_H__
#include<stdlib.h>
#include "../utils/utils.h"

typedef struct Node {
    int key;
    int element;
} Node;

Node* getnode() {
    Node* newnode = (Node*)malloc(sizeof(Node));
    if (newnode == NULL){
        notEnoughMemory();
        return NULL;
    }
    newnode->key = 0;
    newnode->element = 0;    
    return newnode;
}

void Node_putnode(Node* node) {
    free(node);
}

// #endif