package DataStructures

type DoublyLinkedNode struct {
	Element      int
	nextlink     *DoublyLinkedNode
	previouslink *DoublyLinkedNode
}

func GetDoublyLinkedNode() *DoublyLinkedNode {
	newnode := &DoublyLinkedNode{
		nextlink:     nil,
		previouslink: nil,
	}
	return newnode
}
