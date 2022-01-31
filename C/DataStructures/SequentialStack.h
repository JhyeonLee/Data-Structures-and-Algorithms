#pragma once
// #ifdef __SEQUENTIALSTACK_H__
// #define __SEQUENTIALSTACK_H__
#include<stdlib.h>
#include "../utils/utils.h"

typedef struct SequentialStack { // 원형 배열
    int* elements; // 원소들
    int acceptableSize; // 배열 크기
    int top;
} SequentialStack;

SequentialStack* SequentialStack_initialize(int n){
    SequentialStack* newstack = (SequentialStack*)malloc(sizeof(SequentialStack));
    if (newstack == NULL){
        notEnoughMemory();
        return NULL;
    }
    newstack->elements = (int*)malloc(n*sizeof(int));
    if (newstack->elements == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newstack->acceptableSize = n;
    newstack->top = -1;
    return newstack;
}

int SequentialStack_size(SequentialStack* S) {
    return S->top + 1;
}

int SequentialStack_isEmpty(SequentialStack* S) {
    return S->top == -1;
}

int SequentialStack_top(SequentialStack* S) {
    if (SequentialStack_isEmpty(S)) {
        return emptyListException();
    }
    return S->elements[S->top];
}

void SequentialStack_push(SequentialStack* S, int e) {
    if (S->top == S->acceptableSize - 1) {
        fullStackException();
        return;
    }
    S->top += 1;
    S->elements[S->top] = e;
}

int SequentialStack_pop(SequentialStack* S) {
    if (SequentialStack_isEmpty(S)){
        return emptyStackException();
    }
    S->top -= 1;
    return S->elements[S->top + 1];
}

// #endif