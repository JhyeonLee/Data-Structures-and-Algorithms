#pragma once
// #ifdef __LINKEDQUEUE_H__
// #define __LINKEDQUEUE_H__
#include<stdlib.h>
#include "../utils/utils.h"
#include "./SinglyLinkedNode.h"

typedef struct LinkedQueue {
    SinglyLinkedNode* front;
    SinglyLinkedNode* rear;
} LinkedQueue;

typedef struct LinkedQueue_biT {
    SinglyLinkedNode_biT* front;
    SinglyLinkedNode_biT* rear;
} LinkedQueue_biT;

LinkedQueue* LinkedQueue_initialize() {
    LinkedQueue* queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    if (queue == NULL) {
        notEnoughMemory();
        return NULL;        
    }
    queue->front = NULL;
    queue->rear = NULL;
}

int LinkedQueue_isEmpty(LinkedQueue* Q) {
    return Q->front == NULL;
}

void LinkedQueue_enqueue(LinkedQueue* Q, int e) { // int k, int e
    SinglyLinkedNode* p = SinglyLinkedNode_getnode();
    if (p == NULL) {
        return;
    }
    // p->key = k
    p->element = e;
    p->link = NULL;
    if (LinkedQueue_isEmpty(Q)) {
        Q->front = p;
        Q->rear = p;
    } else {
        (Q->rear)->link = p;
        Q->rear = p;
    }
}

int LinkedQueue_dequeue(LinkedQueue* Q) {
    if (LinkedQueue_isEmpty(Q)) {
        return emptyQueueException();
    }
    int e = (Q->front)->element;
    SinglyLinkedNode* p = Q->front;
    Q->front = (Q->front)->link;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    SinglyLinkedNode_putnode(p);
    return e;
}


LinkedQueue_biT* LinkedQueue_biT_initialize() {
    LinkedQueue_biT* queue = (LinkedQueue_biT*)malloc(sizeof(LinkedQueue_biT));
    if (queue == NULL) {
        notEnoughMemory();
        return NULL;        
    }
    queue->front = NULL;
    queue->rear = NULL;
}

int LinkedQueue_biT_isEmpty(LinkedQueue_biT* Q) {
    return Q->front == NULL;
}

void LinkedQueue_biT_enqueue(LinkedQueue_biT* Q, LinkedBinaryTreeNode* node) {
    SinglyLinkedNode_biT* p = SinglyLinkedNode_biT_getnode();
    if (p == NULL) {
        return;
    }
    p->value = node;
    p->link = NULL;
    if (LinkedQueue_biT_isEmpty(Q)) {
        Q->front = p;
        Q->rear = p;
    } else {
        (Q->rear)->link = p;
        Q->rear = p;
    }
}

LinkedBinaryTreeNode* LinkedQueue_biT_dequeue(LinkedQueue_biT* Q) {
    if (LinkedQueue_biT_isEmpty(Q)) {
        emptyQueueException();
        return NULL;
    }
    LinkedBinaryTreeNode* e = (Q->front)->value;
    SinglyLinkedNode_biT* p = Q->front;
    Q->front = (Q->front)->link;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    SinglyLinkedNode_biT_putnode(p);
    return e;
}

// #endif