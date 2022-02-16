package Algorithms

import (
	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/DataStructures"
	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"
)

// orderType: 오름차순(Ascending), 내림차순(Descending)
func (list *DoublyLinkedList) QuickSort(orderType string) {
	list.InPlaceQuickSort(0, list.Size, orderType)
}

func (list *DoublyLinkedList) InPlaceQuickSort(left, right int, orderType string) {
	if left >= right {
		return
	}
	k := FindPivot(left, right)
	index, err := list.inPlacePartition(left, right, k, orderType)
	if err != nil {
		utils.HandleErr(err)
	}
	list.InPlaceQuickSort(left, index-1, orderType)
	list.InPlaceQuickSort(index+1, right, orderType)
}

func (list *DoublyLinkedList) inPlacePartition(left, right, k int, orderType string) (int, error) {
	// sort by key
	pivotValue := list.FindNode(k).Key
	DataStructures.Swap_DoublyLinkedNode(list.FindNode(k), list.FindNode(right))
	i := left
	j := right
	for i <= j {
		if orderType == "Ascending" { // 오름차순(Ascending)
			for i <= j && list.FindNode(i).Key <= pivotValue {
				i++
			}
			for j >= i && list.FindNode(j).Key >= pivotValue {
				j++
			}
		} else if orderType == "Descending" { // 내림차순(Descending)
			for i <= j && list.FindNode(i).Key >= pivotValue {
				i++
			}
			for j >= i && list.FindNode(j).Key <= pivotValue {
				j++
			}
		} else {
			return -1, utils.WrongOrderTypeException()
		}
		if i < j {
			DataStructures.Swap_DoublyLinkedNode(list.FindNode(i), list.FindNode(j))
		}
	}
	DataStructures.Swap_DoublyLinkedNode(list.FindNode(i), list.FindNode(right))
	return i, nil

	// sort by element
	// pivotValue := list.FindNode(k).Element
	// DataStructures.Swap_DoublyLinkedNode(list.FindNode(k), list.FindNode(right))
	// i := left
	// j := right
	// for i <= j {
	// 	if orderType == "Ascending" { // 오름차순(Ascending)
	// 		for i <= j && list.FindNode(i).Element <= pivotValue {
	// 			i++
	// 		}
	// 		for j >= i && list.FindNode(j).Element >= pivotValue {
	// 			j++
	// 		}
	// 	} else if orderType == "Descending" { // 내림차순(Descending)
	// 		for i <= j && list.FindNode(i).Element >= pivotValue {
	// 			i++
	// 		}
	// 		for j >= i && list.FindNode(j).Element <= pivotValue {
	// 			j++
	// 		}
	// 	} else {
	// 		return -1, utils.WrongOrderTypeException()
	// 	}
	// 	if i < j {
	// 		DataStructures.Swap_DoublyLinkedNode(list.FindNode(i), list.FindNode(j))
	// 	}
	// }
	// DataStructures.Swap_DoublyLinkedNode(list.FindNode(i), list.FindNode(right))
	// return i, nil
}
