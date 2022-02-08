package DataStructures

type SinglyLinkedNode struct {
	Key     int
	Element int
	Link    *SinglyLinkedNode
}

func GetSinglyLinkedNode() *SinglyLinkedNode {
	newnode := &SinglyLinkedNode{
		Link: nil,
	}
	return newnode
}

func Swap_SinglyLinkedNode(A, B *SinglyLinkedNode) {
	k := A.Key
	A.Key = B.Key
	B.Key = k

	e := A.Element
	A.Element = B.Element
	B.Element = e
}
