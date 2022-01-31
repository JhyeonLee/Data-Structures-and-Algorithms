package DataStructures

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

type LinkedDeque struct {
	front *DoublyLinkedNode
	rear  *DoublyLinkedNode
}

func Initialize_LinkeDeque() *LinkedDeque {
	deque := &LinkedDeque{
		front: nil,
		rear:  nil,
	}
	return deque
}

func (Dq *LinkedDeque) IsEmpty() bool {
	return Dq.front == nil
}

func (Dq *LinkedDeque) Push(e int) {
	p := GetDoublyLinkedNode()
	p.Element = e
	p.nextlink = nil
	p.previouslink = nil
	if Dq.IsEmpty() {
		Dq.front = p
		Dq.rear = p
	} else {
		p.nextlink = Dq.front
		(Dq.front).previouslink = p
		Dq.front = p
	}
}

func (Dq *LinkedDeque) Pop() (int, error) {
	if Dq.IsEmpty() {
		return -1, utils.EmptyDequeException()
	}
	e := Dq.front.Element
	Dq.front = Dq.front.nextlink
	if Dq.front == nil {
		Dq.rear = nil
	}
	return e, nil
}

func (Dq *LinkedDeque) Inject(e int) {
	p := GetDoublyLinkedNode()
	p.Element = e
	p.nextlink = nil
	p.previouslink = nil
	if Dq.IsEmpty() {
		Dq.front = p
		Dq.rear = p
	} else {
		p.previouslink = Dq.rear
		(Dq.rear).nextlink = p
		Dq.rear = p
	}
}

func (Dq *LinkedDeque) Eject() (int, error) {
	if Dq.IsEmpty() {
		return -1, utils.EmptyDequeException()
	}
	e := Dq.rear.Element
	Dq.rear = Dq.rear.previouslink
	if Dq.rear == nil {
		Dq.front = nil
	}
	return e, nil
}
