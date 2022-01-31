#pragma once
// #ifdef __SEQUENTIALDEQUEUE_H__
// #define __SEQUENTIALDEQUEUE_H__
#include <stdlib.h>
#include "../utils/utils.h"

typedef struct SequentialDeque { // 원형 데크(Circular Deque)
    int* elements;
    int acceptableSize;
    int front;
    int rear;
} SequentialDeque;


int SequentialDeque_isEmpty(SequentialDeque* Dq) {
    return (Dq->rear + 1) % Dq->acceptableSize == Dq->front;
}

int SequentialDeque_isFull(SequentialDeque* Dq) {
    return (Dq->rear + 2) % Dq->acceptableSize == Dq->front;
}

SequentialDeque* SequentialDeque_initialize(int n) {
    SequentialDeque* queue = (SequentialDeque*)malloc(sizeof(SequentialDeque));
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

// front 위치에 원소 e 삽입
void SequentialDeque_push(SequentialDeque* Dq, int e) {
    if (SequentialDeque_isFull(Dq)) {
        fullDequeException();
        return;
    }
    Dq->front = (Dq->acceptableSize + Dq->front - 1) % Dq->acceptableSize;
    Dq->elements[Dq->front] = e;
}

// front 위치의 원소를 삭제하여 반환
int SequentialDeque_pop(SequentialDeque* Dq) {
    if (SequentialDeque_isEmpty(Dq)) {
        return emptyDequeException();        
    }
    int e = Dq->elements[Dq->front];
    Dq->front = (Dq->front + 1) % Dq->acceptableSize;
    return e;
}

// rear 위치에 원소 e를 삽입
void SequentialDeque_inject(SequentialDeque* Dq, int e) {
    if (SequentialDeque_isFull(Dq)) {
        fullDequeException();
        return;
    }
    Dq->rear = (Dq->rear + 1) % Dq->acceptableSize;
    Dq->elements[Dq->rear] = e;
}

// rear 위치에 원소를 삭제하여 반환
int SequentialDeque_eject(SequentialDeque* Dq) {
    if (SequentialDeque_isEmpty(Dq)) {
        return emptyDequeException();        
    }
    int e = Dq->elements[Dq->rear];
    Dq->rear = (Dq->acceptableSize + Dq->rear - 1) % Dq->acceptableSize;
    return e;
}

int SequentialDeque_size(SequentialDeque* Dq) {
    return (Dq->acceptableSize - Dq->front + Dq->rear + 1) % Dq->acceptableSize;
}

int SequentialDeque_front(SequentialDeque* Dq) {
    if (SequentialDeque_isEmpty(Dq)) {
        return emptyDequeException();
    }
    return Dq->elements[Dq->front];
}

int SequentialDeque_rear(SequentialDeque* Dq) {
    if (SequentialDeque_isEmpty(Dq)) {
        return emptyDequeException();
    }
    return Dq->elements[Dq->rear];
}

// #endif