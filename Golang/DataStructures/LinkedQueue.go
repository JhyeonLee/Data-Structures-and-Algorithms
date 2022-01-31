package DataStructures

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

type LinkedQueue struct {
	front *SinglyLinkedNode
	rear  *SinglyLinkedNode
}

func Initialize_LinkedQueue() *LinkedQueue {
	queue := &LinkedQueue{
		front: nil,
		rear:  nil,
	}
	return queue
}

func (Q *LinkedQueue) IsEmpty() bool {
	return Q.front == nil
}

func (Q *LinkedQueue) Enqueue(e int) {
	p := GetSinglyLinkedNode()
	p.Element = e
	p.link = nil
	if Q.IsEmpty() {
		Q.front = p
		Q.rear = p
	} else {
		(Q.rear).link = p
		Q.rear = p
	}
}

func (Q *LinkedQueue) Dequeue() (int, error) {
	if Q.IsEmpty() {
		return -1, utils.EmptyQueueException()
	}
	e := Q.front.Element
	Q.front = Q.front.link
	if Q.front == nil {
		Q.rear = nil
	}
	return e, nil
}
