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

// 리스트의 크기, 즉 원소 수 반환
func (l *SequentialPriorityQueue) Size() int {
	return len(l.keys)
}

// 리스트가 비어 있는지 여부를 반환
func (l *SequentialPriorityQueue) IsEmpty() bool {
	return l.Size() == 0
}

func (l *SequentialPriorityQueue) Swap(A, B int) {
	k := l.keys[A]
	l.keys[A] = l.keys[B]
	l.keys[B] = k
}

func (l *SequentialPriorityQueue) InsertItem(k, e int) {
	// fullQueueException()

	l.rear++
	l.keys[l.rear] = k
	l.elements[k] = e
}

func (l *SequentialPriorityQueue) MinKey() (int, error) {
	if l.IsEmpty() {
		return -1, utils.EmptyQueueException()
	}
	min := l.keys[0]
	for key, value := range l.elements {
		if l.elements[min] > value {
			min = key
		}
	}
	return min, nil
}

func (l *SequentialPriorityQueue) RemoveMin() (int, error) {
	if l.IsEmpty() {
		return -1, utils.EmptyQueueException()
	}
	min, err := l.MinKey()
	if err != nil {
		return -1, err
	}
	e := l.elements[min]
	l.Swap(min, l.keys[0])
	l.rear--
	return e, nil
}

func (l *SequentialPriorityQueue) MinElement() (int, error) {
	if l.IsEmpty() {
		return -1, utils.EmptyQueueException()
	}
	min, err := l.MinKey()
	if err != nil {
		return -1, err
	}
	return l.elements[min], nil
}
