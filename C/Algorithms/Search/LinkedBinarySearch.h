#pragma once
// #ifdef __LINKEDBINARYSEARCH_H__
// #define __LINKEDBINARYSEARCH_H__
#include "../DataStructures/DoublyLinkedList.h"

// 정렬이 되어있을 경우
int FindElement_recursive(DoublyLinkedList* list, int k) {
    if (k < list->headNode->key || list->tailNode->key < k) {
        return noSuchKey();
    }
    return rFindElement_recursive(list, k, 0, list->size);
}
int rFindElement_recursive(DoublyLinkedList* list, int k, int left, int right) {
    if (left > right) {
		return noSuchKey();
	}
    int m =  (left + right) / 2;
    DoublyLinkedNode* mid = DoublyLinkedList_findNode(list, m);
	if (k == mid->key) {
		return mid->element;
	}
	else if (k < mid->key) {
		return rFindElement_recursive(list, k, left, m - 1);
	}
	else { // k > mid->key
		return rFindElement_recursive(list, k, m + 1, right);
	}
}

int FindElement_nonRecursive(DoublyLinkedList* list, int k) {
    int left = 0;
	int right = list->size - 1;
	if (k < list->headNode->key || list->tailNode->key < k) {
        return noSuchKey();
    }

	for(;;) {
		if (left > right) {
			return noSuchKey();
		}
        int m =  (left + right) / 2;
        DoublyLinkedNode* mid = DoublyLinkedList_findNode(list, m);
		if (k == mid->key) {
		return mid->element;
	}
		else if (k < mid->key) {
			right = m - 1;
		}
		else { // k > mid->key
			left = m + 1;
		}
	}
}

// #endif