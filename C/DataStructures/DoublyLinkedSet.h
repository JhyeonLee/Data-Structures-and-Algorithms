#pragma once
// #ifdef __ARRAYLISTS_H_
// #define __ARRAYLISTS_H_

#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include "./DoublyLinkedList.h"

// 합집합(파괴적, 비재귀적)
DoublyLinkedList DoublyLinkedList_union(DoublyLinkedList* A, DoublyLinkedList* B) {
    DoublyLinkedList C = DoublyLinkedList_initialize();
    while(!DoublyLinkedList_isEmpty(A) && !DoublyLinkedList_isEmpty(B)) {
        int a = DoublyLinkedList_get(A, 1);
        int b = DoublyLinkedList_get(B, 1);
        if (a < b) {
            DoublyLinkedList_addLast(&C, a);
            DoublyLinkedList_removeFirst(A);
        } else if (a > b) {
            DoublyLinkedList_addLast(&C, b);
            DoublyLinkedList_removeFirst(B);
        } else { // a == b
            DoublyLinkedList_addLast(&C, a);
            DoublyLinkedList_removeFirst(A);
            DoublyLinkedList_removeFirst(B);
        }
    }
    while (!DoublyLinkedList_isEmpty(A)) {
        int a = DoublyLinkedList_get(A, 1);
        DoublyLinkedList_addLast(&C, a);
        DoublyLinkedList_removeFirst(A);
    }
    while (!DoublyLinkedList_isEmpty(B)) {
        int b = DoublyLinkedList_get(B, 1);
        DoublyLinkedList_addLast(&C, b);
        DoublyLinkedList_removeFirst(B);
    }
    return C;
}

// 교집합(파괴적, 비재귀적))
DoublyLinkedList DoublyLinkedList_intersect(DoublyLinkedList* A, DoublyLinkedList* B) {
    DoublyLinkedList C = DoublyLinkedList_initialize();
    while(!DoublyLinkedList_isEmpty(A) && !DoublyLinkedList_isEmpty(B)) {
        int a = DoublyLinkedList_get(A, 1);
        int b = DoublyLinkedList_get(B, 1);
        if (a < b) {
            DoublyLinkedList_removeFirst(A);
        } else if (a > b) {
            DoublyLinkedList_removeFirst(B);
        } else { // a == b
            DoublyLinkedList_addLast(&C, a);
            DoublyLinkedList_removeFirst(A);
            DoublyLinkedList_removeFirst(B);
        }
    }
    while (!DoublyLinkedList_isEmpty(A)) {
        DoublyLinkedList_removeFirst(A);
    }
    while (!DoublyLinkedList_isEmpty(B)) {
        DoublyLinkedList_removeFirst(B);
    }
    return C;
}

//차집합(A - B)
DoublyLinkedList DoublyLinkedList_subtract(DoublyLinkedList* A, DoublyLinkedList* B) {
    DoublyLinkedList C = DoublyLinkedList_initialize();
    while(!DoublyLinkedList_isEmpty(A) && !DoublyLinkedList_isEmpty(B)) {
        int a = DoublyLinkedList_get(A, 1);
        int b = DoublyLinkedList_get(B, 1);
        if (a < b) {
            DoublyLinkedList_addLast(&C, a);
            DoublyLinkedList_removeFirst(A);
        } else if (a > b) {
            DoublyLinkedList_removeFirst(B);
        } else { // a == b
            DoublyLinkedList_removeFirst(A);
            DoublyLinkedList_removeFirst(B);
        }
    }
    while (!DoublyLinkedList_isEmpty(A)) {
        int a = DoublyLinkedList_get(A, 1);
        DoublyLinkedList_addLast(&C, a);
        DoublyLinkedList_removeFirst(A);
    }
    while (!DoublyLinkedList_isEmpty(B)) {
        DoublyLinkedList_removeFirst(B);
    }
    return C;
}

// 포함 여부
int DoublyLinkedList_member(DoublyLinkedList* A, int e) {
    if (DoublyLinkedList_isEmpty(A)) {
        return -1;
    }
    for(DoublyLinkedNode* p = A->headNode; p != A->trailer; p = p->nextlink) {
        if (p->element == e) {
            return 1;
        }
    }
    return -1;
}

// 부분집합 여부(is B a subset of A?)
int DoublyLinkedList_subset(DoublyLinkedList* A, DoublyLinkedList* B) {
    if (DoublyLinkedList_isEmpty(A)) {
        return -1;
    }
    for(DoublyLinkedNode* p = A->headNode; p != A->trailer; p = p->nextlink) {
        if (DoublyLinkedList_member(B, p->element)) {
            if(p->nextlink == A->trailer) {
                return 1;
            }
        } else {
            return -1;
        }
    }
}

// #endif