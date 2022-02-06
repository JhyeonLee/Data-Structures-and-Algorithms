package DataStructures

type SinglyLinkedNode struct {
	Key     int
	Element int
	link    *SinglyLinkedNode
}

func GetSinglyLinkedNode() *SinglyLinkedNode {
	newnode := &SinglyLinkedNode{
		link: nil,
	}
	return newnode
}
