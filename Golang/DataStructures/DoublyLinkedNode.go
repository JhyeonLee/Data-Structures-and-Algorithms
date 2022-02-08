package DataStructures

type DoublyLinkedNode struct {
	Key          int
	Element      int
	NextLink     *DoublyLinkedNode
	PreviousLink *DoublyLinkedNode
}

func GetDoublyLinkedNode() *DoublyLinkedNode {
	newnode := &DoublyLinkedNode{
		NextLink:     nil,
		PreviousLink: nil,
	}
	newnode.Key = 0
	newnode.Element = 0
	return newnode
}

func Swap_DoublyLinkedNode(A, B *DoublyLinkedNode) {
	k := A.Key
	A.Key = B.Key
	B.Key = k

	e := A.Element
	A.Element = B.Element
	B.Element = e
}
