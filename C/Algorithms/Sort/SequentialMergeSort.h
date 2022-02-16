#pragma once
// #ifdef __SEQUENTIALMERGESORT_H__
// #define __SEQUENTIALMERGESORT_H__
#include "../DataStructures/ArrayList.h"

// orderType: 오름차순(Ascending, 1), 내림차순(Descending, 2)
void SequentialMergeSort(ArrayList* list, int orderType) {
    SequentialRMergeSort(list, list->front, list->last, orderType);
}

void SequentialRMergeSort(ArrayList* list, int left, int right, int orderType) {
    if (left < right) {
        int m = (left + right) /2; // 분할(divide)
        SequentialRMergeSort(list, left, m, orderType); // 재귀(recur)
        SequentialRMergeSort(list, m, right, orderType); // 재귀(recur)
        SequentialMerge(list, left, m, right, orderType); // 통치(concquer)
    }
}

void SequentialMerge(ArrayList* list, int left, int middle, int right, int orderType) {
    int i = left;
    int k = left;
    int j = middle + 1;
    int* B = (int*)malloc((right - left + 1) * sizeof(int));
	if (B == NULL) {
		printf("Not Enough Memory");
		return;
	}
    
    while (i <= middle && j <= right) {
        // 오름차순(Ascending)
        if (orderType == 1) {
            if (list->elements[i] <= list->elements[j]) {
                B[k - left] = list->elements[i];
                k++;
                i++;
            } else {
                B[k - left] = list->elements[j];
                k++;
                j++;
            }
        } else if (orderType == 2) { // 내림차순(Descending)
            if (list->elements[i] >= list->elements[j]) {
                B[k - left] = list->elements[i];
                k++;
                i++;
            } else {
                B[k - left] = list->elements[j];
                k++;
                j++;
            }
        } else {
            wrongOrderTypeException();
            return;
        }
    }
    while (i <= middle) {
        B[k - left] = list->elements[i];
        k++;
        i++;
    }
    while (j <= right) {
        B[k - left] = list->elements[j];
        k++;
        j++;
    }
    for(k = left; k <= right; k++) {
        list->elements[k] = B[k - left];
    }
}

// #endif