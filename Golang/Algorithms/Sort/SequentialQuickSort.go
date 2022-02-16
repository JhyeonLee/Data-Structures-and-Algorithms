package Algorithms

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

// orderType: 오름차순(Ascending), 내림차순(Descending)
func (list *ArrayList) QuickSort(orderType string) {
	list.InPlaceQuickSort(0, list.Size(), orderType)
}

func (list *ArrayList) InPlaceQuickSort(left, right int, orderType string) {
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

func (list *ArrayList) inPlacePartition(left, right, k int, orderType string) (int, error) {
	pivotValue := list.Elements[k]
	list.Swap(k, right)
	i := left
	j := right
	for i <= j {
		if orderType == "Ascending" { // 오름차순(Ascending)
			for i <= j && list.Elements[i] <= pivotValue {
				i++
			}
			for j >= i && list.Elements[j] >= pivotValue {
				j++
			}
		} else if orderType == "Descending" { // 내림차순(Descending)
			for i <= j && list.Elements[i] >= pivotValue {
				i++
			}
			for j >= i && list.Elements[j] <= pivotValue {
				j++
			}
		} else {
			return -1, utils.WrongOrderTypeException()
		}

		if i < j {
			list.Swap(i, j)
		}
	}
	list.Swap(i, right)
	return i, nil
}
