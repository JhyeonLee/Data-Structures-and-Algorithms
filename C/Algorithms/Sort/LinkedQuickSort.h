#pragma once
// #ifdef __LINKEDQUICKSORT_H__
// #define __LINKEDQUICKSORT_H__
#include "../DataStructures/DoublyLinkedList.h"

int LinkedQuickSort_findPivot(int left, int right) {
	return rand() % (right - left + 1) + left;
}
int LinkedQuickSort_inPlacePartition(DoublyLinkedList* list, int left, int right, int k, int orderType) {
    // sort by key
	int pivotValue = DoublyLinkedList_findNode(list, k)->key;
	DoublyLinkedList_swap(DoublyLinkedList_findNode(list, k), DoublyLinkedList_findNode(list, right));
	int i = left;
	int j = right - 1;
	while (i <= j) {
        if (orderType == 1){ // 오름차순(Ascending, 1)
            while (i <= j && DoublyLinkedList_findNode(list, i)->key <= pivotValue) {
			    i++;
            }
            while (j >= i && DoublyLinkedList_findNode(list, j)->key >= pivotValue) {
                j--;
            }
        } else if (orderType == 2) { // 내림차순(Descending, 2)
            while (i <= j && DoublyLinkedList_findNode(list, i)->key >= pivotValue) {
			    i++;
            }
            while (j >= i && DoublyLinkedList_findNode(list, j)->key <= pivotValue) {
                j--;
            }
        } else {
            return wrongOrderTypeException();
        }
		
		if (i < j) {
            DoublyLinkedList_swap(DoublyLinkedList_findNode(list, i), DoublyLinkedList_findNode(list, j));
		}
	}
    DoublyLinkedList_swap(DoublyLinkedList_findNode(list, i), DoublyLinkedList_findNode(list, right));
	return i;

    // sort by element
	// int pivotValue = DoublyLinkedList_findNode(list, k)->element;
	// DoublyLinkedList_swap(DoublyLinkedList_findNode(list, k), DoublyLinkedList_findNode(list, right));
	// int i = left;
	// int j = right - 1;
	// while (i <= j) {
    //     if (orderType == 1){ // 오름차순(Ascending, 1)
    //         while (i <= j && DoublyLinkedList_findNode(list, i)->element <= pivotValue) {
	// 		    i++;
    //         }
    //         while (j >= i && DoublyLinkedList_findNode(list, j)->element >= pivotValue) {
    //             j--;
    //         }
    //     } else if (orderType == 2) { // 내림차순(Descending, 2)
    //         while (i <= j && DoublyLinkedList_findNode(list, i)->element >= pivotValue) {
	// 		    i++;
    //         }
    //         while (j >= i && DoublyLinkedList_findNode(list, j)->element <= pivotValue) {
    //             j--;
    //         }
    //     } else {
    //         return wrongOrderTypeException();
    //     }
		
	// 	if (i < j) {
    //         DoublyLinkedList_swap(DoublyLinkedList_findNode(list, i), DoublyLinkedList_findNode(list, j));
	// 	}
	// }
    // DoublyLinkedList_swap(DoublyLinkedList_findNode(list, i), DoublyLinkedList_findNode(list, right));
	// return i;
}

// orderType: 오름차순(Ascending, 1), 내림차순(Descending, 2)
void LinkedQuickSort(DoublyLinkedList* list, int orderType) {
    LinkedInPlaceQuickSort(list, 0, list->size, orderType);
}

void LinkedInPlaceQuickSort(DoublyLinkedList* list, int left, int right, int orderType) {
    if (left >= right) {
        return;
    }
    int k = LinkedQuickSort_findPivot(left, right);
    int index = LinkedQuickSort_inPlacePartition(list, left, right, k, orderType);
    if (index == NULL) {
        return;
    }
	LinkedInPlaceQuickSort(list, left, index - 1, orderType);
	LinkedInPlaceQuickSort(list, index + 1, right, orderType);
}

// #endif