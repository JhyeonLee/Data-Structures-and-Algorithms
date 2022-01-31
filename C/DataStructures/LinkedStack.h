#pragma once
// #ifdef __LINKEDSTACK_H__
// #define __LINKEDSTACK_H__
#include "../utils/utils.h"
#include "./SinglyLinkedNode.h"


typedef struct LinkedStack {
    SinglyLinkedNode* top;
} LinkedStack;

LinkedStack* LinkedStack_initialize() {
    LinkedStack* newstack = (LinkedStack*)malloc(sizeof(LinkedStack));
    if (newstack == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newstack->top = NULL;
    return newstack;
}

int LinkedStack_isEmpty(LinkedStack* S) {
    return S->top == NULL;
}

void LinkedStack_push(LinkedStack* S, int e) {
    SinglyLinkedNode* p = SinglyLinkedNode_getnode();
    if (p == NULL) {
        return;
    }
    p->element = e;
    p->link = S->top;
    S->top = p;
}

int LinkedStack_put(LinkedStack* S) {
    if (LinkedStack_isEmpty(S)) {
        return emptyStackException();
    }
    int e = S->top->element;
    SinglyLinkedNode* p = S->top;
    S->top = S->top->link;
    SinglyLinkedNode_putnode(p);
    return e;
}

// #endif