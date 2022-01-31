package DataStructures

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

type SequentialQueue struct {
	Elements []int
	front    int
	rear     int
}

func Initialize_SequentialQueue() *SequentialQueue {
	queue := &SequentialQueue{
		front: 0,
		rear:  -1,
	}
	return queue
}

func (Q *SequentialQueue) Size() int {
	return Q.rear + 1
}

func (Q *SequentialQueue) IsEmpty() bool {
	return Q.Size() == 0
}

func (Q *SequentialQueue) Enqueue(e int) {
	// fullQueueException()

	Q.rear++
	Q.Elements = append(Q.Elements, e)
}

func (Q *SequentialQueue) Dequeue() (int, error) {
	if Q.IsEmpty() {
		return -1, utils.EmptyQueueException()
	}
	// fullQueueException()
	e := Q.Elements[Q.front]
	Q.rear--
	Q.Elements = Q.Elements[1:]
	return e, utils.EmptyQueueException()
}
