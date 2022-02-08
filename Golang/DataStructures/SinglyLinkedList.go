package DataStructures

import (
	"fmt"

	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"
)

type SinglyLinkedList struct {
	HeadNode *SinglyLinkedNode
	TailNode *SinglyLinkedNode
	Header   *SinglyLinkedNode
	Trailer  *SinglyLinkedNode
}

func Initialize_SinglyLinkedList() *SinglyLinkedList {
	list := &SinglyLinkedList{
		HeadNode: nil,
		TailNode: nil,
		Header:   GetSinglyLinkedNode(),
		Trailer:  GetSinglyLinkedNode(),
	}
	list.Header.Link = list.Trailer
	return list
}

// 리스트의 크기, 즉 원소 수 반환
func (l *SinglyLinkedList) Size() int {
	count := 0
	if l.HeadNode == nil {
		return count
	}

	for p := l.HeadNode; p != l.Trailer; p = p.Link {
		count += 1
	}
	return count
}

// 리스트가 비어 있는지 여부를 반환
func (l *SinglyLinkedList) IsEmpty() bool {
	return l.Size() == 0
}

// 순위 r에 저장된 원소를 반환
func (l *SinglyLinkedList) Get(r int) (int, error) {
	if r < 0 || l.Size() < r {
		return -1, utils.InvalidRankException()
	}
	p := l.Header
	for i := 0; i < r; i++ {
		p = p.Link
	}
	return p.Element, nil
}

// 순위 r에 저장된 원소를 e로 대체
func (l *SinglyLinkedList) Set(r, k, e int) (int, error) {
	if r < 0 || l.Size() < r {
		return -1, utils.InvalidRankException()
	}
	p := l.Header
	for i := 0; i < r; i++ {
		p = p.Link
	}
	p.Key = k
	p.Element = e
	return e, nil
}

// 원소 전체 순회
func (l *SinglyLinkedList) Traverse() {
	for p := l.HeadNode; p != l.Trailer; p = p.Link {
		fmt.Printf(" %d", p.Element)
	}
	fmt.Printf("\n")
}

// 노드 p 뒤에 값이 e인 노드 삽입
func (p *SinglyLinkedNode) AddNodeNext(k, e int) {
	q := GetSinglyLinkedNode()
	q.Key = k
	q.Element = e
	q.Link = p.Link
	p.Link = q
}

// 순위 r에 원소가 e인 노드 삽입
func (l *SinglyLinkedList) Add(r, k, e int) error {
	if r < 0 || l.Size()+1 < r {
		return utils.InvalidRankException()
	}
	p := l.Header
	for i := 0; i < r-1; i++ {
		p = p.Link
	}
	p.AddNodeNext(k, e)
	return nil
}

// 리스트 가장 앞에(헤드 노드) 원소가 e인 노드 삽입
func (l *SinglyLinkedList) AddFirst(k, e int) error {
	return l.Add(1, k, e)
}

// 리스트 가장 끝에(테일 노드) 원소가 e인 노드 삽입
func (l *SinglyLinkedList) AddLast(k, e int) error {
	return l.Add(l.Size()+1, k, e)
}

// 노드 p 삭제
func (previousNode *SinglyLinkedNode) RemoveNode() *SinglyLinkedNode {
	p := previousNode.Link
	// e := p.Element
	previousNode.Link = p.Link
	// p = nil
	// return e

	// apply node which has key and element
	p.Link = nil
	return p
}

// 순위 r에 저장된 원소를 삭제하여 반환
// apply node which has key and element
func (l *SinglyLinkedList) Remove(r int) (*SinglyLinkedNode, error) {
	if r < 0 || l.Size() < r {
		// return -1, utils.InvalidRankException()
		return nil, utils.InvalidRankException()
	}
	p := l.Header
	for i := 0; i < r-1; i++ {
		p = p.Link
	}
	e := p.RemoveNode()
	return e, nil
}

// 리스트 가장 앞에(헤드 노드) 원소가 e인 노드 삭제
// apply node which has key and element
func (l *SinglyLinkedList) RemoveFirst() (*SinglyLinkedNode, error) {
	return l.Remove(1)
}

// 리스트 가장 끝에(테일 노드) 원소가 e인 노드 삭제
// apply node which has key and element
func (l *SinglyLinkedList) RemoveLast() (*SinglyLinkedNode, error) {
	return l.Remove(l.Size())
}

// 헤더와 트레일러 이외 모든 원소 삭제
func (l *SinglyLinkedList) RemoveAll() error {
	if l.IsEmpty() {
		return utils.EmptyListException()
	}
	for i := l.Size(); i > 0; i-- {
		l.RemoveFirst()
	}
	return nil
}

// 리스트 자체 삭제
func (l *SinglyLinkedList) PutList() error {
	err := l.RemoveAll()
	if err != nil {
		return err
	}
	l.Header = nil
	l.Trailer = nil
	return nil
}
