package Algorithms

import (
	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/DataStructures"
	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"
)

// orderType: 오름차순(Ascending, 1), 내림차순(Descending, 2)
func MergeSort_SinglyLinkedList(list *DataStructures.SinglyLinkedList, orderType string) {
	rMergeSort_SinglyLinkedList(list, orderType)
}
func rMergeSort_SinglyLinkedList(list *DataStructures.SinglyLinkedList, orderType string) {
	if list.Size > 1 {
		partitionedList := DataStructures.Initialize_SinglyLinkedList()
		rMergeSort_SinglyLinkedList(list, orderType)
		rMergeSort_SinglyLinkedList(partitionedList, orderType)
		merge_SinglyLinkedList(list, partitionedList, orderType)
	}
}
func merge_SinglyLinkedList(left, right *DataStructures.SinglyLinkedList, orderType string) {
	L := left.Header
	for L.Link != left.Trailer && !right.IsEmpty() {
		// sort Ascending by Key
		if orderType == "Ascending" {
			if L == left.Header && (left.HeadNode).Key > (right.HeadNode).Key {
				tmp, err := right.RemoveFirst()
				if err != nil {
					utils.HandleErr(err)
				}
				DataStructures.InsertNodeNext(L, tmp)
			} else if (L.Link).Key > (right.HeadNode).Key {
				tmp, err := right.RemoveFirst()
				if err != nil {
					utils.HandleErr(err)
				}
				DataStructures.InsertNodeNext(L, tmp)
			} else { // (L->link)->Key <= (right->headNode)->Key
				L = L.Link
			}
		} else if orderType == "Descending" { // sort Descending by Key
			if L == left.Header && (left.HeadNode).Key < (right.HeadNode).Key {
				tmp, err := right.RemoveFirst()
				if err != nil {
					utils.HandleErr(err)
				}
				DataStructures.InsertNodeNext(L, tmp)
			} else if (L.Link).Key < (right.HeadNode).Key {
				tmp, err := right.RemoveFirst()
				if err != nil {
					utils.HandleErr(err)
				}
				DataStructures.InsertNodeNext(L, tmp)
			} else { // (L->link)->Key >= (right->headNode)->Key
				L = L.Link
			}
		} else {
			return
		}

		// sort Ascending by Element
		// if orderType == "Ascending" {
		// 	if L == left.Header && (left.HeadNode).Element > (right.HeadNode).Element {
		// 		tmp, err := right.RemoveFirst()
		// 		if err != nil {
		// 			utils.HandleErr(err)
		// 		}
		// 		DataStructures.InsertNodeNext(L, tmp)
		// 	} else if (L.Link).Element > (right.HeadNode).Element {
		// 		tmp, err := right.RemoveFirst()
		// 		if err != nil {
		// 			utils.HandleErr(err)
		// 		}
		// 		DataStructures.InsertNodeNext(L, tmp)
		// 	} else { // (L->link)->Element <= (right->headNode)->Element
		// 		L = L.Link
		// 	}
		// } else if orderType == "Descending" { // sort Descending by Element
		// 	if L == left.Header && (left.HeadNode).Element < (right.HeadNode).Element {
		// 		tmp, err := right.RemoveFirst()
		// 		if err != nil {
		// 			utils.HandleErr(err)
		// 		}
		// 		DataStructures.InsertNodeNext(L, tmp)
		// 	} else if (L.Link).Element < (right.HeadNode).Element {
		// 		tmp, err := right.RemoveFirst()
		// 		if err != nil {
		// 			utils.HandleErr(err)
		// 		}
		// 		DataStructures.InsertNodeNext(L, tmp)
		// 	} else { // (L->link)->Element >= (right->headNode)->Element
		// 		L = L.Link
		// 	}
		// } else {
		// 	return
		// }
	}
	if !right.IsEmpty() {
		DataStructures.Concatenate_SinglyLinkedList(left, right)
	}
}

func MergeSort_DoublyLinkedList(list *DataStructures.DoublyLinkedList, orderType string) {
	rMergeSort_DoublyLinkedList(list, orderType)
}
func rMergeSort_DoublyLinkedList(list *DataStructures.DoublyLinkedList, orderType string) {
	if list.Size > 1 {
		partitionedList := DataStructures.Initialize_DoublyLinkedList()
		rMergeSort_DoublyLinkedList(list, orderType)
		rMergeSort_DoublyLinkedList(partitionedList, orderType)
		merge_DoublyLinkedList(list, partitionedList, orderType)
	}
}
func merge_DoublyLinkedList(left, right *DataStructures.DoublyLinkedList, orderType string) {
	L := left.HeadNode
	for L.NextLink != left.Trailer && !right.IsEmpty() {
		// sort Ascending by Key
		if orderType == "Ascending" {
			if L.Key > (right.HeadNode).Key {
				tmp, err := right.RemoveFirst()
				if err != nil {
					utils.HandleErr(err)
				}
				DataStructures.InsertNodeBefore(L, tmp)
			} else { // (L->link)->Key <= (right->headNode)->Key
				L = L.NextLink
			}
		} else if orderType == "Descending" { // sort Descending by Key
			if L.Key < (right.HeadNode).Key {
				tmp, err := right.RemoveFirst()
				if err != nil {
					utils.HandleErr(err)
				}
				DataStructures.InsertNodeBefore(L, tmp)
			} else { // (L->link)->Key >= (right->headNode)->Key
				L = L.NextLink
			}
		} else {
			return
		}

	}
	if !right.IsEmpty() {
		DataStructures.Concatenate_DoublyLinkedList(left, right)
	}
}
