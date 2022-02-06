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

void LinkedQueue_enqueue(LinkedQueue* Q, void* node) { // int k, int e
    SinglyLinkedNode* p = SinglyLinkedNode_getnode();
    if (p == NULL) {
        return;
    }
    // p->key = k;
    // p->element = e;
    p->element = node;
    p->link = NULL;
    if (LinkedQueue_isEmpty(Q)) {
        Q->front = p;
        Q->rear = p;
    } else {
        (Q->rear)->link = p;
        Q->rear = p;
    }
}

void* LinkedQueue_dequeue(LinkedQueue* Q) {
    if (LinkedQueue_isEmpty(Q)) {
        return emptyQueueException();
    }
    // int e = (Q->front)->element;
    void* e = (Q->front)->element;
    SinglyLinkedNode* p = Q->front;
    Q->front = (Q->front)->link;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    SinglyLinkedNode_putnode(p);
    return e;
}

// #endif