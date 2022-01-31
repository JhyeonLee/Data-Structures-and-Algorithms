// Array Lists

#pragma once
// #ifdef __ARRAYLISTS_H_
// #define __ARRAYLISTS_H_
#include<stdlib.h>
#include "../utils/utils.h"

typedef struct ArrayList { // 원형 배열
    int* elements; // 원소들
    int acceptableSize; // 배열 크기
    int front;
    int last;
} ArrayList;

// 크기가 n인 배열 리스트 초기화
ArrayList* ArrayList_initialize(int n){
    ArrayList* newList = (ArrayList*)malloc(sizeof(ArrayList));
    if (newList == NULL){
        notEnoughMemory();
        return NULL;
    }
    newList->elements = (int*)malloc(sizeof(n));
    if (newList->elements == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newList->acceptableSize = n;
    newList->front = 0;
    newList->last = 0;
    return newList;
}

// 리스트의 크기, 즉 원소 수 반환
int ArrayList_size(ArrayList* list){
    return (list->acceptableSize - list->front + list->last + 1) % list->acceptableSize;
}
// 리스트가 비어 있는지 여부를 반환
int ArrayList_isEmpty(ArrayList* list){
    if (ArrayList_size(list) == 0){
        return 1; // 리스트는 비어 있다
    }
    else {
        return 0;
    }
}
// 원소 전체를 반환
int* ArrayList_elements(ArrayList* list){
    return list->elements;
}
// 순위 r에 저장된 원소를 반환
int ArrayList_get(ArrayList* list, int r){
    if (r < 0 || r > list->acceptableSize) {
        return invalidRankException();
    }
    return list->elements[(list->front + r) % list->acceptableSize];
}
// 순위 r에 저장된 원소를 e로 대체
int ArrayList_set(ArrayList* list, int r, int e) {
    if (r < 0 || r > list->acceptableSize) {
        return invalidRankException();
    }
    list->elements[(list->front + r) % list->acceptableSize] = e;
    return e;
}
// 순위 r 앞에 원소 e를 삽입
int ArrayList_add(ArrayList* list, int r, int e) {
    int n = ArrayList_size(list);
    if (n == list->acceptableSize) {
        return fullListException();
    }
    if (r < 0 || r > n) {
        return invalidRankException();
    }
    if (r < n/2) {
        for(int i = list->front; i <= (list->front + r - 1) % list->acceptableSize; i++) {
            list->elements[(i-1) % list->acceptableSize] = list->elements[i];
        }
        list->elements[(list->front + r - 1) % list->acceptableSize] = e;
        list->front = (list->front - 1) % list->acceptableSize;
    } else {
        for(int i = list->last; i >= (list->front + r) % list->acceptableSize; i--) {
            list->elements[(i+1) % list->acceptableSize] = list->elements[i];
        }
        list->elements[(list->front + r) % list->acceptableSize] = e;
        list->last = (list->last + 1) % list->acceptableSize;
    }
}
// 순위 r에 저장된 원소를 삭제하여 반환
int ArrayList_remove(ArrayList* list, int r) {
    int n = ArrayList_size(list);
    if (n == 0) {
        return emptyListException();
    }
    if (r < 0 || r >= list->acceptableSize) {
        return invalidRankException();
    }
    int e = list->elements[(list->front + r) % list->acceptableSize];
    if ( r < n/2 ) {
        for(int i = (list->front + r - 1) % list->acceptableSize; i >= list->front; i--) {
            list->elements[(i + 1) % list->acceptableSize] = list->elements[i];
        }
        list->front = (list->front + 1) % list->acceptableSize;
    } else {
        for(int i = (list->front + r + 1) % list->acceptableSize; i <= list->last; i++) {
            list->elements[(i - 1) % list->acceptableSize] = list->elements[i];
        }
        list->last = (list->last - 1) % list->acceptableSize;
    }
    return e;
}

// #endif