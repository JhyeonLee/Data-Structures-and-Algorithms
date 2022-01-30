package DataStructures

import (
	"fmt"

	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"
)

type DoublyLinkedList struct {
	HeadNode *DoublyLinkedNode
	TailNode *DoublyLinkedNode
	Header   *DoublyLinkedNode
	Trailer  *DoublyLinkedNode
}

func Initialize_DoublyLinkedList() *DoublyLinkedList {
	list := &DoublyLinkedList{
		HeadNode: nil,
		TailNode: nil,
		Header:   GetDoublyLinkedNode(),
		Trailer:  GetDoublyLinkedNode(),
	}
	(list.Header).nextlink = list.Trailer
	(list.Trailer).previouslink = list.Header
	return list
}

// 리스트의 크기, 즉 원소 수 반환
func (l *DoublyLinkedList) Size() int {
	count := 0
	if l.HeadNode == nil {
		return count
	}

	for p := l.HeadNode; p != l.Trailer; p = p.nextlink {
		count += 1
	}
	return count
}

// 리스트가 비어 있는지 여부를 반환
func (l *DoublyLinkedList) IsEmpty() bool {
	return l.Size() == 0
}

// 순위 r에 저장된 원소를 반환
func (l *DoublyLinkedList) Get(r int) (int, error) {
	if r < 0 || l.Size() < r {
		return -1, utils.InvalidRankException()
	}
	p := l.Header
	for i := 0; i < r; i++ {
		p = p.nextlink
	}
	return p.Element, nil
}

// 순위 r에 저장된 원소를 e로 대체
func (l *DoublyLinkedList) Set(r, e int) (int, error) {
	if r < 0 || l.Size() < r {
		return -1, utils.InvalidRankException()
	}
	p := l.Header
	for i := 0; i < r; i++ {
		p = p.nextlink
	}
	p.Element = e
	return e, nil
}

// 원소 전체 순회
func (l *DoublyLinkedList) Traverse() {
	for p := l.HeadNode; p != l.Trailer; p = p.nextlink {
		fmt.Printf(" %d", p.Element)
	}
	fmt.Printf("\n")
}

// 노드 p 앞에 값이 e인 노드 삽입
func (p *DoublyLinkedNode) AddNodeBefore(e int) {
	q := GetDoublyLinkedNode()
	q.Element = e
	q.previouslink = p.previouslink
	q.nextlink = p
	(p.previouslink).nextlink = q
	p.previouslink = q
}

// 순위 r에 원소가 e인 노드 삽입
func (l *DoublyLinkedList) Add(r, e int) error {
	if r < 0 || l.Size() < r {
		return utils.InvalidRankException()
	}
	p := l.Header
	for i := 0; i < r; i++ {
		p = p.nextlink
	}
	p.AddNodeBefore(e)
	return nil
}

// 노드 p 삭제
func (p *DoublyLinkedNode) RemoveNode() int {
	e := p.Element
	(p.previouslink).nextlink = p.nextlink
	(p.nextlink).previouslink = p.previouslink
	p = nil
	return e
}

// 순위 r에 저장된 원소를 삭제하여 반환
func (l *DoublyLinkedList) Remove(r int) (int, error) {
	if r < 0 || l.Size() < r {
		return -1, utils.InvalidRankException()
	}
	p := l.Header
	for i := 0; i < r-1; i++ {
		p = p.nextlink
	}
	e := p.RemoveNode()
	return e, nil
}

// 헤더와 트레일러 이외 모든 원소 삭제
func (l *DoublyLinkedList) RemoveAll() error {
	if l.IsEmpty() {
		return utils.EmptyListException()
	}
	for i := l.Size(); i > 0; i-- {
		l.Header.RemoveNode()
	}
	return nil
}

// 리스트 자체 삭제
func (l *DoublyLinkedList) PutList() error {
	err := l.RemoveAll()
	if err != nil {
		return err
	}
	l.Header = nil
	l.Trailer = nil
	return nil
}
