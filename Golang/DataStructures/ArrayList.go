// Array Lists
package DataStructures

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

type ArrayList struct {
	elements []int
	front    int
	last     int
}

// var fullListException = errors.New("full List Exception")

func Initialize_ArrayList() *ArrayList {
	list := &ArrayList{
		front: 0,
		last:  0,
	}
	return list
}

// 리스트의 크기, 즉 원소 수 반환
func (l *ArrayList) Size() int {
	return l.last
}

// 리스트가 비어 있는지 여부를 반환
func (l *ArrayList) IsEmpty() bool {
	return l.Size() == 0
}

// 원소 전체를 반환
func (l *ArrayList) Elements() []int {
	return l.elements
}

// 순위 r에 저장된 원소를 반환
func (l *ArrayList) Get(r int) (int, error) {
	if r < 0 || l.Size() < r {
		return -1, utils.InvalidRankException()
	}
	return l.elements[r], nil
}

// 순위 r에 저장된 원소를 e로 대체
func (l *ArrayList) Set(r, e int) (int, error) {
	if r < 0 || l.Size() < r {
		return -1, utils.InvalidRankException()
	}
	l.elements[r] = e
	return e, nil
}

// 순위 r 앞에 원소 e를 삽입
func (l *ArrayList) Add(r, e int) error {
	if r < 0 || l.Size() < r {
		return utils.InvalidRankException()
	}
	l.elements = append(append(l.elements[:r], e), l.elements[r:]...)
	return nil
}

// 순위 r에 저장된 원소를 삭제하여 반환
func (l *ArrayList) Remove(r int) (int, error) {
	if l.Size() == 0 {
		return -1, utils.EmptyListException()
	}
	if r < 0 {
		return -1, utils.InvalidRankException()
	}
	e := l.elements[r]
	l.elements = append(l.elements[:r], l.elements[r+1:]...)
	return e, nil
}
