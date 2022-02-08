#pragma once
// #ifdef __LINKEDPriorityQueue_H__
// #define __LINKEDPriorityQueue_H__
#include<stdlib.h>
#include "../utils/utils.h"
#include "./SinglyLinkedNode.h"

typedef struct LinkedPriorityQueue {
    SinglyLinkedNode* front;
    SinglyLinkedNode* rear;
} LinkedPriorityQueue;

LinkedPriorityQueue* LinkedPriorityQueue_initialize() {
    LinkedPriorityQueue* priorityqueue = (LinkedPriorityQueue*)malloc(sizeof(LinkedPriorityQueue));
    if (priorityqueue == NULL) {
        notEnoughMemory();
        return NULL;
    }
    priorityqueue->front = NULL;
    priorityqueue->rear = NULL;
    return priorityqueue;
}

int LinkedPriorityQueue_isEmpty(LinkedPriorityQueue* Pq) {
    return Pq->front == NULL;
}
int LinkedPriorityQueue_size(LinkedPriorityQueue* Pq) {
    int count = 0;
    SinglyLinkedNode* p = Pq->front;
    while(p != NULL) {
        count++;
        p = p->link;
    }
    return count;
}
void LinkedPriorityQueue_swap(SinglyLinkedNode* A, SinglyLinkedNode* B) {
    int k = A->key;
    A->key = B->key;
    B->key = k;

    int e = A->element;
    A->element = B->element;
    B->element = e;
}

void LinkedPriorityQueue_insertItem(LinkedPriorityQueue* Pq, int k, int e) {
    // if isFull() { fullQueueException(); return; }

    SinglyLinkedNode* newnode = SinglyLinkedNode_getnode();
    if (newnode == NULL) {
        return;
    }
    newnode->element = k;
    newnode->element = e;
    newnode->link = NULL;
    if (LinkedPriorityQueue_isEmpty(Pq)) {
        Pq->front = newnode;
        Pq->rear = newnode;
    } else {
        (Pq->rear)->link = newnode;
        Pq->rear = newnode;
    }
}

SinglyLinkedNode* LinkedPriorityQueue_findMin(LinkedPriorityQueue* Pq) {
    if (LinkedPriorityQueue_isEmpty(Pq)) {
        emptyQueueException();
        return NULL;
    }

    SinglyLinkedNode* min = Pq->front;
    SinglyLinkedNode* p = (Pq->front)->link;
    for( ; p != NULL; p = p->link) {
        if (p->key < min->key) {
            min = p;
        }
    }
    return min;
}

SinglyLinkedNode* LinkedPriorityQueue_removeMin(LinkedPriorityQueue* Pq) {
    if (LinkedPriorityQueue_isEmpty(Pq)) {
        emptyQueueException();
        return NULL;
    }

    SinglyLinkedNode* min = LinkedPriorityQueue_findMin(Pq);
    if (min == NULL) {
        return;
    }
    LinkedPriorityQueue_swap(Pq->front, min);
    min = Pq->front;
    Pq->front = (Pq->front)->link;
    if (Pq->front == NULL) {
        Pq->rear = NULL;
    }
    min->link = NULL;
    return min;
}

int LinkedPriorityQueue_minElement(LinkedPriorityQueue* Pq) {
    if (LinkedPriorityQueue_isEmpty(Pq)) {
        emptyQueueException();
        return NULL;
    }
    SinglyLinkedNode* min = LinkedPriorityQueue_findMin(Pq);
    if (min == NULL) {
        return;
    }
    return min->element;
}

int LinkedPriorityQueue_minKey(LinkedPriorityQueue* Pq) {
    if (LinkedPriorityQueue_isEmpty(Pq)) {
        emptyQueueException();
        return NULL;
    }
    SinglyLinkedNode* min = LinkedPriorityQueue_findMin(Pq);
    if (min == NULL) {
        return;
    }
    return min->key;
}

// #endif