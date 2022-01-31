package DataStructures

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

// 합집합(파괴적, 비재귀적)
func SinglyLinkedList_union(A, B *SinglyLinkedList) (*SinglyLinkedList, error) {
	C := Initialize_SinglyLinkedList()
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
			C.AddLast(a)
			A.RemoveFirst()
		} else if a > b {
			C.AddLast(b)
			B.RemoveFirst()
		} else {
			C.AddLast(a)
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
		C.AddLast(a)
		A.RemoveFirst()
	}
	for !B.IsEmpty() {
		b, err := B.Get(1)
		if err != nil {
			utils.HandleErr(err)
			return nil, err
		}
		C.AddLast(b)
		B.RemoveFirst()
	}
	return C, nil
}

// 교집합(파괴적, 비재귀적))
func SinglyLinkedList_intersect(A, B *SinglyLinkedList) (*SinglyLinkedList, error) {
	C := Initialize_SinglyLinkedList()
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
			C.AddLast(a)
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
func SinglyLinkedList_subtract(A, B *SinglyLinkedList) (*SinglyLinkedList, error) {
	C := Initialize_SinglyLinkedList()
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
			C.AddLast(a)
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
		C.AddLast(a)
		A.RemoveFirst()
	}
	for !B.IsEmpty() {
		B.RemoveFirst()
	}
	return C, nil
}

// 포함 여부
func SinglyLinkedList_member(A *SinglyLinkedList, e int) bool {
	if A.IsEmpty() {
		return false
	}
	for p := A.HeadNode; p != A.Trailer; p = p.link {
		if p.Element == e {
			return true
		}
	}
	return false
}

// 부분집합 여부(is B a subset of A?)
func SinglyLinkedList_subset(A, B *SinglyLinkedList) bool {
	if A.IsEmpty() {
		return false
	}
	for p := A.HeadNode; p != A.Trailer; p = p.link {
		if SinglyLinkedList_member(B, p.Element) {
			if p.link == A.Trailer {
				return true
			}
		} else {
			return false
		}
	}
	return false
}
