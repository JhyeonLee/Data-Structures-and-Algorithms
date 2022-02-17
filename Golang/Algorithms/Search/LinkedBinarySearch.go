package Algorithms

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

// 정렬이 되어있을 경우
func (list *DoublyLinkedList) FindElement_recursive(k int) (int, error) {
	if k < list.HeadNode.Key || list.TailNode.Key < k {
		return -1, utils.NoSuchKey()
	}
	return list.rFindElement(k, 0, list.Size)
}
func (list *DoublyLinkedList) rFindElement(k, left, right int) (int, error) {
	if left > right {
		return -1, utils.NoSuchKey()
	}
	m := (left + right) / 2
	mid := list.FindNode(m)
	if k == mid.Key {
		return mid.Element, nil
	} else if k < mid.Key {
		return list.rFindElement(k, left, m-1)
	} else { // k > mid.Key
		return list.rFindElement(k, m+1, right)
	}
}

func (list *DoublyLinkedList) FindElement_nonRecursive(k int) (int, error) {
	left := 0
	right := list.Size
	if k < list.HeadNode.Key || list.TailNode.Key < k {
		return -1, utils.NoSuchKey()
	}
	for {
		if left > right {
			return -1, utils.NoSuchKey()
		}
		m := (left + right) / 2
		mid := list.FindNode(m)
		if k == mid.Key {
			return mid.Element, nil
		} else if k < mid.Key {
			right = m - 1
		} else { // k > mid.Key
			left = m + 1
		}
	}
}
