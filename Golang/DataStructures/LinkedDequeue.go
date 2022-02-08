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

func (Dq *LinkedDeque) Push(k, e int) {
	p := GetDoublyLinkedNode()
	p.Key = k
	p.Element = e
	p.NextLink = nil
	p.PreviousLink = nil
	if Dq.IsEmpty() {
		Dq.front = p
		Dq.rear = p
	} else {
		p.NextLink = Dq.front
		(Dq.front).PreviousLink = p
		Dq.front = p
	}
}

func (Dq *LinkedDeque) Pop() (*DoublyLinkedNode, error) {
	if Dq.IsEmpty() {
		return nil, utils.EmptyDequeException()
	}
	// e := Dq.front.Element
	e := Dq.front
	Dq.front = Dq.front.NextLink
	if Dq.front == nil {
		Dq.rear = nil
	}
	return e, nil
}

func (Dq *LinkedDeque) Inject(k, e int) {
	p := GetDoublyLinkedNode()
	p.Key = k
	p.Element = e
	p.NextLink = nil
	p.PreviousLink = nil
	if Dq.IsEmpty() {
		Dq.front = p
		Dq.rear = p
	} else {
		p.PreviousLink = Dq.rear
		(Dq.rear).NextLink = p
		Dq.rear = p
	}
}

func (Dq *LinkedDeque) Eject() (*DoublyLinkedNode, error) {
	if Dq.IsEmpty() {
		return nil, utils.EmptyDequeException()
	}
	// e := Dq.rear.Element
	e := Dq.rear
	Dq.rear = Dq.rear.PreviousLink
	if Dq.rear == nil {
		Dq.front = nil
	}
	return e, nil
}
