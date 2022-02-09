package Algorithms

import (
	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/DataStructures"
	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"
)


func (list *ArrayList) PQ_Sort() {
	Pq := DataStructures.Initialize_SequentialPriorityQueue()
	for !list.IsEmpty() {
		e, err := list.RemoveFirst()
		if err != nil {
			utils.HandleErr(err)
		}
		Pq.InsertItem(e, e)
	}
	for !Pq.IsEmpty() {
		e, err := Pq.RemoveMin()
		if err != nil {
			utils.HandleErr(err)
		}
		list.AddLast(e)
	}
}

func (list *ArrayList) InPlaceSelectionSort() {
	for pass := 0; pass <= list.Size()-2; pass++ {
		min := pass
		for j := pass + 1; pass <= list.Size()-1; j++ {
			if list.Elements[j] < list.Elements[min] {
				min = j
			}
		}
		list.Swap(pass, min)
	}
}

func (list *ArrayList) InPlaceInsertionSort() {
	for pass := 1; pass <= list.Size()-1; pass++ {
		save := list.Elements[pass]
		j := pass - 1
		for ; j >= 0 && list.Elements[j] > save; j-- {
			list.Elements[j+1] = list.Elements[j]
		}
		list.Elements[j+1] = save
	}
}
