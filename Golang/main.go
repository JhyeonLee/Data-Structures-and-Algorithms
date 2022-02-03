// Run Step
// 1. go run [파일명] ~> go run golang/main.go

package main

type SequentialHeap struct {
	keys       []int
	elements   map[int]int
	n          int
	typeOfHeap string
}

func Initialize_SequentialHeap(typeOfHeap string) *SequentialHeap {
	heap := &SequentialHeap{
		n:          0,
		typeOfHeap: typeOfHeap,
	}
	heap.elements = make(map[int]int)
	return heap
}

func (H *SequentialHeap) IsRoot(i int) {
	return i == 1
}

func main() {
}
