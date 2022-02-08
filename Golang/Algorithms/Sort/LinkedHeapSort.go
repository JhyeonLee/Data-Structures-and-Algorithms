package Algorithms

import (
	"fmt"

	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/DataStructures"
)

type LinkedHeap struct {
	DataStructures.LinkedHeap
}

func InplaceLinkedHeapSort_Insertion(orderType string) *DataStructures.LinkedHeap {
	N := 0
	heap := DataStructures.Initialize_LinkedHeap(orderType)
	// Phase 1: Build Heap
	fmt.Println("input keys and elements(key element).\n (-1 -1) concludes input phase.")
	var key, element int
	for {
		fmt.Scan(&key, &element)
		if key == -1 && element == -1 {
			break
		}
		if orderType == "Ascending" {
			heap.InsertItem_minHeap(key, element)
		} else if orderType == "Descending" {
			heap.InsertItem_maxHeap(key, element)
		} else {
			return nil
		}
		N++
	}
	heap.N = N

	// Phase 2
	if orderType == "Ascending" {
		lastnode := heap.LastNode()
		for i := heap.N; i >= 2; i-- {
			DataStructures.Swap_LinkedBinaryTreeNode(heap.Root, lastnode)
			(heap.Root).DownHeap_minHeap()
			lastnode = DataStructures.RetreatLastNode(heap, lastnode)
		}
		heap.N = N
	} else if orderType == "Descending" {
		lastnode := heap.LastNode()
		for i := heap.N; i >= 2; i-- {
			DataStructures.Swap_LinkedBinaryTreeNode(heap.Root, lastnode)
			(heap.Root).DownHeap_maxHeap()
			lastnode = DataStructures.RetreatLastNode(heap, lastnode)
		}
		heap.N = N
	} else {
		return nil
	}
	return heap
}

// Bottom UP
func InplaceLinkedHeapSort_BottomUp_Recursive(orderType string) *DataStructures.LinkedHeap {
	N := 0
	list := DataStructures.Initialize_SinglyLinkedList()
	// Phase 1: Build Heap
	fmt.Println("input keys and elements(key element).\n (-1 -1) concludes input phase.")
	var key, element int
	for {
		fmt.Scan(&key, &element)
		if key == -1 && element == -1 {
			break
		}
		list.AddLast(key, element)
		N++
	}
	var heap *DataStructures.LinkedHeap
	if orderType == "Ascending" {
		heap = DataStructures.RecursiveBuildHeap_minHeap(list, orderType)
	} else if orderType == "Descending" {
		heap = DataStructures.RecursiveBuildHeap_maxHeap(list, orderType)
	} else {
		return nil
	}
	heap.N = N

	// Phase 2
	if orderType == "Ascending" {
		lastnode := heap.LastNode()
		for i := heap.N; i >= 2; i-- {
			DataStructures.Swap_LinkedBinaryTreeNode(heap.Root, lastnode)
			(heap.Root).DownHeap_minHeap()
			lastnode = DataStructures.RetreatLastNode(heap, lastnode)
		}
		heap.N = N
	} else if orderType == "Descending" {
		lastnode := heap.LastNode()
		for i := heap.N; i >= 2; i-- {
			DataStructures.Swap_LinkedBinaryTreeNode(heap.Root, lastnode)
			(heap.Root).DownHeap_maxHeap()
			lastnode = DataStructures.RetreatLastNode(heap, lastnode)
		}
		heap.N = N
	} else {
		return nil
	}
	return heap
}
