package Algorithms

import (
	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/DataStructures"
	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"
)

// orderType: 오름차순(Ascending), 내림차순(Descending)
func (list *ArrayList) MergeSort(orderType string) {
	list.rMergeSort(list.Front, list.Last, orderType)
}
func (list *ArrayList) rMergeSort(left, right int, orderType string) {
	if left < right {
		m := (left + right) / 2
		list.rMergeSort(left, m, orderType)
		list.rMergeSort(m, right, orderType)
		list.merge(left, m, right, orderType)
	}
}
func (list *ArrayList) merge(left, middle, right int, orderType string) {
	i := left
	k := left
	j := middle
	B := DataStructures.Initialize_ArrayList()
	for i <= middle && j <= right {
		// 오름차순(Ascending)
		if orderType == "Ascending" {
			if list.Elements[i] <= list.Elements[j] {
				err := B.AddLast(list.Elements[i])
				if err != nil {
					utils.HandleErr(err)
				}
				k++
				i++
			} else {
				err := B.AddLast(list.Elements[j])
				if err != nil {
					utils.HandleErr(err)
				}
				k++
				j++
			}
		} else if orderType == "Descending" { // 내림차순(Descending)
			if list.Elements[i] >= list.Elements[j] {
				err := B.AddLast(list.Elements[i])
				if err != nil {
					utils.HandleErr(err)
				}
				k++
				i++
			} else {
				err := B.AddLast(list.Elements[j])
				if err != nil {
					utils.HandleErr(err)
				}
				k++
				j++
			}
		} else {
			return
		}
	}
	for i <= middle {
		err := B.AddLast(list.Elements[i])
		if err != nil {
			utils.HandleErr(err)
		}
		k++
		i++
	}
	for j <= middle {
		err := B.AddLast(list.Elements[j])
		if err != nil {
			utils.HandleErr(err)
		}
		k++
		j++
	}
	for k := left; !B.IsEmpty(); k++ {
		e, err := B.RemoveFirst()
		if err != nil {
			utils.HandleErr(err)
		}
		list.Elements[k] = e

	}
}
