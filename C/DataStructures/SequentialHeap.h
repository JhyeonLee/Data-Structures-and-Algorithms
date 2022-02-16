#pragma once
// #ifdef __SEQUENTIALHEAP_H__
// #define __SEQUENTIALHEAP_H__
#include<stdlib.h>
#include "../utils/utils.h"

typedef struct SequentialHeap {
    int* keys;
    int* elements;
    int acceptableSize;
    int size;
    int type; // Min Heap(1) Max Heap(2)
} SequentialHeap;

SequentialHeap* SequentialHeap_initialize(int N, int type) {
    SequentialHeap* newheap = (SequentialHeap*)malloc(sizeof(SequentialHeap));
    if (newheap == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newheap->keys = (int*)malloc((N+1)*sizeof(int));
    if (newheap->keys == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newheap->elements = (int*)malloc((N+1)*sizeof(int));
    if (newheap->elements == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newheap->acceptableSize = N;
    newheap->size = 0;
    return newheap;
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
    return i > H->size;
}

int SequentialHeap_isinternal(SequentialHeap* H, int i) {
    return i <= H->size;
}

void SequentialHeap_swap(SequentialHeap* H, int A, int B) {
    int k = H->keys[A];
    H->keys[A] = H->keys[B];
    H->keys[B] = k;

    int e = H->elements[A];
    H->elements[A] = H->elements[B];
    H->elements[B] = e;
}

void SequentialHeap_upHeap_minHeap(SequentialHeap* H, int i) {
    if(SequentialHeap_isRoot(i)) {
        return;
    }
    if (H->keys[i] <= H->keys[SequentialHeap_parent(i)]) {
        return;
    }
    SequentialHeap_swap(H, i, SequentialHeap_parent(i));
    SequentialHeap_upHeap_minHeap(H, SequentialHeap_parent(i));
}

void SequentialHeap_downHeap_minHeap(SequentialHeap* H, int i) {
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
    SequentialHeap_downHeap_minHeap(H, smaller);
}

void SequentialHeap_insertItem_minHeap(SequentialHeap* H, int k, int e) {
    H->size++;
    H->keys[H->size] = k;
    H->elements[H->size] = e;
    SequentialHeap_upHeap_maxHeap(H, H->size);
}

int SequentialHeap_removeMin_minHeap(SequentialHeap* H) {
    int k = H->keys[1];
    int e = H->elements[1];
    H->keys[1] = H->keys[H->size];
    H->elements[1] = H->elements[H->size];
    H->size--;
    SequentialHeap_downHeap_minHeap(H, 1);
    return e;
}

void SequentialHeap_upHeap_maxHeap(SequentialHeap* H, int i) {
    if(SequentialHeap_isRoot(i)) {
        return;
    }
    if (H->keys[i] >= H->keys[SequentialHeap_parent(i)]) { // Max Heap
        return;
    }
    SequentialHeap_swap(H, i, SequentialHeap_parent(i));
    SequentialHeap_upHeap_maxHeap(H, SequentialHeap_parent(i));
}

void SequentialHeap_downHeap_maxHeap(SequentialHeap* H, int i) {
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
    SequentialHeap_downHeap_maxHeap(H, bigger);
}

void SequentialHeap_insertItem_maxHeap(SequentialHeap* H, int k, int e) {
    H->size++;
    H->keys[H->size] = k;
    H->elements[H->size] = e;
    SequentialHeap_upHeap_maxHeap(H, H->size);
}

int SequentialHeap_removeMax_maxHeap(SequentialHeap* H) {
    int k = H->keys[1];
    int e = H->elements[1];
    H->keys[1] = H->keys[H->size];
    H->elements[1] = H->elements[H->size];
    H->size--;
    SequentialHeap_downHeap_maxHeap(H, 1);
}

// Build Bottom-Up Sequential Heap
void SequentialHeap_RecursiveBuildHeap_minHeap(SequentialHeap* H) {
    SequentialHeap_rBuildHeap_minHeap(H, 1);
}
void SequentialHeap_rBuildHeap_minHeap(SequentialHeap* H, int i) {
    if (i > H->size) {
        return;
    }
    SequentialHeap_rBuildHeap_minHeap(H, SequentialHeap_leftChild(i));
    SequentialHeap_rBuildHeap_minHeap(H, SequentialHeap_rightChild(i));
    SequentialHeap_downHeap_minHeap(H, i);
}

void SequentialHeap_nonRecursiveBuildHeap_minHeap(SequentialHeap* H) {
    for(int i = H->size / 2; i >= 1; i--) {
        SequentialHeap_downHeap_minHeap(H, i);
    }
}

void SequentialHeap_RecursiveBuildHeap_maxHeap(SequentialHeap* H) {
    SequentialHeap_rBuildHeap_maxHeap(H, 1);
}
void SequentialHeap_rBuildHeap_maxHeap(SequentialHeap* H, int i) {
    if (i > H->size) {
        return;
    }
    SequentialHeap_rBuildHeap_maxHeap(H, SequentialHeap_leftChild(i));
    SequentialHeap_rBuildHeap_maxHeap(H, SequentialHeap_rightChild(i));
    SequentialHeap_downHeap_maxHeap(H, i);
}

void SequentialHeap_nonRecursiveBuildHeap_maxHeap(SequentialHeap* H) {
    for(int i = H->size / 2; i >= 1; i--) {
        SequentialHeap_downHeap_maxHeap(H, i);
    }
}

// #endif