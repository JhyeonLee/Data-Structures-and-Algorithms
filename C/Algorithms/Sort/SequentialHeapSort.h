#pragma once
// #ifdef __SEQUENTIALHEAPSORT_H__
// #define __SEQUENTIALHEAPSORT_H__
#include<stdio.h>
#include "../DataStructures/SequentialHeap.h"

// orderType: Ascending(1, Min Heap) Descending(2, Max Heap)
SequentialHeap* inPlaceSequentialHeapSort_Insertion(int orderType) {
    int N; printf("Acceptable Size, or How Many?"); scanf("%d", &N);
    SequentialHeap* H = SequentialHeap_initialize(N, orderType);
    if (H == NULL) {
        return NULL;
    }
    // Phase 1: Build Heap
    printf("input keys and elements(key element)");
    for(int i = 1; i <= N; i++) {
        int key; int element;
        scanf("%d %d", key, element);
        if (orderType == 1) {
            SequentialHeap_insertItem_minHeap(H, key, element);
        } else if (orderType == 2) {
            SequentialHeap_insertItem_maxHeap(H, key, element);
        } else {
            wrongOrderTypeException();
            return;
        }
    }
    
    // Phase 2
    if (orderType == 1) {
        for(int i = N; i >= 2; i--) {
            SequentialHeap_swap(H, 1, i);
            H->size--;
            SequentialHeap_downHeap_minHeap(H, 1);
        }
        H->size = N;
    } else if (orderType == 2) {
        for(int i = N; i >= 2; i--) {
            SequentialHeap_swap(H, 1, i);
            H->size--;
            SequentialHeap_downHeap_maxHeap(H, 1);
        }
        H->size = N;
    } else {
        wrongOrderTypeException();
        return;
    }
    return H;
}

// Bottom UP
SequentialHeap* inPlaceSequentialHeapSort_BottomUp_Recursive(int orderType) {
    int N; int type;
    printf("Acceptable Size and Type for Sequential Heap? Min Heap(1) Max Heap(2)"); scanf("%d %d", &N, &type);
    SequentialHeap* H = SequentialHeap_initialize(N, type);
    // Phase 1: Build Heap
    printf("input keys and elements(key element)");
    for(int i = 1; i <= H->size; i++) {
        scanf("%d %d", &(H->keys[i]), &(H->elements[i]));
    }
    if (orderType == 1) {
        SequentialHeap_RecursiveBuildHeap_minHeap(H);
    } else if (orderType == 2) {
        SequentialHeap_RecursiveBuildHeap_maxHeap(H);
    } else {
        wrongOrderTypeException();
        return;
    }
    // Phase 2
    if (orderType == 1) {
        for(int i = N; i >= 2; i--) {
            SequentialHeap_swap(H, 1, i);
            H->size--;
            SequentialHeap_downHeap_minHeap(H, 1);
        }
        H->size = N;
    } else if (orderType == 2) {
        for(int i = N; i >= 2; i--) {
            SequentialHeap_swap(H, 1, i);
            H->size--;
            SequentialHeap_downHeap_maxHeap(H, 1);
        }
        H->size = N;
    } else {
        wrongOrderTypeException();
        return;
    }
    return H;
}

SequentialHeap* inPlacSequentialeHeapSort_BottomUp_nonRecursive(int orderType) {
    int N; int type;
    printf("Acceptable Size and Type for Sequential Heap? Min Heap(1) Max Heap(2)"); scanf("%d %d", &N, &type);
    SequentialHeap* H = SequentialHeap_initialize(N, type);
    // Phase 1: Build Heap
    printf("input keys and elements(key element)");
    for(int i = 1; i <= H->size; i++) {
        scanf("%d %d", &(H->keys[i]), &(H->elements[i]));
    }
    if (orderType == 1) {
        SequentialHeap_nonRecursiveBuildHeap_minHeap(H);
    } else if (orderType == 2) {
        SequentialHeap_nonRecursiveBuildHeap_maxHeap(H);
    } else {
        wrongOrderTypeException();
        return;
    }
    // Phase 2
    if (orderType == 1) {
        for(int i = N; i >= 2; i--) {
            SequentialHeap_swap(H, 1, i);
            H->size--;
            SequentialHeap_downHeap_minHeap(H, 1);
        }
        H->size = N;
    } else if (orderType == 2) {
        for(int i = N; i >= 2; i--) {
            SequentialHeap_swap(H, 1, i);
            H->size--;
            SequentialHeap_downHeap_maxHeap(H, 1);
        }
        H->size = N;
    } else {
        wrongOrderTypeException();
        return;
    }
    return H;
}

// #endif