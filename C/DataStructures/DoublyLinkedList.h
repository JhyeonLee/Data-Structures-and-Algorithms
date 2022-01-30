#pragma once
// #ifdef __ARRAYLISTS_H_
// #define __ARRAYLISTS_H_
#include <stdio.h>
#include<stdlib.h>
#include "../utils/utils.h"
#include "./DoublyLinkedNode.h"

typedef struct DoublyLinkedList {
    DoublyLinkedNode* headNode;
    DoublyLinkedNode* tailNode;
    DoublyLinkedNode* header;
    DoublyLinkedNode* trailer;
} DoublyLinkedList;

DoublyLinkedList DoublyLinkedList_initialize(){
    DoublyLinkedList newlist;
    newlist.headNode = NULL;
    newlist.tailNode = NULL;
    newlist.header = DoublyLinkedNode_getnode();
    newlist.trailer = DoublyLinkedNode_getnode();
    newlist.header->nextlink = newlist.trailer;
    newlist.trailer->previouslink = newlist.header;
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
int isEmpty(DoublyLinkedList* list) {
    return DoublyLinkedList_size(list) == 0;
}

// 순위 r에 저장된 원소를 반환
int DoublyLinkedList_get(DoublyLinkedList* list, int r){
    if ( r < 1 || DoublyLinkedList_size(list) < r) {
        return invalidRankException();
    }
    DoublyLinkedNode* p = list->header;
    for(int i = 0; i <r; i++){
        p = p->nextlink;
    }
    return p->element;
}

// 순위 r에 저장된 원소를 e로 대체
int DoublyLinkedList_set(DoublyLinkedList* list, int r, int e){
    if (r < 1 || DoublyLinkedList_size(list) < r) {
        return invalidRankException();
    }
    DoublyLinkedNode* p = list->header;
    for(int i = 0; i<r; i++){
        p = p->nextlink;
    }
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
void DoublyLinkedList_addNodeBefore(DoublyLinkedNode* p, int e){
    DoublyLinkedNode* q = DoublyLinkedNode_getnode();
    q->element = e;
    q->previouslink = p->previouslink;
    q->nextlink = p;
    (p->previouslink)->nextlink = q;
    p->previouslink = q;
}

// 순위 r에 원소가 e인 노드 삽입
void DoublyLinkedList_add(DoublyLinkedList* list, int r, int e) {
    if (r < 1 || DoublyLinkedList_size(list) < r) {
        invalidRankException();
        return;
    }
    DoublyLinkedNode* p = list->header;
    for(int i = 0; i<r; i++){
        p = p->nextlink;
    }
    DoublyLinkedList_addNodeBefore(p, e);
    // size += 1;
}

// 노드 p 삭제
int DoublyLinkedList_removeNode(DoublyLinkedNode* p){
    int e = p->element;
    (p->previouslink)->nextlink = p->nextlink;
    (p->nextlink)->previouslink = p->previouslink;
    DoublyLinkedNode_putnode(p);
    return e;
}

// 순위 r에 저장된 원소를 삭제하여 반환
int DoublyLinkedList_remove(DoublyLinkedList* list, int r){
    if (r < 1 || DoublyLinkedList_size(list) < r) {
        return invalidRankException();
    }
    DoublyLinkedNode* p = list->header;
    for(int i = 0; i<r; i++){
        p = p->nextlink;
    }
    int e = DoublyLinkedList_removeNode(p);
    // size -= 1;
    return e;
}

// 헤더와 트레일러 이외 모든 원소 삭제
void DoublyLinkedList_removeAll(DoublyLinkedList* list){
    if (isEmpty(list)) {
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