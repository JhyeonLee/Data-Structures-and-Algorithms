#pragma once
// #ifdef __SEQUENTIALHEAP_H__
// #define __SEQUENTIALHEAP_H__
#include<stdio.h>
#include "../DataStructures/SequentialHeap.h"

// orderType: Ascending(1, Min Heap) Descending(2, Max Heap)
SequentialHeap* inPlaceHeapSort_Insertion(int orderType) {
    int N; printf("Acceptable Size, or How Many?"); scanf("%d", &N);
    SequentialHeap* H = SequentialHeap_initialize(N, orderType);
    // Phase 1: Build Heap
    printf("input keys and elements(key element)");
    for(int i = 1; i <= N; i++) {
        int key; int element;
        scanf("%d %d", key, element);
        if (orderType == 1) {
            SequentialHeap_insertItem_MinHeap(H, key, element);
        } else if (orderType == 2) {
            SequentialHeap_insertItem_MaxHeap(H, key, element);
        } else {
            return;
        }
    }
    
    // Phase 2
    if (orderType == 1) {
        for(int i = N; i >= 2; i--) {
            SequentialHeap_swap(H, 1, i);
            H->n--;
            SequentialHeap_downHeap_MinHeap(H, 1);
        }
        H->n = N;
    } else if (orderType == 2) {
        for(int i = N; i >= 2; i--) {
            SequentialHeap_swap(H, 1, i);
            H->n--;
            SequentialHeap_downHeap_MaxHeap(H, 1);
        }
        H->n = N;
    } else {
        return;
    }
    return H;
}

// Bottom UP
SequentialHeap* inPlaceHeapSort_BottomUp_Recursive(int orderType) {
    int N; int type;
    printf("Acceptable Size and Type for Sequential Heap? Min Heap(1) Max Heap(2)"); scanf("%d %d", &N, &type);
    SequentialHeap* H = SequentialHeap_initialize(N, type);
    // Phase 1: Build Heap
    printf("input keys and elements(key element)");
    for(int i = 1; i <= H->n; i++) {
        scanf("%d %d", &(H->keys[i]), &(H->elements[i]));
    }
    if (H->type == 1) {
        SequentialHeap_RecursiveBuildHeap_MinHeap(H);
    } else if (H->type == 2) {
        SequentialHeap_RecursiveBuildHeapp_MaxHeap(H);
    } else {
        return;
    }
    // Phase 2
    if (orderType == 1) {
        for(int i = N; i >= 2; i--) {
            SequentialHeap_swap(H, 1, i);
            H->n--;
            SequentialHeap_downHeap_MinHeap(H, 1);
        }
        H->n = N;
    } else if (orderType == 2) {
        for(int i = N; i >= 2; i--) {
            SequentialHeap_swap(H, 1, i);
            H->n--;
            SequentialHeap_downHeap_MaxHeap(H, 1);
        }
        H->n = N;
    } else {
        return;
    }
}

SequentialHeap* inPlaceHeapSort_BottomUp_nonRecursive(int orderType) {
    int N; int type;
    printf("Acceptable Size and Type for Sequential Heap? Min Heap(1) Max Heap(2)"); scanf("%d %d", &N, &type);
    SequentialHeap* H = SequentialHeap_initialize(N, type);
    // Phase 1: Build Heap
    printf("input keys and elements(key element)");
    for(int i = 1; i <= H->n; i++) {
        scanf("%d %d", &(H->keys[i]), &(H->elements[i]));
    }
    if (H->type == 1) {
        SequentialHeap_nonRecursiveBuildHeap_MinHeap(H);
    } else if (H->type == 2) {
        SequentialHeap_nonRecursiveBuildHeap_MaxHeap(H);
    } else {
        return;
    }
    // Phase 2
    if (orderType == 1) {
        for(int i = N; i >= 2; i--) {
            SequentialHeap_swap(H, 1, i);
            H->n--;
            SequentialHeap_downHeap_MinHeap(H, 1);
        }
        H->n = N;
    } else if (orderType == 2) {
        for(int i = N; i >= 2; i--) {
            SequentialHeap_swap(H, 1, i);
            H->n--;
            SequentialHeap_downHeap_MaxHeap(H, 1);
        }
        H->n = N;
    } else {
        return;
    }
}

// #endif