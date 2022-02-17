#pragma once
// #ifdef __SEQUENTIALBINARYSEARCH_H__
// #define __SEQUENTIALBINARYSEARCH_H__
#include "../DataStructures/ArrayList.h"

// 정렬이 되어있을 경우
int FindIndex_recursive(ArrayList* list, int k) {
    if (k < list->elements[0] || list->elements[ArrayList_size(list)-1] < k) {
        return noSuchKey();
    }
    return rFindIndex(list, k, 0, ArrayList_size(list));
}
int rFindIndex(ArrayList* list, int k, int left, int right) {
    if (left > right) {
		return noSuchKey();
	}
	int mid = (left + right) / 2;
	if (k == list->elements[mid]) {
		return mid;
	}
	else if (k < list->elements[mid]) {
		return rFindIndex(list, k, left, mid - 1);
	}
	else { // k > list->elements[mid]
		return rFindIndex(list, k, mid + 1, right);
	}
}

int FindIndex_nonRecursive(ArrayList* list, int k) {
    int left = 0;
	int right = ArrayList_size(list) - 1;
	if (k < list->elements[0] || list->elements[0] < k) {
        return noSuchKey();
    }

	for(;;) {
		if (left > right) {
			return noSuchKey();
		}

		int mid = (left + right) / 2;
		if (k == list->elements[mid]) {
		return mid;
	}
		else if (k < list->elements[mid]) {
			right = mid - 1;
		}
		else { // k > list->elements[mid]
			left = mid + 1;
		}
	}
}

// #endif