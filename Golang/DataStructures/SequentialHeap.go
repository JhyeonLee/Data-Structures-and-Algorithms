package DataStructures

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

type SequentialHeap struct {
	Keys        []int
	Elements    map[int]int
	N           int
	typeOfOrder string
}

func Initialize_SequentialHeap(typeOfOrder string) *SequentialHeap {
	heap := &SequentialHeap{
		N:           0,
		typeOfOrder: typeOfOrder,
	}
	heap.Keys = append(heap.Keys, 0) // 0번째는 사용하지 않음
	heap.Elements = make(map[int]int)
	return heap
}

func (H *SequentialHeap) IsRoot(k int) bool {
	return k == H.Keys[0]
}

func (H *SequentialHeap) Parent(k int) (int, error) {
	index := utils.FindIndex(H.Keys, k)
	if index == -1 {
		return -1, utils.IsNotElement()
	}
	return H.Keys[index/2], nil
}

func (H *SequentialHeap) IsExternal(k int) bool {
	index := utils.FindIndex(H.Keys, k)
	return index == -1
}
func (H *SequentialHeap) IsInternal(k int) bool {
	index := utils.FindIndex(H.Keys, k)
	return index != -1
}

func (H *SequentialHeap) LeftChild(k int) (int, error) {
	index := utils.FindIndex(H.Keys, k)
	if index == -1 {
		return -1, utils.IsNotElement()
	}
	index = 2 * index
	if H.IsExternal(H.Keys[index]) {
		return -2, utils.IsNotElement()
	}

	return H.Keys[index], nil
}

func (H *SequentialHeap) RightChild(k int) (int, error) {
	index := utils.FindIndex(H.Keys, k)
	if index == -1 {
		return -1, utils.IsNotElement()
	}
	index = 2*index + 1
	if H.IsExternal(H.Keys[index]) {
		return -2, utils.IsNotElement()
	}
	return H.Keys[index], nil
}

func (H *SequentialHeap) Swap(k1, k2 int) {
	index1 := utils.FindIndex(H.Keys, k1)
	if index1 == -1 {
		utils.HandleErr(utils.IsNotElement())
	}
	index2 := utils.FindIndex(H.Keys, k2)
	if index2 == -1 {
		utils.HandleErr(utils.IsNotElement())
	}

	H.Keys[index1] = k2
	H.Keys[index2] = k1
}

func (H *SequentialHeap) UpHeap_minHeap(k int) {
	if H.IsRoot(k) {
		return
	}
	parent, err := H.Parent(k)
	if err != nil {
		utils.HandleErr(err)
	}
	if k <= parent {
		return
	}
	H.Swap(k, parent)
	H.UpHeap_minHeap(parent)
}
func (H *SequentialHeap) DownHeap_minHeap(k int) {
	LeftK, _ := H.LeftChild(k)
	RightK, _ := H.RightChild(k)
	if H.IsExternal(LeftK) && H.IsExternal(RightK) {
		return
	}
	smaller := LeftK
	if H.IsInternal(RightK) {
		if RightK < smaller {
			smaller = RightK
		}
	}
	if k <= smaller {
		return
	}
	H.Swap(k, smaller)
	H.DownHeap_minHeap(smaller)
}

func (H *SequentialHeap) InsertItem_minHeap(k, e int) {
	H.N++
	H.Keys = append(H.Keys, k)
	H.Elements[k] = e
	H.UpHeap_minHeap(k)
}
func (H *SequentialHeap) RemoveMin_minHeap() int {
	k := H.Keys[1]
	e := H.Elements[k]
	H.Keys[1] = H.Keys[H.N]
	H.Elements[1] = H.Elements[H.N]
	H.N--
	H.DownHeap_minHeap(H.Keys[1])
	return e
}

func (H *SequentialHeap) UpHeap_maxHeap(k int) {
	if H.IsRoot(k) {
		return
	}
	parent, err := H.Parent(k)
	if err != nil {
		utils.HandleErr(err)
	}
	if k >= parent {
		return
	}
	H.Swap(k, parent)
	H.UpHeap_maxHeap(parent)
}
func (H *SequentialHeap) DownHeap_maxHeap(k int) {
	LeftK, _ := H.LeftChild(k)
	RightK, _ := H.RightChild(k)
	if H.IsExternal(LeftK) && H.IsExternal(RightK) {
		return
	}
	bigger := LeftK
	if H.IsInternal(RightK) {
		if RightK >= bigger {
			bigger = RightK
		}
	}
	if k >= bigger {
		return
	}
	H.Swap(k, bigger)
	H.DownHeap_maxHeap(bigger)
}

func (H *SequentialHeap) InsertItem_maxHeap(k, e int) {
	H.N++
	H.Keys = append(H.Keys, k)
	H.Elements[k] = e
	H.UpHeap_maxHeap(k)
}
func (H *SequentialHeap) RemoveMin_maxHeap() int {
	k := H.Keys[1]
	e := H.Elements[k]
	H.Keys[1] = H.Keys[H.N]
	H.Elements[1] = H.Elements[H.N]
	H.N--
	H.DownHeap_maxHeap(H.Keys[1])
	return e
}

// Build Bottom-Up Sequential Heap
func (H *SequentialHeap) RecursiveBuildHeap_minHeap() {
	H.RBuildHeap_minHeap(H.Keys[1])
}
func (H *SequentialHeap) RBuildHeap_minHeap(k int) {
	index := utils.FindIndex(H.Keys, k)
	if index == -1 {
		return
	}
	LeftK, _ := H.LeftChild(index)
	H.RBuildHeap_minHeap(LeftK)
	RightK, _ := H.RightChild(index)
	H.RBuildHeap_minHeap(RightK)
	H.DownHeap_minHeap(k)
}

func (H *SequentialHeap) NonRecursiveBuildHeap_minHeap() {
	for i := H.N / 2; i >= 1; i-- {
		H.DownHeap_minHeap(H.Keys[i])
	}
}

func (H *SequentialHeap) RecursiveBuildHeap_maxHeap() {
	H.RBuildHeap_maxHeap(H.Keys[1])
}
func (H *SequentialHeap) RBuildHeap_maxHeap(k int) {
	index := utils.FindIndex(H.Keys, k)
	if index == -1 {
		return
	}
	LeftK, _ := H.LeftChild(index)
	H.RBuildHeap_maxHeap(LeftK)
	RightK, _ := H.RightChild(index)
	H.RBuildHeap_maxHeap(RightK)
	H.DownHeap_maxHeap(k)
}

func (H *SequentialHeap) NonRecursiveBuildHeap_maxHeap() {
	for i := H.N / 2; i >= 1; i-- {
		H.DownHeap_maxHeap(H.Keys[i])
	}
}
