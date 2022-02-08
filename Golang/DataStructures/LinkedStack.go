package DataStructures

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

type LinkeStack struct {
	Top *SinglyLinkedNode
}

func Initialize_LinkeStack() *LinkeStack {
	stack := &LinkeStack{
		Top: nil,
	}
	return stack
}

func (S *LinkeStack) IsEmpty() bool {
	return S.Top == nil
}

func (S *LinkeStack) Push(e int) {
	p := GetSinglyLinkedNode()
	p.Element = e
	p.Link = S.Top
	S.Top = p
}

func (S *LinkeStack) Put() (int, error) {
	if S.IsEmpty() {
		return -1, utils.EmptyStackException()
	}
	e := S.Top.Element
	// p := S.Top
	S.Top = S.Top.Link
	// p = nil
	return e, nil
}
