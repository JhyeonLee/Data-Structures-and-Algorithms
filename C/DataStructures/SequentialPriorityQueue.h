#pragma once
// #ifdef __SequentialPriorityQueue_H__
// #define __SequentialPriorityQueue_H__
#include<stdlib.h>
#include "../utils/utils.h"

#include "./ArrayList.h"

typedef struct SequentialPriorityQueue {
    int* keys;
    int* elements;
    int acceptableSize;
    int front;
    int rear;
} SequentialPriorityQueue;

SequentialPriorityQueue* SequentialPriorityQueue_initialize(int n) {
    SequentialPriorityQueue* priorityqueue = (SequentialPriorityQueue*)malloc(sizeof(SequentialPriorityQueue));
    if (priorityqueue == NULL) {
        notEnoughMemory();
        return NULL;
    }
    priorityqueue->keys = (int*)malloc(n * sizeof(int));
    if (priorityqueue->keys == NULL) {
        notEnoughMemory();
        return NULL;
    }
    priorityqueue->elements = (int*)malloc(n * sizeof(int));
    if (priorityqueue->elements == NULL) {
        notEnoughMemory();
        return NULL;
    }
    priorityqueue->acceptableSize = n;
    priorityqueue->front = 0;
    priorityqueue->rear = n - 1;
    return priorityqueue;
}

int SequentialPriorityQueue_isEmpty(SequentialPriorityQueue* Pq) {
    return (Pq->rear + 1) % Pq->acceptableSize == Pq->front;
}

int SequentialPriorityQueue_isFull(SequentialPriorityQueue* Pq) {
    return (Pq->rear + 2) % Pq->acceptableSize == Pq->front;
}

int SequentialPriorityQueue_size(SequentialPriorityQueue* Pq) {
    return (Pq->acceptableSize - Pq->front + Pq->rear + 1) % Pq->acceptableSize;
}

void SequentialPriorityQueue_swap(SequentialPriorityQueue* Pq, int A, int B) {
    int k = Pq->keys[A];
    Pq->keys[A] = Pq->keys[B];
    Pq->keys[B] = k;

    int e = Pq->elements[A];
    Pq->elements[A] = Pq->elements[B];
    Pq->elements[B] = k;
}

void SequentialPriorityQueue_insertItem(SequentialPriorityQueue* Pq, int k, int e) {
    if (SequentialPriorityQueue_isFull(Pq)) {
        fullQueueException();
        return;
    }
    Pq->rear = (Pq->rear + 1) % Pq->acceptableSize;
    Pq->keys[Pq->rear] = k;
    Pq->elements[Pq->rear] = e;
}

int SequentialPriorityQueue_findMin(SequentialPriorityQueue* Pq) {
    if (SequentialPriorityQueue_isEmpty(Pq)) {
        return emptyQueueException();        
    }

    int min = 0;
    for(int i = 0; i < SequentialPriorityQueue_size(Pq); i++) {
        if (Pq->elements[min] > Pq->elements[i]) {
            min = i;
        }
    }

    return min;
}

int SequentialPriorityQueue_removeMin(SequentialPriorityQueue* Pq) {
    if (SequentialPriorityQueue_isEmpty(Pq)) {
        return emptyQueueException();        
    }

    int min = SequentialPriorityQueue_findMin(Pq);
    int e = Pq->elements[min];
    SequentialPriorityQueue_swap(Pq, min, Pq->front);
    Pq->front = (Pq->front + 1) % Pq->acceptableSize;
    return e;
}

int SequentialPriorityQueue_minElement(SequentialPriorityQueue* Pq) {
    if (SequentialPriorityQueue_isEmpty(Pq)) {
        return emptyQueueException();        
    }
    int min = SequentialPriorityQueue_findMin(Pq);
    return Pq->elements[min];
}

int SequentialPriorityQueue_minKey(SequentialPriorityQueue* Pq) {
    if (SequentialPriorityQueue_isEmpty(Pq)) {
        return emptyQueueException();        
    }
    int min = SequentialPriorityQueue_findMin(Pq);
    return Pq->keys[min];
}

// #endif