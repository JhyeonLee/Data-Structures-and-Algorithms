package DataStructures

import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

type LinkedQueue struct {
	front *SinglyLinkedNode
	rear  *SinglyLinkedNode
}
type LinkedQueue_biT_Node struct {
	Value *LinkedBinaryTreeNode
	link  *LinkedQueue_biT_Node
}
type LinkedQueue_biT struct {
	front *LinkedQueue_biT_Node
	rear  *LinkedQueue_biT_Node
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

func Initialize_LinkedLinkedQueue_biT_node() *LinkedQueue_biT_Node {
	node := &LinkedQueue_biT_Node{
		link: nil,
	}
	node.Value = GetLinkedBinaryTreeNode()
	return node
}
func Initialize_LinkedQueue_biT() *LinkedQueue_biT {
	queue := &LinkedQueue_biT{
		front: nil,
		rear:  nil,
	}
	return queue
}

func (Q *LinkedQueue_biT) IsEmpty_biT() bool {
	return Q.front == nil
}

func (Q *LinkedQueue_biT) Enqueue_biT(node *LinkedBinaryTreeNode) {
	p := Initialize_LinkedLinkedQueue_biT_node()
	p.Value = node
	p.link = nil
	if Q.IsEmpty_biT() {
		Q.front = p
		Q.rear = p
	} else {
		(Q.rear).link = p
		Q.rear = p
	}
}

func (Q *LinkedQueue_biT) Dequeue_biT() (*LinkedBinaryTreeNode, error) {
	if Q.IsEmpty_biT() {
		return nil, utils.EmptyQueueException()
	}
	e := Q.front.Value
	Q.front = Q.front.link
	if Q.front == nil {
		Q.rear = nil
	}
	e.LeftChild = nil
	e.RightChild = nil
	e.Parent = nil
	return e, nil
}
