#pragma once
// #ifdef __LINKEDDEQUE_H__
// #define __LINKEDDEQUE_H__
#include <stdlib.h>
#include "../utils/utils.h"
#include "./DoublyLinkedNode.h"

typedef struct LinkedDeque {
    DoublyLinkedNode* front;
    DoublyLinkedNode* rear;
} LinkedDeque;

LinkedDeque* LinkedDeque_initialize() {
    LinkedDeque* queue = (LinkedDeque*)malloc(sizeof(LinkedDeque));
    if (queue == NULL) {
        notEnoughMemory();
        return NULL;        
    }
    queue->front = NULL;
    queue->rear = NULL;
}

int LinkedDeque_isEmpty(LinkedDeque* Q) {
    return Q->front == NULL;
}

// front 위치에 원소 e 삽입
void LinkedDeque_push(LinkedDeque* Q, int e) {
    DoublyLinkedNode* p = DoublyLinkedNode_getnode();
    if (p == NULL) {
        return;
    }
    p->element = e;
    p->nextlink = NULL;
    p->previouslink = NULL;

    if (LinkedDeque_isEmpty(Q)) {
        Q->front = p;
        Q->rear = p;
    } else {
        p->nextlink = Q->front;
        (Q->front)->previouslink = p;
        Q->front = p;
    }
}
// front 위치의 원소를 삭제하여 반환
int LinkedDeque_pop(LinkedDeque* Q) {
    if (LinkedDeque_isEmpty(Q)) {
        return emptyDequeException();
    }
    int e = (Q->front)->element;
    DoublyLinkedNode* p = Q->front;
    Q->front = (Q->front)->nextlink;
    if (Q->front == NULL) {
        Q->rear = NULL;
    } else {
        (Q->front)->previouslink = NULL;
    }
    DoublyLinkedNode_putnode(p);
    return e;
}
// rear 위치에 원소 e를 삽입
void LinkedDeque_inject(LinkedDeque* Q, int e) {
    DoublyLinkedNode* p = DoublyLinkedNode_getnode();
    if (p == NULL) {
        return;
    }
    p->element = e;
    p->nextlink = NULL;
    p->previouslink = NULL;

    if (LinkedDeque_isEmpty(Q)) {
        Q->front = p;
        Q->rear = p;
    } else {
        p->previouslink = Q->rear;
        (Q->rear)->nextlink = p;
        Q->rear = p;
    }
}
// rear 위치에 원소를 삭제하여 반환
int LinkedDeque_eject(LinkedDeque* Q) {
    if (LinkedDeque_isEmpty(Q)) {
        return emptyDequeException();
    }
    int e = (Q->rear)->element;
    DoublyLinkedNode* p = Q->rear;
    Q->rear = (Q->rear)->previouslink;
    if (Q->rear == NULL) {
        Q->front = NULL;
    } else {
        (Q->rear)->nextlink = NULL;
    }
    DoublyLinkedNode_putnode(p);
    return e;
}

// #endif