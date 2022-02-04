import re
from xml.dom.minidom import Element
from DataStructures.SequentialHeap import SequentialHeap

def InplaceHeapSort_Insertion(orderType):
    N = input("How Many keys(or elements) do you want?")
    heap = SequentialHeap(orderType)

    # Phase 1: Build Heap
    print("input keys and elements(key element)")
    for i in range(1, N+1):
        key, element = input().split()
        if orderType == "Ascending":
            heap.insertItem_minHeap(key, element)
        elif orderType == "Descending":
            heap.insertItem_maxHeap(key, element)
        else:
            return
    
    # Phase 2
    if orderType == "Ascending":
        for i in range(N, 1, -1):
            heap.swap(heap.keys[1], heap.keys[i])
            heap.n -= 1
            heap.downHeap_minHeap(heap.keys[1])
        heap.n = N
    elif orderType == "Descending":
        for i in range(N, 1, -1):
            heap.swap(heap.keys[1], heap.keys[i])
            heap.n -= 1
            heap.downHeap_maxHeap(heap.keys[1])
        heap.n = N
    else:
            return
    return heap

# Bottom Up
def InplaceHeapSort_BottomUp_Recursive(orderType):
    N = input("How Many keys(or elements) do you want?")
    heap = SequentialHeap(orderType)

    # Phase 1: Build Heap
    print("input keys and elements(key element)")
    for i in range(1, N+1):
        key, element = input().split()
        heap.keys[i] = key
        heap.elements[key] = element
    if orderType == "Ascending":
        heap.recursiveBuildHeap_minHeap()
    elif orderType == "Descending":
        heap.recursiveBuildHeap_maxHeap()
    else:
        return
    
    # Phase 2
    if orderType == "Ascending":
        for i in range(N, 1, -1):
            heap.swap(heap.keys[1], heap.keys[i])
            heap.n -= 1
            heap.downHeap_minHeap(heap.keys[1])
        heap.n = N
    elif orderType == "Descending":
        for i in range(N, 1, -1):
            heap.swap(heap.keys[1], heap.keys[i])
            heap.n -= 1
            heap.downHeap_maxHeap(heap.keys[1])
        heap.n = N
    else:
            return
    return heap

def InplaceHeapSort_BottomUp_nonRecursive(orderType):
    N = input("How Many keys(or elements) do you want?")
    heap = SequentialHeap(orderType)

    # Phase 1: Build Heap
    print("input keys and elements(key element)")
    for i in range(1, N+1):
        key, element = input().split()
        heap.keys[i] = key
        heap.elements[key] = element
    if orderType == "Ascending":
        heap.nonRecursiveBuildHeap_minHeap()
    elif orderType == "Descending":
        heap.nonRecursiveBuildHeap_maxHeap()
    else:
        return
    
    # Phase 2
    if orderType == "Ascending":
        for i in range(N, 1, -1):
            heap.swap(heap.keys[1], heap.keys[i])
            heap.n -= 1
            heap.downHeap_minHeap(heap.keys[1])
        heap.n = N
    elif orderType == "Descending":
        for i in range(N, 1, -1):
            heap.swap(heap.keys[1], heap.keys[i])
            heap.n -= 1
            heap.downHeap_maxHeap(heap.keys[1])
        heap.n = N
    else:
            return
    return heap