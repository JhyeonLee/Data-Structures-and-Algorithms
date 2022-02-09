#pragma once
// #ifdef __SINGLYLINKEDLIST_H__
// #define __SINGLYLINKEDLIST_H__
#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include "./SinglyLinkedNode.h"

typedef struct SinglyLinkedList {
    SinglyLinkedNode* headNode;
    SinglyLinkedNode* tailNode;
    SinglyLinkedNode* header;
    SinglyLinkedNode* trailer;
    int size;
} SinglyLinkedList;

SinglyLinkedList* SinglyLinkedList_initialize() {
    SinglyLinkedList* newlist = (SinglyLinkedList*)malloc(sizeof(SinglyLinkedList));
    if (newlist == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newlist->headNode = NULL;
    newlist->tailNode = NULL;
    newlist->header = SinglyLinkedNode_getnode();
    newlist->trailer = SinglyLinkedNode_getnode();
    (newlist->header)->link = newlist->trailer;
    int n = 0;
    return newlist;
}

// 리스트의 크기, 즉 원소 수 반환
int SinglyLinkedList_size(SinglyLinkedList* list){
    int count = 0;
    if (list->headNode == NULL) {
        return count;
    }
    for(SinglyLinkedNode* p = list->headNode; p != list->trailer; p = p->link){
        count += 1;
    }
    return count;
}

// 리스트가 비어 있는지 여부를 반환
int SinglyLinkedList_isEmpty(SinglyLinkedList* list) {
    return SinglyLinkedList_size(list) == 0;
}

void SinglyLinkedList_swap(SinglyLinkedNode* A, SinglyLinkedNode* B) {
    int k = A->key;
    A->key = B->key;
    B->key = k;

    int e = A->element;
    A->element = B->element;
    B->element = e;
}

// 순위 r에 있는 노드 반환
SinglyLinkedNode* SinglyLinkedList_findNode(SinglyLinkedList* list, int r) {
    SinglyLinkedNode* p = list->header;
    for(int i = 0; i <r; i++){
        p = p->link;
    }
    return p;
}

// 순위 r에 저장된 원소를 반환
int SinglyLinkedList_get(SinglyLinkedList* list, int r) {
    if ( r < 1 || SinglyLinkedList_size(list) < r) {
        invalidRankException();
        return NULL;
    }
    SinglyLinkedNode* p = SinglyLinkedList_findNode(list, r);
    return p->element;
}

// 순위 r에 저장된 원소를 e로 대체
int SinglyLinkedList_set(SinglyLinkedList* list, int r, int e) {
    if (r < 1 || SinglyLinkedList_size(list) < r) {
        return invalidRankException();
    }
    SinglyLinkedNode* p = SinglyLinkedList_findNode(list, r);
    int q = p->element;
    p->element = e;
    return e;
}

// 원소 전체 순회
void SinglyLinkedList_traverse(SinglyLinkedList* list) {
    for(SinglyLinkedNode* p = list->headNode; p != list->trailer; p = p->link) {
        printf(" %d", p->element);
    }
    printf("\n");
}

// 노드 p 뒤에 값이 e인 노드 삽입
void SinglyLinkedList_addNodeNext(SinglyLinkedNode* p, int k, int e) {
    SinglyLinkedNode* q = SinglyLinkedNode_getnode();
    q->key = k;
    q->element = e;
    q->link = p->link;
    p->link = q;
}

// 순위 r에 원소가 e인 노드 삽입
void SinglyLinkedList_add(SinglyLinkedList* list, int r, int k, int e) {
    if (r < 1 || SinglyLinkedList_size(list)+1 < r) {
        invalidRankException();
        return;
    }
    SinglyLinkedNode* p = SinglyLinkedList_findNode(list, r-1);
    SinglyLinkedList_addNodeNext(p, k, e);
    list->size++;
}

// 리스트 가장 앞에(헤드 노드) 원소가 e인 노드 삽입
void SinglyLinkedList_addFirst(SinglyLinkedList* list, int k, int e) {
    SinglyLinkedList_add(list, 1, k, e);
}

// 리스트 가장 끝에(테일 노드) 원소가 e인 노드 삽입
void SinglyLinkedList_addLast(SinglyLinkedList* list, int k, int e) {
    SinglyLinkedList_add(list, SinglyLinkedList_size(list)+1, k, e);
}

void SinglyLinkedList_insertNodeNext(SinglyLinkedNode* p, SinglyLinkedNode* q) {
    q->link = p->link;
    p->link = q;
}

SinglyLinkedList* SinglyLinkedList_concatenate(SinglyLinkedList* left, SinglyLinkedList* right) {
    (left->tailNode)->link = right->headNode;
    SinglyLinkedNode_putnode(left->trailer);
    left->trailer = right->trailer;
    SinglyLinkedNode_putnode(right->header);
    left->size += right->size;
    return left;
}

SinglyLinkedList* SinglyLinkedList_Partition(SinglyLinkedList* list, int r) {
    SinglyLinkedNode* prev = SinglyLinkedList_findNode(list, r-1);
    SinglyLinkedNode* p = prev->link;

    SinglyLinkedList* SinglyPartitionedList = SinglyLinkedList_initialize();
    (SinglyPartitionedList->header)->link = p;
    SinglyPartitionedList->headNode = p;
    SinglyPartitionedList->tailNode = list->tailNode;
    SinglyPartitionedList->trailer = list->trailer;

    prev->link = list->trailer;
    list->tailNode = prev;

    SinglyPartitionedList->size = list->size - r;
    list->size = r;
    return SinglyPartitionedList;
}

// 노드 p 삭제
SinglyLinkedNode* SinglyLinkedList_removeNode(SinglyLinkedNode* previousNode) {
    SinglyLinkedNode* p = previousNode->link;
    if (p == NULL) {
        // return -1;
        return NULL;
    }
    // int e = p->element;
    previousNode->link = p->link;
    // SinglyLinkedNode_putnode(p);
    // return e;

    // apply node which has key and element
    p->link = NULL;
    return p;
}

// 순위 r에 저장된 원소를 삭제하여 반환
SinglyLinkedNode* SinglyLinkedList_remove(SinglyLinkedList* list, int r) {
    if (r < 1 || SinglyLinkedList_size(list) < r) {
        invalidRankException();
        // return -1;
        return NULL;
    }
    SinglyLinkedNode* p = list->header;
    for(int i = 0; i<r-1; i++){
        p = p->link;
    }
    // int e = SinglyLinkedList_removeNode(p);
    list->size--;
    // return e;

    // apply node which has key and element
    p = SinglyLinkedList_removeNode(p);
    if (p == NULL) {
        return;
    }
    if(list->size == 0) {
        list->headNode = NULL;
        list->tailNode = NULL;
    }
    return p;
}

// 리스트 가장 앞에(헤드 노드) 원소가 e인 노드 삭제
// apply node which has key and element
SinglyLinkedNode* SinglyLinkedList_removeFirst(SinglyLinkedList* list) {
    return SinglyLinkedList_remove(list, 1);
}

// 리스트 가장 끝에(테일 노드) 원소가 e인 노드 삭제
// apply node which has key and element
SinglyLinkedNode* SinglyLinkedList_removeLast(SinglyLinkedList* list) {
    return SinglyLinkedList_remove(list, SinglyLinkedList_size(list));
}

// 헤더와 트레일러 이외 모든 원소 삭제
void SinglyLinkedList_removeAll(SinglyLinkedList* list) {
    if (SinglyLinkedList_isEmpty(list)) {
        emptyListException();
        return;
    }
    for(int i = SinglyLinkedList_size(list); i>0; i++) {
        SinglyLinkedList_removeNode(list->header);
    }
}

// 리스트 자체 삭제
void SinglyLinkedList_putList(SinglyLinkedList* list) {
    SinglyLinkedList_removeAll(list);
    SinglyLinkedNode_putnode(list->trailer);
    SinglyLinkedNode_putnode(list->header);
    free(list);
}
// #endif