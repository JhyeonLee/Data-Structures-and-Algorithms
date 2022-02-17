package Algorithms

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

// 정렬이 되어있을 경우
func (list *ArrayList) FindIndex_recursive(k int) (int, error) {
	if k < list.Elements[0] || list.Elements[list.Size()-1] < k {
		return -1, utils.NoSuchKey()
	}
	return list.rFindIndex(k, 0, list.Size())
}
func (list *ArrayList) rFindIndex(k, left, right int) (int, error) {
	if left > right {
		return -1, utils.NoSuchKey()
	}
	mid := (left + right) / 2
	if k == list.Elements[mid] {
		return mid, nil
	} else if k < list.Elements[mid] {
		return list.rFindIndex(k, left, mid-1)
	} else { // k > list.Elements[mid]
		return list.rFindIndex(k, mid+1, right)
	}
}

func (list *ArrayList) FindIndex_nonRecursive(k int) (int, error) {
	left := 0
	right := list.Size()
	if k < list.Elements[0] || list.Elements[list.Size()-1] < k {
		return -1, utils.NoSuchKey()
	}
	for {
		if left > right {
			return -1, utils.NoSuchKey()
		}

		mid := (left + right) / 2
		if k == list.Elements[mid] {
			return mid, nil
		} else if k < list.Elements[mid] {
			right = mid - 1
		} else { // k > list.Elements[mid]
			left = mid + 1
		}
	}
}