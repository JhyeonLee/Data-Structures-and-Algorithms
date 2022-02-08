#pragma once
// #ifdef __LINKEDSORT_H__
// #define __LINKEDSORT_H__
#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include "../DataStructures/LinkedPriorityQueue.h"
#include "../DataStructures/SinglyLinkedList.h"
#include "../DataStructures/DoublyLinkedList.h"

// 우선순위 큐를 이용한 정렬
void Linked_PQ_Sort(SinglyLinkedList* list) {
    LinkedPriorityQueue* Pq = LinkedPriorityQueue_initialize();
    if (Pq == NULL) {
        return;
    }
    SinglyLinkedNode* node;
    while (!SinglyLinkedList_isEmpty(list)) {
        node = SinglyLinkedList_removeFirst(list);
        if (node == NULL) {
            return;
        }
        LinkedPriorityQueue_insertItem(Pq, node->key, node->element);
    }
    while (!LinkedPriorityQueue_isEmpty(Pq)) {
        node = LinkedPriorityQueue_removeMin(Pq);
        if (node == NULL) {
            return;
        }
        SinglyLinkedList_addLast(list, node->key, node->element);
    }
}

// 제자리 선택 정렬
void SinglyLinked_inPlaceSelectionSort(SinglyLinkedList* list) {
    SinglyLinkedNode* pass = list->headNode;
    for( ; pass != list->tailNode; pass = pass->link) {
        SinglyLinkedNode* min = pass;
        SinglyLinkedNode* j = pass->link;
        for( ; j != list->tailNode; j = j->link) {
            // sort by key
            if (j->key < min->key) {
                min = j;
            }
            // sort by element
            // if (j->element < min->element) {
            //     min = j;
            // }
        }
        SinglyLinkedList_swap(pass, min);
    }
}

void DoublyLinked_inPlaceSelectionSort(DoublyLinkedList* list) {
    DoublyLinkedNode* pass = list->headNode;
    for( ; pass != (list->tailNode)->previouslink; pass = pass->nextlink) {
        DoublyLinkedNode* min = pass;
        DoublyLinkedNode* j = pass->nextlink;
        for( ; j != list->tailNode; j = j->nextlink) {
            // sort by key
            if (j->key < min->key) {
                min = j;
            }
            // sort by element
            // if (j->element < min->element) {
            //     min = j;
            // }
        }
        DoublyLinkedList_swap(pass, min);
    }
}

// 제자리 삽입 정렬
void DoublyLinked_inPlaceInsertionSort(DoublyLinkedList* list) {
    DoublyLinkedNode* pass = list->headNode;
    for( ; pass != list->tailNode; pass = pass->nextlink) {
        int savedKey = pass->key;
        int savedElement = pass->element;
        DoublyLinkedNode* j = pass->previouslink;
        // sort by key
        for( ; j != list->header && j->key > savedKey; j = j->previouslink) {
            (j->nextlink)->key = j->key;
            (j->nextlink)->element = j->element;
        }
        // sort by element
        // for( ; j != list->header && j->element > savedElement; j = j->previouslink) {
        //     (j->nextlink)->key = j->key;
        //     (j->nextlink)->element = j->element;
        // }
        (j->nextlink)->key = savedKey;
        (j->nextlink)->element = savedElement;
    }
}

// #endif