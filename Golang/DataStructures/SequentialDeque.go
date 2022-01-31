package DataStructures

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

type SequentialDeque struct {
	Elements []int
	front    int
	rear     int
}

func Initialize_SequentialDeque() *SequentialDeque {
	deque := &SequentialDeque{
		front: 0,
		rear:  -1,
	}
	return deque
}

func (Dq *SequentialDeque) Size() int {
	return Dq.rear + 1
}

func (Dq *SequentialDeque) IsEmpty() bool {
	return Dq.Size() == 0
}

func (Dq *SequentialDeque) Push(e int) {
	// fullQueueException()

	Dq.rear++
	Dq.Elements = append([]int{e}, Dq.Elements...)
}

func (Dq *SequentialDeque) Pop() (int, error) {
	if Dq.IsEmpty() {
		return -1, utils.EmptyDequeException()
	}
	// fullQueueException()
	e := Dq.Elements[Dq.front]
	Dq.rear--
	Dq.Elements = Dq.Elements[Dq.front+1:]
	return e, utils.EmptyDequeException()
}

func (Dq *SequentialDeque) Inject(e int) {
	// fullQueueException()

	Dq.rear++
	Dq.Elements = append(Dq.Elements, e)
}

func (Dq *SequentialDeque) Eject() (int, error) {
	if Dq.IsEmpty() {
		return -1, utils.EmptyDequeException()
	}
	// fullQueueException()
	e := Dq.Elements[Dq.rear]
	Dq.rear--
	Dq.Elements = Dq.Elements[:Dq.rear+1]
	return e, utils.EmptyDequeException()
}
