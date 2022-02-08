package DataStructures

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

type LinkedPriorityQueue struct {
	Front *SinglyLinkedNode
	Rear  *SinglyLinkedNode
}

func LinkedPriorityQueue_initialize() *LinkedPriorityQueue {
	Pq := &LinkedPriorityQueue{
		Front: nil,
		Rear:  nil,
	}
	return Pq
}

func (Pq *LinkedPriorityQueue) IsEmpty() bool {
	return Pq.Front == nil
}

func (Pq *LinkedPriorityQueue) Size() int {
	count := 0
	for p := Pq.Front; p != nil; p = p.Link {
		count++
	}
	return count
}

func (Pq *LinkedPriorityQueue) InsertItem(k, e int) {
	newnode := GetSinglyLinkedNode()
	newnode.Key = k
	newnode.Element = e
	newnode.Link = nil
	if Pq.IsEmpty() {
		Pq.Front = newnode
		Pq.Rear = newnode
	} else {
		(Pq.Rear).Link = newnode
		Pq.Rear = newnode
	}
}

func (Pq *LinkedPriorityQueue) FindMin() (*SinglyLinkedNode, error) {
	if Pq.IsEmpty() {
		return nil, utils.EmptyQueueException()
	}
	min := Pq.Front
	for p := (Pq.Front).Link; p != nil; p = p.Link {
		if p.Key < min.Key {
			min = p
		}
	}
	return min, nil
}

func (Pq *LinkedPriorityQueue) RemoveMin() (*SinglyLinkedNode, error) {
	if Pq.IsEmpty() {
		return nil, utils.EmptyQueueException()
	}
	min, err := Pq.FindMin()
	if err != nil {
		return nil, err
	}
	Swap_SinglyLinkedNode(Pq.Front, min)
	min = Pq.Front
	Pq.Front = (Pq.Front).Link
	if Pq.Front == nil {
		Pq.Rear = nil
	}
	min.Link = nil
	return min, nil
}

func (Pq *LinkedPriorityQueue) MinElement() (int, error) {
	if Pq.IsEmpty() {
		return -1, utils.EmptyQueueException()
	}
	min, err := Pq.FindMin()
	if err != nil {
		return -1, err
	}
	return min.Element, nil
}

func (Pq *LinkedPriorityQueue) MinKey() (int, error) {
	if Pq.IsEmpty() {
		return -1, utils.EmptyQueueException()
	}
	min, err := Pq.FindMin()
	if err != nil {
		return -1, err
	}
	return min.Key, nil
}
