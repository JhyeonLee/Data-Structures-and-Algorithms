package Algorithms

import (
	"math/rand"

	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/DataStructures"
)

func FindPivot(left, right int) int {
	return rand.Intn(right)%(right-left+1) + left
}

// 구조체 임베딩
type ArrayList struct {
	DataStructures.ArrayList
}
type SinglyLinkedNode struct {
	DataStructures.SinglyLinkedNode
}
type SinglyLinkedList struct {
	DataStructures.SinglyLinkedList
}
type DoublyLinkedNode struct {
	DataStructures.DoublyLinkedNode
}
type DoublyLinkedList struct {
	DataStructures.DoublyLinkedList
}
type LinkedPriorityQueue struct {
	DataStructures.LinkedPriorityQueue
}
type SequentialHeap struct {
	DataStructures.SequentialHeap
}
type LinkedHeap struct {
	DataStructures.LinkedHeap
}
