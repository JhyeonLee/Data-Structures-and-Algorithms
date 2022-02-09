package Algorithms

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/DataStructures"

// orderType: 오름차순(Ascending, 1), 내림차순(Descending, 2)
func (list *SinglyLinkedList) MergeSort(orderType string) {
	list.rMergeSort(orderType)
}
func (list *SinglyLinkedList) rMergeSort(orderType string) {
	if list.Size > 1 {
		partitionedList := DataStructures.Initialize_SinglyLinkedList()
		list.rMergeSort(orderType)
		partitionedList.rMergeSort(orderType)
		merge(list, partitionedList, orderType)
	}
}
func merge(left, right *SinglyLinkedList, orderType string) {

}
