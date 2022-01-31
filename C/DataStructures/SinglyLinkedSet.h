#pragma once
// #ifdef __ARRAYLISTS_H_
// #define __ARRAYLISTS_H_

#include <stdio.h>
#include <stdlib.h>
#include "./SinglyLinkedList.h"

// 합집합(파괴적, 비재귀적)
SinglyLinkedList SinglyLinkedList_union(SinglyLinkedList* A, SinglyLinkedList* B) {
    SinglyLinkedList C = SinglyLinkedList_initialize();
    while(!SinglyLinkedList_isEmpty(A) && !SinglyLinkedList_isEmpty(B)) {
        int a = SinglyLinkedList_get(A, 1);
        int b = SinglyLinkedList_get(B, 1);
        if (a < b) {
            SinglyLinkedList_addLast(&C, a);
            SinglyLinkedList_removeFirst(A);
        } else if (a > b) {
            SinglyLinkedList_addLast(&C, b);
            SinglyLinkedList_removeFirst(B);
        } else { // a == b
            SinglyLinkedList_addLast(&C, a);
            SinglyLinkedList_removeFirst(A);
            SinglyLinkedList_removeFirst(B);
        }
    }
    while (!SinglyLinkedList_isEmpty(A)) {
        int a = SinglyLinkedList_get(A, 1);
        SinglyLinkedList_addLast(&C, a);
        SinglyLinkedList_removeFirst(A);
    }
    while (!SinglyLinkedList_isEmpty(B)) {
        int b = SinglyLinkedList_get(B, 1);
        SinglyLinkedList_addLast(&C, b);
        SinglyLinkedList_removeFirst(B);
    }
    return C;
}

// 교집합(파괴적, 비재귀적))
SinglyLinkedList SinglyLinkedList_intersect(SinglyLinkedList* A, SinglyLinkedList* B) {
    SinglyLinkedList C = SinglyLinkedList_initialize();
    while(!SinglyLinkedList_isEmpty(A) && !SinglyLinkedList_isEmpty(B)) {
        int a = SinglyLinkedList_get(A, 1);
        int b = SinglyLinkedList_get(B, 1);
        if (a < b) {
            SinglyLinkedList_removeFirst(A);
        } else if (a > b) {
            SinglyLinkedList_removeFirst(B);
        } else { // a == b
            SinglyLinkedList_addLast(&C, a);
            SinglyLinkedList_removeFirst(A);
            SinglyLinkedList_removeFirst(B);
        }
    }
    while (!SinglyLinkedList_isEmpty(A)) {
        SinglyLinkedList_removeFirst(A);
    }
    while (!SinglyLinkedList_isEmpty(B)) {
        SinglyLinkedList_removeFirst(B);
    }
    return C;
}

//차집합(A - B)
SinglyLinkedList SinglyLinkedList_subtract(SinglyLinkedList* A, SinglyLinkedList* B) {
    SinglyLinkedList C = SinglyLinkedList_initialize();
    while(!SinglyLinkedList_isEmpty(A) && !SinglyLinkedList_isEmpty(B)) {
        int a = SinglyLinkedList_get(A, 1);
        int b = SinglyLinkedList_get(B, 1);
        if (a < b) {
            SinglyLinkedList_addLast(&C, a);
            SinglyLinkedList_removeFirst(A);
        } else if (a > b) {
            SinglyLinkedList_removeFirst(B);
        } else { // a == b
            SinglyLinkedList_removeFirst(A);
            SinglyLinkedList_removeFirst(B);
        }
    }
    while (!SinglyLinkedList_isEmpty(A)) {
        int a = SinglyLinkedList_get(A, 1);
        SinglyLinkedList_addLast(&C, a);
        SinglyLinkedList_removeFirst(A);
    }
    while (!SinglyLinkedList_isEmpty(B)) {
        SinglyLinkedList_removeFirst(B);
    }
    return C;
}

// 포함 여부
int SinglyLinkedList_member(SinglyLinkedList* A, int e) {
    if (SinglyLinkedList_isEmpty(A)) {
        return -1;
    }
    for(SinglyLinkedNode* p = A->headNode; p != A->trailer; p = p->link) {
        if (p->element == e) {
            return 1;
        }
    }
    return -1;
}

// 부분집합 여부(is B a subset of A?)
int SinglyLinkedList_subset(SinglyLinkedList* A, SinglyLinkedList* B) {
    if (SinglyLinkedList_isEmpty(A)) {
        return -1;
    }
    for(SinglyLinkedNode* p = A->headNode; p != A->trailer; p = p->link) {
        if (SinglyLinkedList_member(B, p->element)) {
            if(p->link == A->trailer) {
                return 1;
            }
        } else {
            return -1;
        }
    }
}

// #endif