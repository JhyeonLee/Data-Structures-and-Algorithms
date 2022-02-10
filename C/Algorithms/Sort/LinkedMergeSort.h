#pragma once
// #ifdef __SinglyLINKEDMERGESORT_H__
// #define __SinglyLINKEDMERGESORT_H__
#include "../DataStructures/SinglyLinkedList.h"
#include "../DataStructures/DoublyLinkedList.h"

// orderType: 오름차순(Ascending, 1), 내림차순(Descending, 2)
void SinglyLinkedMergeSort(SinglyLinkedList* list, int orderType) {
    SinglyLinkedRMergeSort(list, orderType);
}
void SinglyLinkedRMergeSort(SinglyLinkedList* list, int orderType) {
    if (list->size > 1) {
        SinglyLinkedList* SinglyPartitionedList = SinglyLinkedList_Partition(list, list->size/2);
        SinglyLinkedRMergeSort(list, orderType);
        SinglyLinkedRMergeSort(SinglyPartitionedList, orderType);
        SinglyLinkedMerge(list, SinglyPartitionedList, orderType);
    }
}

void SinglyLinkedMerge(SinglyLinkedList* left, SinglyLinkedList* right, int orderType) {
    SinglyLinkedNode* L = left->header;
    while( L->link != left->trailer && !SinglyLinkedList_isEmpty(right)) {
        // sort Ascending by key
        if (orderType == 1) {
            if (L == left->header && (left->headNode)->key > (right->headNode)->key) {
                SinglyLinkedNode* tmp = SinglyLinkedList_removeFirst(right);
                SinglyLinkedList_insertNodeNext(L, tmp);
            } else if ((L->link)->key > (right->headNode)->key) {
                SinglyLinkedNode* tmp = SinglyLinkedList_removeFirst(right);
                SinglyLinkedList_insertNodeNext(L, tmp);
            } else { // (L->link)->key <= (right->headNode)->key
                L = L->link;
            }
        } else if (orderType == 2) { // sort Descending by key
            if (L == left->header && (left->headNode)->key < (right->headNode)->key) {
                SinglyLinkedNode* tmp = SinglyLinkedList_removeFirst(right);
                SinglyLinkedList_insertNodeNext(L, tmp);
            } else if ((L->link)->key < (right->headNode)->key) {
                SinglyLinkedNode* tmp = SinglyLinkedList_removeFirst(right);
                SinglyLinkedList_insertNodeNext(L, tmp);
            } else { // (L->link)->key >= (right->headNode)->key
                L = L->link;
            }
        } else {
            return;
        }
        
        // sort Ascending by element
        // if (orderType == 1) {
        //     if (L == left->header && (left->headNode)->element > (right->headNode)->element) {
        //         SinglyLinkedNode* tmp = SinglyLinkedList_removeFirst(right);
        //         SinglyLinkedList_insertNodeNext(L, tmp);
        //     } else if ((L->link)->element > (right->headNode)->element) {
        //         SinglyLinkedNode* tmp = SinglyLinkedList_removeFirst(right);
        //         SinglyLinkedList_insertNodeNext(L, tmp);
        //     } else { // (L->link)->element <= (right->headNode)->element
        //         L = L->link;
        //     }
        // } else if (orderType == 2) { // sort Descending by element
        //     if (L == left->header && (left->headNode)->element < (right->headNode)->element) {
        //         SinglyLinkedNode* tmp = SinglyLinkedList_removeFirst(right);
        //         SinglyLinkedList_insertNodeNext(L, tmp);
        //     } else if ((L->link)->element < (right->headNode)->element) {
        //         SinglyLinkedNode* tmp = SinglyLinkedList_removeFirst(right);
        //         SinglyLinkedList_insertNodeNext(L, tmp);
        //     } else { // (L->link)->element >= (right->headNode)->element
        //         L = L->link;
        //     }
        // } else {
        //     return;
        // }
    }
    if( !SinglyLinkedList_isEmpty(right)) {
        SinglyLinkedList_concatenate(left, right);
    }
}

void DoublyLinkedMergeSort(DoublyLinkedList* list, int orderType) {
    DoublyLinkedRMergeSort(list, orderType);
}
void DoublyLinkedRMergeSort(DoublyLinkedList* list, int orderType) {
    if (list->size > 1) {
        DoublyLinkedList* DoublyPartitionedList = DoublyLinkedList_Partition(list, list->size/2);
        DoublyLinkedRMergeSort(list, orderType);
        DoublyLinkedRMergeSort(DoublyPartitionedList, orderType);
        DoublyLinkedMerge(list, DoublyPartitionedList, orderType);
    }
}
void DoublyLinkedMerge(DoublyLinkedList* left, DoublyLinkedList* right, int orderType) {
    DoublyLinkedNode* L = left->headNode;
    while(L != left->trailer && !DoublyLinkedList_isEmpty(right)) {
        // sort Ascending by key
        if (orderType == 1) {
            if (L->key > (right->headNode)->key)  {
                DoublyLinkedNode* tmp = DoublyLinkedList_removeFirst(right);
                DoublyLinkedList_insertNodeBefore(L, tmp);
            } else { // L->key <= (right->headNode)->key
                L = L->nextlink;
            }
        } else if (orderType == 2) { // sort Descending by key
            if (L->key < (right->headNode)->key)  {
                DoublyLinkedNode* tmp = DoublyLinkedList_removeFirst(right);
                DoublyLinkedList_insertNodeBefore(L, tmp);
            } else { // L->key >= (right->headNode)->key
                L = L->nextlink;
            }
        } else {
            return;
        }
        
        // sort Ascending by element
        // if (orderType == 1) {
        //     if (L->element > (right->headNode)->element)  {
        //         DoublyLinkedNode* tmp = DoublyLinkedList_removeFirst(right);
        //         DoublyLinkedList_insertNodeBefore(L, tmp);
        //     } else { // L->element <= (right->headNode)->element
        //         L = L->nextlink;
        //     }
        // } else if (orderType == 2) { // sort Descending by element
        //     if (L->element < (right->headNode)->element)  {
        //         DoublyLinkedNode* tmp = DoublyLinkedList_removeFirst(right);
        //         DoublyLinkedList_insertNodeBefore(L, tmp);
        //     } else { // L->element >= (right->headNode)->element
        //         L = L->nextlink;
        //     }
        // } else {
        //     return;
        // }
    }
    if (!DoublyLinkedList_isEmpty(right)) {
        DoublyLinkedList_concatenate(left, right);
    }
}

// #endif