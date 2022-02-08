package DataStructures

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

// 합집합(파괴적, 비재귀적)
func DoublyLinkedList_union(A, B *DoublyLinkedList) (*DoublyLinkedList, error) {
	C := Initialize_DoublyLinkedList()
	for !A.IsEmpty() && !B.IsEmpty() {
		a, err := A.Get(1)
		if err != nil {
			utils.HandleErr(err)
			return nil, err
		}
		b, err := B.Get(1)
		if err != nil {
			utils.HandleErr(err)
			return nil, err
		}
		if a < b {
			C.AddLast(a, a)
			A.RemoveFirst()
		} else if a > b {
			C.AddLast(b, b)
			B.RemoveFirst()
		} else {
			C.AddLast(a, a)
			A.RemoveFirst()
			B.RemoveFirst()
		}
	}
	for !A.IsEmpty() {
		a, err := A.Get(1)
		if err != nil {
			utils.HandleErr(err)
			return nil, err
		}
		C.AddLast(a, a)
		A.RemoveFirst()
	}
	for !B.IsEmpty() {
		b, err := B.Get(1)
		if err != nil {
			utils.HandleErr(err)
			return nil, err
		}
		C.AddLast(b, b)
		B.RemoveFirst()
	}
	return C, nil
}

// 교집합(파괴적, 비재귀적))
func DoublyLinkedList_intersect(A, B *DoublyLinkedList) (*DoublyLinkedList, error) {
	C := Initialize_DoublyLinkedList()
	for !A.IsEmpty() && !B.IsEmpty() {
		a, err := A.Get(1)
		if err != nil {
			utils.HandleErr(err)
			return nil, err
		}
		b, err := B.Get(1)
		if err != nil {
			utils.HandleErr(err)
			return nil, err
		}
		if a < b {
			A.RemoveFirst()
		} else if a > b {
			B.RemoveFirst()
		} else {
			C.AddLast(a, a)
			A.RemoveFirst()
			B.RemoveFirst()
		}
	}
	for !A.IsEmpty() {
		A.RemoveFirst()
	}
	for !B.IsEmpty() {
		B.RemoveFirst()
	}
	return C, nil
}

//차집합(A - B)
func DoublyLinkedList_subtract(A, B *DoublyLinkedList) (*DoublyLinkedList, error) {
	C := Initialize_DoublyLinkedList()
	for !A.IsEmpty() && !B.IsEmpty() {
		a, err := A.Get(1)
		if err != nil {
			utils.HandleErr(err)
			return nil, err
		}
		b, err := B.Get(1)
		if err != nil {
			utils.HandleErr(err)
			return nil, err
		}
		if a < b {
			C.AddLast(a, a)
			A.RemoveFirst()
		} else if a > b {
			B.RemoveFirst()
		} else {
			A.RemoveFirst()
			B.RemoveFirst()
		}
	}
	for !A.IsEmpty() {
		a, err := A.Get(1)
		if err != nil {
			utils.HandleErr(err)
			return nil, err
		}
		C.AddLast(a, a)
		A.RemoveFirst()
	}
	for !B.IsEmpty() {
		B.RemoveFirst()
	}
	return C, nil
}

// 포함 여부
func DoublyLinkedList_member(A *DoublyLinkedList, e int) bool {
	if A.IsEmpty() {
		return false
	}
	for p := A.HeadNode; p != A.Trailer; p = p.NextLink {
		if p.Element == e {
			return true
		}
	}
	return false
}

// 부분집합 여부(is B a subset of A?)
func DoublyLinkedList_subset(A, B *DoublyLinkedList) bool {
	if A.IsEmpty() {
		return false
	}
	for p := A.HeadNode; p != A.Trailer; p = p.NextLink {
		if DoublyLinkedList_member(B, p.Element) {
			if p.NextLink == A.Trailer {
				return true
			}
		} else {
			return false
		}
	}
	return false
}
