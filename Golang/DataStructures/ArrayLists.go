// Array Lists
package DataStructures

import "errors"

type ArrayList struct {
	Elements []int
	front    int
	last     int
}

var invalidRankException = errors.New("invalid Rank Exception")
var emptyListException = errors.New("empty List Exception")

// var fullListException = errors.New("full List Exception")

func initialize() *ArrayList {
	list := &ArrayList{
		front: 0,
		last:  0,
	}
	return list
}

// 리스트의 크기, 즉 원소 수 반환
func (l *ArrayList) size() int {
	return l.last
}

// 리스트가 비어 있는지 여부를 반환
func (l *ArrayList) isEmpty() bool {
	return l.size() == 0
}

// 원소 전체를 반환
func (l *ArrayList) elements() []int {
	return l.Elements
}

// 순위 r에 저장된 원소를 반환
func (l *ArrayList) get(r int) (int, error) {
	if r < 0 {
		return -1, invalidRankException
	}
	return l.Elements[r], nil
}

// 순위 r에 저장된 원소를 e로 대체
func (l *ArrayList) set(r, e int) (int, error) {
	if r < 0 {
		return -1, invalidRankException
	}
	l.Elements[r] = e
	return e, nil
}

// 순위 r 앞에 원소 e를 삽입
func (l *ArrayList) add(r, e int) error {
	if r < 0 {
		return invalidRankException
	}
	l.Elements = append(append(l.Elements[:r], e), l.Elements[r:]...)
	return nil
}

// 순위 r에 저장된 원소를 삭제하여 반환
func (l *ArrayList) remove(r int) (int, error) {
	if l.size() == 0 {
		return -1, emptyListException
	}
	if r < 0 {
		return -1, invalidRankException
	}
	e := l.Elements[r]
	l.Elements = append(l.Elements[:r], l.Elements[r+1:]...)
	return e, nil
}
