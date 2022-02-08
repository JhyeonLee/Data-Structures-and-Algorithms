#pragma once
// #ifdef __SEQUENTIALSORT_H__
// #define __SEQUENTIALSORT_H__
#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include "../DataStructures/SequentialPriorityQueue.h"

// 우선순위 큐를 이용한 정렬
void Sequential_PQ_Sort(ArrayList* list) {
    SequentialPriorityQueue* Pq = SequentialPriorityQueue_initialize(ArrayList_size(list));
    if (Pq == NULL) {
        return;
    }
    while (!ArrayList_isEmpty(list)) {
        int e = ArrayList_removeFirst(list);
        SequentialPriorityQueue_insertItem(Pq, e, e);
    }
    while (!SequentialPriorityQueue_isEmpty(Pq)) {
        int e = SequentialPriorityQueue_removeMin(Pq);
        ArrayList_addLast(list, e);
    }
}

// 제자리 선택 정렬
void Sequential_inPlaceSelectionSort(ArrayList* list) {
    for(int pass = 0 ; pass <= ArrayList_size(list) - 2; pass++) {
        int min = pass;
        for(int j = pass +1; pass <= ArrayList_size(list) - 1; j++) {
            if (list->elements[j] < list->elements[min]) {
                min = j;
            }
        }
        ArrayList_swap(list, pass, min);
    }
}

// 제자리 삽입 정렬
void Sequential_inPlaceInsertionSort(ArrayList* list) {
    for (int pass = 1; pass <= ArrayList_size(list) - 1; pass++) {
        int save = list->elements[pass];
        int j = pass - 1;
        for ( ; j>= 0 && list->elements[j] > save; j--) {
            list->elements[j+1] = list->elements[j];
        }
        list->elements[j+1] = save;
    }
}

// #endif