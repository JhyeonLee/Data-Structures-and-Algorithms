package DataStructures

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

type SequentialStack struct {
	elements []int
	top      int
}

func Initialize_SequentialStack() *SequentialStack {
	stack := &SequentialStack{
		top: -1,
	}
	return stack
}

func (S *SequentialStack) Size() int {
	return S.top + 1
}

func (S *SequentialStack) IsEmpty() bool {
	return S.top == -1
}

func (S *SequentialStack) Top() (int, error) {
	if S.IsEmpty() {
		return -1, utils.EmptyStackException()
	}
	return S.elements[S.top], nil
}

func (S *SequentialStack) push(e int) {
	// fullStackException()?

	S.top += 1
	S.elements[S.top] = e
}

func (S *SequentialStack) pop() (int, error) {
	if S.IsEmpty() {
		return -1, utils.EmptyStackException()
	}
	S.top -= 1
	return S.elements[S.top+1], nil
}
