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
	Size     int
}

func Initialize_DoublyLinkedList() *DoublyLinkedList {
	list := &DoublyLinkedList{
		HeadNode: nil,
		TailNode: nil,
		Header:   GetDoublyLinkedNode(),
		Trailer:  GetDoublyLinkedNode(),
	}
	(list.Header).NextLink = list.Trailer
	(list.Trailer).PreviousLink = list.Header
	list.Size = 0
	return list
}

// 리스트의 크기, 즉 원소 수 반환
// func (l *DoublyLinkedList) Size() int {
// 	count := 0
// 	if l.HeadNode == nil {
// 		return count
// 	}

// 	for p := l.HeadNode; p != l.Trailer; p = p.NextLink {
// 		count += 1
// 	}
// 	return count
// }

// 리스트가 비어 있는지 여부를 반환
func (l *DoublyLinkedList) IsEmpty() bool {
	return l.Size == 0
}

// 순위 r에 있는 노드 반환
func (l *DoublyLinkedList) FindNode(r int) *DoublyLinkedNode {
	p := l.Header
	for i := 0; i < r; i++ {
		p = p.NextLink
	}
	return p
}

// 순위 r에 저장된 원소를 반환
func (l *DoublyLinkedList) Get(r int) (int, error) {
	if r < 0 || l.Size < r {
		return -1, utils.InvalidRankException()
	}
	p := l.FindNode(r)
	return p.Element, nil
}

// 순위 r에 저장된 원소를 e로 대체
func (l *DoublyLinkedList) Set(r, e int) (int, error) {
	if r < 0 || l.Size < r {
		return -1, utils.InvalidRankException()
	}
	p := l.FindNode(r)
	p.Element = e
	return e, nil
}

// 원소 전체 순회
func (l *DoublyLinkedList) Traverse() {
	for p := l.HeadNode; p != l.Trailer; p = p.NextLink {
		fmt.Printf(" %d", p.Element)
	}
	fmt.Printf("\n")
}

// 노드 p 앞에 값이 e인 노드 삽입
func (p *DoublyLinkedNode) AddNodeBefore(k, e int) {
	q := GetDoublyLinkedNode()
	q.Key = k
	q.Element = e
	q.PreviousLink = p.PreviousLink
	q.NextLink = p
	(p.PreviousLink).NextLink = q
	p.PreviousLink = q
}

// 순위 r에 원소가 e인 노드 삽입
func (l *DoublyLinkedList) Add(r, k, e int) error {
	if r < 0 || l.Size < r {
		return utils.InvalidRankException()
	}
	p := l.FindNode(r)
	p.AddNodeBefore(k, e)
	l.Size++
	return nil
}

// 리스트 가장 앞에(헤드 노드) 원소가 e인 노드 삽입
func (l *DoublyLinkedList) AddFirst(k, e int) error {
	return l.Add(1, k, e)
}

// 리스트 가장 끝에(테일 노드) 원소가 e인 노드 삽입
func (l *DoublyLinkedList) AddLast(k, e int) error {
	return l.Add(l.Size+1, k, e)
}

// 노드 p 삭제
func (p *DoublyLinkedNode) RemoveNode() *DoublyLinkedNode {
	// e := p.Element
	e := p
	(p.PreviousLink).NextLink = p.NextLink
	(p.NextLink).PreviousLink = p.PreviousLink
	// p = nil
	e.NextLink = nil
	e.PreviousLink = nil
	return e
}

// 순위 r에 저장된 원소를 삭제하여 반환
func (l *DoublyLinkedList) Remove(r int) (*DoublyLinkedNode, error) {
	if r < 0 || l.Size < r {
		return nil, utils.InvalidRankException()
	}
	p := l.Header
	for i := 0; i < r-1; i++ {
		p = p.NextLink
	}
	e := p.RemoveNode()
	l.Size--
	if l.Size == 0 {
		l.HeadNode = nil
		l.TailNode = nil
	}
	return e, nil
}

// 리스트 가장 앞에(헤드 노드) 원소가 e인 노드 삭제
func (l *DoublyLinkedList) RemoveFirst() (*DoublyLinkedNode, error) {
	return l.Remove(1)
}

// 리스트 가장 끝에(테일 노드) 원소가 e인 노드 삭제
func (l *DoublyLinkedList) RemoveLast() (*DoublyLinkedNode, error) {
	return l.Remove(l.Size)
}

// 헤더와 트레일러 이외 모든 원소 삭제
func (l *DoublyLinkedList) RemoveAll() error {
	if l.IsEmpty() {
		return utils.EmptyListException()
	}
	for i := l.Size; i > 0; i-- {
		l.RemoveFirst()
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
