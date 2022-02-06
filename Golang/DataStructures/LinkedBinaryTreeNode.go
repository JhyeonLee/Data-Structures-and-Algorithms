package DataStructures

type LinkedBinaryTreeNode struct {
	Key        int
	Element    int
	Parent     *LinkedBinaryTreeNode
	LeftChild  *LinkedBinaryTreeNode
	RightChild *LinkedBinaryTreeNode
}

func GetLinkedBinaryTreeNode() *LinkedBinaryTreeNode {
	newnode := &LinkedBinaryTreeNode{
		Key:        0,
		Element:    0,
		Parent:     nil,
		LeftChild:  nil,
		RightChild: nil,
	}
	return newnode
}

// func PutLinkedBinaryTreeNode(node *LinkedBinaryTreeNode) {
// 	del
// }
