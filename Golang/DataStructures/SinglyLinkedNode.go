package DataStructures

type SinglyLinkedNode struct {
	Element int
	link    *SinglyLinkedNode
}

func GetSinglyLinkedNode() *SinglyLinkedNode {
	newnode := &SinglyLinkedNode{
		link: nil,
	}
	return newnode
}
