package Algorithms

import (
	"fmt"

	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/DataStructures"
)

type SequentialHeap struct {
	DataStructures.SequentialHeap
}

// order Type: Ascending(min Heap), Descending(max Heap)
func InplaceSequentialHeapSort_Insertion(orderType string) *DataStructures.SequentialHeap {
	var N int
	fmt.Println("How Many keys(or elements) do you want?")
	fmt.Scan(&N)
	heap := DataStructures.Initialize_SequentialHeap(orderType)

	// Phase 1: Build Heap
	fmt.Println("input keys and elements(key element)")
	var key, element int
	for i := 1; i <= N; i++ {
		fmt.Scan(&key, &element)
		if orderType == "Ascending" {
			heap.InsertItem_minHeap(key, element)
		} else if orderType == "Descending" {
			heap.InsertItem_maxHeap(key, element)
		} else {
			return nil
		}
	}

	// Phase 2
	if orderType == "Ascending" {
		for i := N; i >= 2; i-- {
			heap.Swap(heap.Keys[1], heap.Keys[i])
			heap.N--
			heap.DownHeap_minHeap(heap.Keys[1])
		}
		heap.N = N
	} else if orderType == "Descending" {
		for i := N; i >= 2; i-- {
			heap.Swap(heap.Keys[1], heap.Keys[i])
			heap.N--
			heap.DownHeap_maxHeap(heap.Keys[1])
		}
		heap.N = N
	} else {
		return nil
	}
	return heap
}

// Bottom Up
func InplaceSequentialHeapSort_BottomUp_Recursive(orderType string) *DataStructures.SequentialHeap {
	var N int
	fmt.Println("How Many keys(or elements) do you want?")
	fmt.Scan(&N)
	heap := DataStructures.Initialize_SequentialHeap(orderType)

	// Phase 1: Build Heap
	fmt.Println("input keys and elements(key element)")
	var key, element int
	for i := 1; i <= N; i++ {
		fmt.Scan(&key, &element)
		heap.Keys[i] = key
		heap.Elements[key] = element
	}
	if orderType == "Ascending" {
		heap.RecursiveBuildHeap_minHeap()
	} else if orderType == "Descending" {
		heap.RecursiveBuildHeap_maxHeap()
	} else {
		return nil
	}

	// Phase 2
	if orderType == "Ascending" {
		for i := N; i >= 2; i-- {
			heap.Swap(heap.Keys[1], heap.Keys[i])
			heap.N--
			heap.DownHeap_minHeap(heap.Keys[1])
		}
		heap.N = N
	} else if orderType == "Descending" {
		for i := N; i >= 2; i-- {
			heap.Swap(heap.Keys[1], heap.Keys[i])
			heap.N--
			heap.DownHeap_maxHeap(heap.Keys[1])
		}
		heap.N = N
	} else {
		return nil
	}

	return heap
}

func InplaceSequentialHeapSort_BottomUp_nonRecursive(orderType string) *DataStructures.SequentialHeap {
	var N int
	fmt.Println("How Many keys(or elements) do you want?")
	fmt.Scan(&N)
	heap := DataStructures.Initialize_SequentialHeap(orderType)

	// Phase 1: Build Heap
	fmt.Println("input keys and elements(key element)")
	var key, element int
	for i := 1; i <= N; i++ {
		fmt.Scan(&key, &element)
		heap.Keys[i] = key
		heap.Elements[key] = element
	}
	if orderType == "Ascending" {
		heap.NonRecursiveBuildHeap_minHeap()
	} else if orderType == "Descending" {
		heap.NonRecursiveBuildHeap_maxHeap()
	} else {
		return nil
	}

	// Phase 2
	if orderType == "Ascending" {
		for i := N; i >= 2; i-- {
			heap.Swap(heap.Keys[1], heap.Keys[i])
			heap.N--
			heap.DownHeap_minHeap(heap.Keys[1])
		}
		heap.N = N
	} else if orderType == "Descending" {
		for i := N; i >= 2; i-- {
			heap.Swap(heap.Keys[1], heap.Keys[i])
			heap.N--
			heap.DownHeap_maxHeap(heap.Keys[1])
		}
		heap.N = N
	} else {
		return nil
	}

	return heap
}
