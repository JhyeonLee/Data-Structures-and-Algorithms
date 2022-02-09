package Algorithms

import (
	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/DataStructures"
	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"
)

// 우선순위 큐를 이용한 정렬
func Linked_PQ_Sort(list *SinglyLinkedList) {
	Pq := DataStructures.LinkedPriorityQueue_initialize()
	for !list.IsEmpty() {
		node, err := list.RemoveFirst()
		if err != nil {
			utils.HandleErr(err)
		}
		Pq.InsertItem(node.Key, node.Element)
	}
	for !Pq.IsEmpty() {
		node, err := Pq.RemoveMin()
		if err != nil {
			utils.HandleErr(err)
		}
		list.AddLast(node.Key, node.Element)
	}
}

// 제자리 선택 정렬
func SinglyLinked_inPlaceSelectionSort(list *SinglyLinkedList) {
	for pass := list.HeadNode; pass != list.TailNode; pass = pass.Link {
		min := pass
		for j := pass.Link; j != list.TailNode; j = j.Link {
			// sort by key
			if j.Key < min.Key {
				min = j
			}
			// sort by element
			// if j.Element < min.Element {
			// 	min = j
			// }
		}
		DataStructures.Swap_SinglyLinkedNode(pass, min)
	}
}

func DoublyLinked_inPlaceSelectionSort(list *DoublyLinkedList) {
	for pass := list.HeadNode; pass != (list.TailNode).PreviousLink; pass = pass.NextLink {
		min := pass
		for j := pass.NextLink; j != list.TailNode; j = j.NextLink {
			// sort by key
			if j.Key < min.Key {
				min = j
			}
			// sort by element
			// if j.Element < min.Element {
			// 	min = j
			// }
		}
		DataStructures.Swap_DoublyLinkedNode(pass, min)
	}
}

// 제자리 삽입 정렬
func DoublyLinked_inPlaceInsertionSort(list *DoublyLinkedList) {
	for pass := list.HeadNode; pass != list.TailNode; pass = pass.NextLink {
		savedKey := pass.Key
		savedElement := pass.Element
		j := pass.PreviousLink
		// sort by key
		for ; j != list.Header && j.Key > savedKey; j = j.PreviousLink {
			(j.NextLink).Key = j.Key
			(j.NextLink).Element = j.Element
		}
		// sort by element
		// for j := pass.PreviousLink; j != list.Header && j.Element > savedElement; j = j.PreviousLink {
		// 	(j.NextLink).Key = j.Key
		// 	(j.NextLink).Element = j.Element
		// }
		(j.NextLink).Key = savedKey
		(j.NextLink).Element = savedElement
	}
}
