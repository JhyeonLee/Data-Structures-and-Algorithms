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

func Swap_LinkedBinaryTreeNode(v *LinkedBinaryTreeNode, w *LinkedBinaryTreeNode) {
	k := v.Key
	v.Key = w.Key
	w.Key = k
	e := v.Element
	v.Element = w.Element
	w.Element = e
}

// func PutLinkedBinaryTreeNode(node *LinkedBinaryTreeNode) {
// 	del
// }
