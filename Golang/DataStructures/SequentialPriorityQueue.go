package DataStructures

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

type SequentialPriorityQueue struct {
	keys     []int
	elements map[int]int
	front    int
	rear     int
}

func Initialize_SequentialPriorityQueue() *SequentialPriorityQueue {
	pq := &SequentialPriorityQueue{
		front: 0,
		rear:  -1,
	}
	pq.elements = make(map[int]int)
	return pq
}

// 리스트가 비어 있는지 여부를 반환
func (pq *SequentialPriorityQueue) IsEmpty() bool {
	return pq.Size() == 0
}

// 리스트의 크기, 즉 원소 수 반환
func (pq *SequentialPriorityQueue) Size() int {
	return len(pq.keys)
}

func (pq *SequentialPriorityQueue) Swap(A, B int) {
	k := pq.keys[A]
	pq.keys[A] = pq.keys[B]
	pq.keys[B] = k
}

func (pq *SequentialPriorityQueue) InsertItem(k, e int) {
	// fullQueueException()

	pq.rear++
	pq.keys[pq.rear] = k
	pq.elements[k] = e
}

func (pq *SequentialPriorityQueue) MinKey() (int, error) {
	if pq.IsEmpty() {
		return -1, utils.EmptyQueueException()
	}
	min := pq.keys[0]
	for key, value := range pq.elements {
		if pq.elements[min] > value {
			min = key
		}
	}
	return min, nil
}

func (pq *SequentialPriorityQueue) RemoveMin() (int, error) {
	if pq.IsEmpty() {
		return -1, utils.EmptyQueueException()
	}
	min, err := pq.MinKey()
	if err != nil {
		return -1, err
	}
	e := pq.elements[min]
	pq.Swap(min, pq.keys[0])
	pq.rear--
	return e, nil
}

func (pq *SequentialPriorityQueue) MinElement() (int, error) {
	if pq.IsEmpty() {
		return -1, utils.EmptyQueueException()
	}
	min, err := pq.MinKey()
	if err != nil {
		return -1, err
	}
	return pq.elements[min], nil
}
