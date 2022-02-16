#pragma once
// #ifdef __DOUBLYLINKEDLIST_H__
// #define __DOUBLYLINKEDLIST_H__
#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include "./DoublyLinkedNode.h"

typedef struct DoublyLinkedList {
    DoublyLinkedNode* headNode;
    DoublyLinkedNode* tailNode;
    DoublyLinkedNode* header;
    DoublyLinkedNode* trailer;
    int size;
} DoublyLinkedList;

DoublyLinkedList* DoublyLinkedList_initialize(){
    DoublyLinkedList* newlist = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (newlist == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newlist->headNode = NULL;
    newlist->tailNode = NULL;
    newlist->header = DoublyLinkedNode_getnode();
    newlist->trailer = DoublyLinkedNode_getnode();
    newlist->size = 0;
    (newlist->header)->nextlink = newlist->trailer;
    (newlist->trailer)->previouslink = newlist->header;
    return newlist;
}

// 리스트의 크기, 즉 원소 수 반환
int DoublyLinkedList_size(DoublyLinkedList* list){
    int count = 0;
    if (list->headNode == NULL) {
        return count;
    }
    for(DoublyLinkedNode* p = list->headNode; p != list->trailer; p = p->nextlink){
        count += 1;
    }
    return count;
}

// 리스트가 비어 있는지 여부를 반환
int DoublyLinkedList_isEmpty(DoublyLinkedList* list) {
    return DoublyLinkedList_size(list) == 0;
}

void DoublyLinkedList_swap(DoublyLinkedNode* A, DoublyLinkedNode* B) {
    int k = A->key;
    A->key = B->key;
    B->key = k;

    int e = A->element;
    A->element = B->element;
    B->element = e;
}

// 순위 r에 있는 노드 반환
DoublyLinkedNode* DoublyLinkedList_findNode(DoublyLinkedList* list, int r) {
    DoublyLinkedNode* p = list->header;
    for(int i = 0; i <r; i++){
        p = p->nextlink;
    }
    return p;
}

// 노드의 순위 r 반환
int DoublyLinkedList_findRank(DoublyLinkedList* list, DoublyLinkedNode* node) {
    DoublyLinkedNode* p = list->header;
    int r = 0;
    for( ; p != list->trailer; p = p->nextlink) {
        r++;
        if (p == node) {
            return r;
        }
    }
    return invalidNodeException();
}

// 순위 r에 저장된 원소를 반환
int DoublyLinkedList_get(DoublyLinkedList* list, int r){
    if ( r < 1 || DoublyLinkedList_size(list) < r) {
        return invalidRankException();
    }
    DoublyLinkedNode* p = DoublyLinkedList_findNode(list, r);
    return p->element;
}

// 순위 r에 저장된 원소를 e로 대체
int DoublyLinkedList_set(DoublyLinkedList* list, int r, int e){
    if (r < 1 || DoublyLinkedList_size(list) < r) {
        return invalidRankException();
    }
    DoublyLinkedNode* p = DoublyLinkedList_findNode(list, r);
    p->element = e;
    return e;
}

// 원소 전체 순회
void DoublyLinkedList_traverse(DoublyLinkedList* list){
    for(DoublyLinkedNode* p = list->headNode; p != list->trailer; p = p->nextlink) {
        printf(" %d", p->element);
    }
    printf("\n");
}

// 노드 p 앞에 값이 e인 노드 삽입
void DoublyLinkedList_addNodeBefore(DoublyLinkedNode* p, int k, int e){
    DoublyLinkedNode* q = DoublyLinkedNode_getnode();
    q->key = k;
    q->element = e;
    q->previouslink = p->previouslink;
    q->nextlink = p;
    (p->previouslink)->nextlink = q;
    p->previouslink = q;
}

// 순위 r에 원소가 e인 노드 삽입
void DoublyLinkedList_add(DoublyLinkedList* list, int r, int k, int e) {
    if (r < 1 || DoublyLinkedList_size(list)+1 < r) {
        invalidRankException();
        return;
    }
    DoublyLinkedNode* p = DoublyLinkedList_findNode(list, r);
    DoublyLinkedList_addNodeBefore(p, k, e);
    list->size++;
}

// 리스트 가장 앞에(헤드 노드) 원소가 e인 노드 삽입
void DoublyLinkedList_addFirst(DoublyLinkedList* list, int k, int e) {
    DoublyLinkedList_add(list, 1, k, e);
}

// 리스트 가장 끝에(테일 노드) 원소가 e인 노드 삽입
void DoublyLinkedList_addLast(DoublyLinkedList* list, int k, int e) {
    DoublyLinkedList_add(list, DoublyLinkedList_size(list)+1, k, e);
}

void DoublyLinkedList_insertNodeBefore(DoublyLinkedNode* p, DoublyLinkedNode* q) {
    q->previouslink = p->previouslink;
    q->nextlink = p;
    (p->previouslink)->nextlink = q;
    p->previouslink = q;
}
void DoublyLinkedList_insertNodeAfter(DoublyLinkedNode* p, DoublyLinkedNode* q) {
    q->nextlink = p->nextlink;
    q->previouslink = p;
    (p->nextlink)->previouslink = q;
    p->nextlink = q;
}

DoublyLinkedList* DoublyLinkedList_concatenate(DoublyLinkedList* left, DoublyLinkedList* right) {
    (left->tailNode)->nextlink = right->headNode;
    (right->headNode)->previouslink = left->tailNode;
    DoublyLinkedNode_putnode(left->trailer);
    left->trailer = right->trailer;
    DoublyLinkedNode_putnode(right->header);
    left->size += right->size;
    return left;
}

DoublyLinkedList* DoublyLinkedList_Partition(DoublyLinkedList* list, int r) {
    DoublyLinkedNode* prev = DoublyLinkedList_findNode(list, r-1);
    DoublyLinkedNode* p = prev->nextlink;

    DoublyLinkedList* PartitionedList = DoublyLinkedList_initialize();
    (PartitionedList->header)->nextlink = p;    
    PartitionedList->headNode = p;
    p->previouslink = PartitionedList->header;
    PartitionedList->tailNode = list->tailNode;
    DoublyLinkedNode_putnode(PartitionedList->trailer);
    PartitionedList->trailer = list->trailer;

    list->trailer = DoublyLinkedNode_getnode();
    (list->trailer)->previouslink = prev;
    prev->nextlink = list->trailer;
    list->tailNode = prev;

    PartitionedList->size = list->size - r;
    list->size = r;
    return PartitionedList;
}

// 노드 p 삭제
DoublyLinkedNode* DoublyLinkedList_removeNode(DoublyLinkedNode* p){
    // int e = p->element;
    (p->previouslink)->nextlink = p->nextlink;
    (p->nextlink)->previouslink = p->previouslink;
    // DoublyLinkedNode_putnode(p);
    // return e;
    p->previouslink = NULL;
    p->nextlink = NULL;
    return p;
}

// 순위 r에 저장된 원소를 삭제하여 반환
DoublyLinkedNode* DoublyLinkedList_remove(DoublyLinkedList* list, int r){
    if (r < 1 || DoublyLinkedList_size(list) < r) {
        invalidRankException();
        return NULL;
    }
    DoublyLinkedNode* p = list->header;
    for(int i = 0; i<r; i++){
        p = p->nextlink;
    }
    // int e = DoublyLinkedList_removeNode(p);
    DoublyLinkedNode* e = DoublyLinkedList_removeNode(p);
    // size -= 1;
    list->size--;
    if (list->size == 0) {
        list->headNode = NULL;
        list->tailNode = NULL;
    }
    return e;
}

// 리스트 가장 앞에(헤드 노드) 원소가 e인 노드 삭제
DoublyLinkedNode* DoublyLinkedList_removeFirst(DoublyLinkedList* list) {
    return DoublyLinkedList_remove(list, 1);
}

// 리스트 가장 끝에(테일 노드) 원소가 e인 노드 삭제
DoublyLinkedNode* DoublyLinkedList_removeLast(DoublyLinkedList* list) {
    return DoublyLinkedList_remove(list, DoublyLinkedList_size(list));
}

// 헤더와 트레일러 이외 모든 원소 삭제
void DoublyLinkedList_removeAll(DoublyLinkedList* list){
    if (DoublyLinkedList_isEmpty(list)) {
        emptyListException();
        return;
    }
    for(int i = DoublyLinkedList_size(list); i>0; i++) {
        DoublyLinkedList_removeNode(list->header);
    }
}

// 리스트 자체 삭제
void DoublyLinkedList_putList(DoublyLinkedList* list){
    DoublyLinkedList_removeAll(list);
    DoublyLinkedNode_putnode(list->header);
    DoublyLinkedNode_putnode(list->trailer);
    free(list);
}

// #endif