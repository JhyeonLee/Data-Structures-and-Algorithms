#pragma once
// #ifdef __SEQUENTIALHEAP_H__
// #define __SEQUENTIALHEAP_H__
#include<stdlib.h>
#include "../utils/utils.h"

typedef struct SequentialHeap {
    int* keys;
    int* elements;
    int acceptableSize;
    int n;
    int type; // Min Heap(1) Max Heap(2)
} SequentialHeap;

SequentialHeap* SequentialHeap_initialize(int N, int type) {
    SequentialHeap* newHeap = (SequentialHeap*)malloc(sizeof(SequentialHeap));
    if (newHeap == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newHeap->keys = (int*)malloc(N*sizeof(int));
    if (newHeap->keys == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newHeap->elements = (int*)malloc(N*sizeof(int));
    if (newHeap->elements == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newHeap->acceptableSize = N;
    newHeap->n = 0;
    return newHeap;
}

int SequentialHeap_isRoot(int i) {
    return i == 1;
}

int SequentialHeap_parent(int i) {
    return i / 2;
}

int SequentialHeap_leftChild(int i) {
    return 2 * i;
}
int SequentialHeap_rightChild(int i) {
    return 2 * i + 1;
}

int SequentialHeap_isExternal(SequentialHeap* H, int i) {
    return i > H->n;
}

int SequentialHeap_isinternal(SequentialHeap* H, int i) {
    return i <= H->n;
}

void SequentialHeap_swap(SequentialHeap* H, int A, int B) {
    int k = H->keys[A];
    H->keys[A] = H->keys[B];
    H->keys[B] = k;

    int e = H->elements[A];
    H->elements[A] = H->elements[B];
    H->elements[B] = e;
}

void SequentialHeap_upHeap_MinHeap(SequentialHeap* H, int i) {
    if(SequentialHeap_isRoot(i)) {
        return;
    }
    if (H->keys[i] <= H->keys[SequentialHeap_parent(i)]) {
        return;
    }
    SequentialHeap_swap(H, i, SequentialHeap_parent(i));
    SequentialHeap_upHeap_MinHeap(H, SequentialHeap_parent(i));
}

void SequentialHeap_downHeap_MinHeap(SequentialHeap* H, int i) {
    if (SequentialHeap_isExternal(H, SequentialHeap_leftChild(i)) && SequentialHeap_isExternal(H, SequentialHeap_rightChild(i))) {
        return;
    }
    int smaller = SequentialHeap_leftChild(i);
    if (SequentialHeap_isinternal(H, SequentialHeap_rightChild(i))) {
        if (H->keys[SequentialHeap_rightChild(i)] < H->keys[smaller]) {
            smaller = SequentialHeap_rightChild(i);
        }
    }
    if (H->keys[i] <= H->keys[smaller]) {
        return;
    }
    SequentialHeap_swap(H, i, smaller);
    SequentialHeap_downHeap_MinHeap(H, smaller);
}

void SequentialHeap_insertItem_MinHeap(SequentialHeap* H, int k, int e) {
    H->n++;
    H->keys[H->n] = k;
    H->elements[H->n] = e;
    SequentialHeap_upHeap_MaxHeap(H, H->n);
}

int SequentialHeap_removeMin_MinHeap(SequentialHeap* H) {
    int k = H->keys[1];
    int e = H->elements[1];
    H->keys[1] = H->keys[H->n];
    H->elements[1] = H->elements[H->n];
    H->n--;
    SequentialHeap_downHeap_MinHeap(H, 1);
    return e;
}

void SequentialHeap_upHeap_MaxHeap(SequentialHeap* H, int i) {
    if(SequentialHeap_isRoot(i)) {
        return;
    }
    if (H->keys[i] >= H->keys[SequentialHeap_parent(i)]) { // Max Heap
        return;
    }
    SequentialHeap_swap(H, i, SequentialHeap_parent(i));
    SequentialHeap_upHeap_MaxHeap(H, SequentialHeap_parent(i));
}

void SequentialHeap_downHeap_MaxHeap(SequentialHeap* H, int i) {
    if (SequentialHeap_isExternal(H, SequentialHeap_leftChild(i)) && SequentialHeap_isExternal(H, SequentialHeap_rightChild(i))) {
        return;
    }
    int bigger = SequentialHeap_leftChild(i);
    if (SequentialHeap_isinternal(H, SequentialHeap_rightChild(i))) {
        if (H->keys[SequentialHeap_rightChild(i)] > H->keys[bigger]) {
            bigger = SequentialHeap_rightChild(i);
        }
    }
    if (H->keys[i] >= H->keys[bigger]) {
        return;
    }
    SequentialHeap_swap(H, i, bigger);
    SequentialHeap_downHeap_MaxHeap(H, bigger);
}

void SequentialHeap_insertItem_MaxHeap(SequentialHeap* H, int k, int e) {
    H->n++;
    H->keys[H->n] = k;
    H->elements[H->n] = e;
    SequentialHeap_upHeap_MaxHeap(H, H->n);
}

int SequentialHeap_removeMax_MaxHeap(SequentialHeap* H) {
    int k = H->keys[1];
    int e = H->elements[1];
    H->keys[1] = H->keys[H->n];
    H->elements[1] = H->elements[H->n];
    H->n--;
    SequentialHeap_downHeap_MaxHeap(H, 1);
}

// Build Bottom-Up Sequential Heap
void SequentialHeap_RecursiveBuildHeap_MinHeap(SequentialHeap* H) {
    SequentialHeap_rBuildHeap_MinHeap(H, 1);
}
void SequentialHeap_rBuildHeap_MinHeap(SequentialHeap* H, int i) {
    if (i > H->n) {
        return;
    }
    SequentialHeap_rBuildHeap_MinHeap(H, SequentialHeap_leftChild(i));
    SequentialHeap_rBuildHeap_MinHeap(H, SequentialHeap_rightChild(i));
    SequentialHeap_downHeap_MinHeap(H, i);
}

void SequentialHeap_nonRecursiveBuildHeap_MinHeap(SequentialHeap* H) {
    for(int i = H->n / 2; i >= 1; i--) {
        SequentialHeap_downHeap_MinHeap(H, i);
    }
}

void SequentialHeap_RecursiveBuildHeapp_MaxHeap(SequentialHeap* H) {
    SequentialHeap_rBuildHeap_MaxHeap(H, 1);
}
void SequentialHeap_rBuildHeap_MaxHeap(SequentialHeap* H, int i) {
    if (i > H->n) {
        return;
    }
    SequentialHeap_rBuildHeap_MaxHeap(H, SequentialHeap_leftChild(i));
    SequentialHeap_rBuildHeap_MaxHeap(H, SequentialHeap_rightChild(i));
    SequentialHeap_downHeap_MaxHeap(H, i);
}

void SequentialHeap_nonRecursiveBuildHeap_MaxHeap(SequentialHeap* H) {
    for(int i = H->n / 2; i >= 1; i--) {
        SequentialHeap_downHeap_MaxHeap(H, i);
    }
}

// #endif