#pragma once
// #ifdef __SEQUENTIALQUEUE_H__
// #define __SEQUENTIALQUEUE_H__
#include<stdlib.h>
#include "../utils/utils.h"

typedef struct SequentialQueue { // 원형 큐(Circular Queue)
    int* elements;
    int acceptableSize;
    int front;
    int rear;
} SequentialQueue;

int SequentialQueue_isEmpty(SequentialQueue* Q) {
    return (Q->rear + 1) % Q->acceptableSize == Q->front;
}

int SequentialQueue_isFull(SequentialQueue* Q) {
    return (Q->rear + 2) % Q->acceptableSize == Q->front;
}

SequentialQueue* SequentialQueue_initialize(int n) {
    SequentialQueue* queue = (SequentialQueue*)malloc(sizeof(SequentialQueue));
    if (queue == NULL) {
        notEnoughMemory();
        return NULL;
    }
    queue->elements = (int*)malloc(n * sizeof(int));
    if (queue->elements == NULL) {
        notEnoughMemory();
        return NULL;
    }
    queue->acceptableSize = n;
    queue->front = 0;
    queue->rear = n - 1;
    return queue;
}

void SequentialQueue_enqueue(SequentialQueue* Q, int e) {
    if (SequentialQueue_isFull(Q)) {
        fullQueueException();
        return;
    }
    Q->rear = (Q->rear + 1) % Q->acceptableSize;
    Q->elements[Q->rear] = e;
}

int SequentialQueue_dequeue(SequentialQueue* Q) {
    if (SequentialQueue_isEmpty(Q)) {
        return emptyQueueException();        
    }
    int e = Q->elements[Q->front];
    Q->front = (Q->front + 1) % Q->acceptableSize;
    return e;
}

int SequentialQueue_size(SequentialQueue* Q) {
    return (Q->acceptableSize - Q->front + Q->rear + 1) % Q->acceptableSize;
}

int SequentialQueue_front(SequentialQueue* Q) {
    if (SequentialQueue_isEmpty(Q)) {
        return emptyQueueException();
    }
    return Q->elements[Q->front];
}

// #endif