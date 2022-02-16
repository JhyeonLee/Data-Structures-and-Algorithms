#pragma once
// #ifdef __SEQUENTIALQUICKSORT_H__
// #define __SEQUENTIALQUICKSORT_H__
#include "../DataStructures/ArrayList.h"

int SequentialQuickSort_findPivot(int left, int right) {
	return rand() % (right - left + 1) + left;
}
int SequentialQuickSort_inPlacePartition(ArrayList* list, int left, int right, int k, int orderType) {
	int pivotValue = list->elements[k];
	ArrayList_swap(list, k, right);
	int i = left;
	int j = right - 1;
	while (i <= j) {
        if (orderType == 1){ // 오름차순(Ascending, 1)
            while (i <= j && list->elements[i] <= pivotValue) {
			    i++;
            }
            while (j >= i && list->elements[j] >= pivotValue) {
                j--;
            }
        } else if (orderType == 2) { // 내림차순(Descending, 2)
            while (i <= j && list->elements[i] >= pivotValue) {
			    i++;
            }
            while (j >= i && list->elements[j] <= pivotValue) {
                j--;
            }
        } else {
            return wrongOrderTypeException();
        }
		
		if (i < j) {
			ArrayList_swap(list, i, j);
		}
	}
	ArrayList_swap(list, i, right);
	return i;
}

// orderType: 오름차순(Ascending, 1), 내림차순(Descending, 2)
void SequentialQuickSort(ArrayList* list, int orderType) {
    SequentialInPlaceQuickSort(list, 0, ArrayList_size(list), orderType);
}

void SequentialInPlaceQuickSort(ArrayList* list, int left, int right, int orderType) {
    if (left >= right) {
        return;
    }
    int k = SequentialQuickSort_findPivot(left, right);
    int index = SequentialQuickSort_inPlacePartition(list, left, right, k, orderType);
    if (index == -1) {
        return;
    }
	SequentialInPlaceQuickSort(list, left, index - 1, orderType);
	SequentialInPlaceQuickSort(list, index + 1, right, orderType);
}

// #endif