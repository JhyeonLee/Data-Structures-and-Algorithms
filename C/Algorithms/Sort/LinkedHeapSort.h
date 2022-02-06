#pragma once
// #ifdef __LINKEDHEAPSORT_H__
// #define __LINKEDHEAPSORT_H__
#include<stdio.h>

#include "./LinkedHeap.h"

LinkedHeap* inPlaceLinkedHeapSort_Insertion(int orderType) {
    int N = 0;
    LinkedHeap* H = LinkedHeap_initialize(orderType);
    if (H == NULL) {
        return NULL;
    }
    // Phase 1: Build Heap
    printf("input keys and elements(key element).\n (-1 -1) concludes input phase.");
    for(;;) {
        int key; int element;
        scanf("%d %d", key, element);
        if (key == -1 && element == -1) {
            break;
        }
        if (orderType == 1) {
            LinkedHeap_insertItem_minHeap(H, key, element);
        } else if (orderType == 2) {
            LinkedHeap_insertItem_maxHeap(H, key, element);
        } else {
            return NULL;
        }
        N++;
    }
    H->n = N;
    
    // Phase 2
    if (orderType == 1) {
        LinkedBinaryTreeNode* lastNode = LinkedHeap_findLastNode(H);
        for(int i = H->n; i >= 2; i--) {
            LinkedHeap_swap(H->root, lastNode);
            LinkedHeap_downHeap_minHeap(H->root);
            lastNode = LinkedHeap_retreatLastNode(H, lastNode);
        }
        H->n = N;
    } else if (orderType == 2) {
        LinkedBinaryTreeNode* lastNode = LinkedHeap_findLastNode(H);
        for(int i = N; i >= 2; i--) {
            LinkedHeap_swap(H->root, lastNode);
            LinkedHeap_downHeap_maxHeap(H->root);
            lastNode = LinkedHeap_retreatLastNode(H, lastNode);
        }
    } else {
        return NULL;
    }
    return H;
}

// Bottom UP
LinkedHeap* inPlaceLinkedHeapSort_BottomUp_Recursive(int orderType) {
    int N = 0;
    SinglyLinkedList* list = SinglyLinkedList_initialize();
    if (list == NULL) {
        return NULL;
    }

    // Phase 1: Build Heap
    printf("input keys and elements(key element).\n (-1 -1) concludes input phase.");
    for(;;) {
        int key; int element;
        scanf("%d %d", key, element);
        if (key == -1 && element == -1) {
            break;
        }
        SinglyLinkedList_addLast(list, key, element);
        N++;
    }
    LinkedHeap* H;
    if (orderType == 1) {
        H = LinkedHeap_RecursiveBuildHeap_minHeap(list, orderType);
    } else if (orderType == 2) {
        H = LinkedHeap_RecursiveBuildHeap_maxHeap(list, orderType);
    } else {
        return NULL;
    }
    H->n = N;

    // Phase 2
    if (orderType == 1) {
        LinkedBinaryTreeNode* lastNode = LinkedHeap_findLastNode(H);
        for(int i = H->n; i >= 2; i--) {
            LinkedHeap_swap(H->root, lastNode);
            LinkedHeap_downHeap_minHeap(H->root);
            lastNode = LinkedHeap_retreatLastNode(H, lastNode);
        }
        H->n = N;
    } else if (orderType == 2) {
        LinkedBinaryTreeNode* lastNode = LinkedHeap_findLastNode(H);
        for(int i = N; i >= 2; i--) {
            LinkedHeap_swap(H->root, lastNode);
            LinkedHeap_downHeap_maxHeap(H->root);
            lastNode = LinkedHeap_retreatLastNode(H, lastNode);
        }
    } else {
        return NULL;
    }
    return H;
}

// #endif