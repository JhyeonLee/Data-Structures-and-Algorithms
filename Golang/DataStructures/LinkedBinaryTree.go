package DataStructures

import (
	"fmt"

	"github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"
)

type LinkedBinaryTree struct {
	Root        *LinkedBinaryTreeNode
	typeOfOrder string
}

func Initialize_LinkedBinaryTree(typeOfOrder string) *LinkedBinaryTree {
	biTree := &LinkedBinaryTree{
		typeOfOrder: typeOfOrder,
	}
	biTree.Root = GetLinkedBinaryTreeNode()
	return biTree
}

func IsRoot(node *LinkedBinaryTreeNode) bool {
	return node.Parent == nil
}
func Sibling(node *LinkedBinaryTreeNode) *LinkedBinaryTreeNode {
	parent := node.Parent
	if parent.LeftChild == node {
		return parent.RightChild
	} else {
		return parent.LeftChild
	}
}
func IsInternal(node *LinkedBinaryTreeNode) bool {
	return node.LeftChild != nil || node.RightChild != nil
}
func IsExternal(node *LinkedBinaryTreeNode) bool {
	return node.LeftChild == nil && node.RightChild == nil
}
func (node *LinkedBinaryTreeNode) SetElement(k, e int) {
	node.Key = k
	node.Element = e
}
func Swap(v *LinkedBinaryTreeNode, w *LinkedBinaryTreeNode) {
	k := v.Key
	v.Key = w.Key
	w.Key = k
	e := v.Element
	v.Element = w.Element
	w.Element = e
}

func (node *LinkedBinaryTreeNode) Depth() int {
	if IsRoot(node) {
		return 0
	} else {
		return 1 + node.Depth()
	}
}
func (node *LinkedBinaryTreeNode) Height() int {
	if IsInternal(node) {
		return 0
	} else {
		leftH := node.LeftChild.Height()
		rightH := node.RightChild.Height()
		if leftH <= rightH {
			return 1 + rightH
		} else {
			return 1 + leftH
		}
	}
}
func PreOrder(node *LinkedBinaryTreeNode) int {
	fmt.Println("key: ", node.Key, ", element: ", node.Element)
	count := 0
	if IsInternal(node) {
		count += PreOrder(node.LeftChild)
		count += PreOrder(node.RightChild)
	}
	return count
}
func PostOrder(node *LinkedBinaryTreeNode) int {
	count := 0
	if IsInternal(node) {
		count += PostOrder(node.LeftChild)
		count += PostOrder(node.RightChild)
	}
	fmt.Println("key: ", node.Key, ", element: ", node.Element)
	return count
}
func InOrder(node *LinkedBinaryTreeNode) int {
	count := 0
	if IsInternal(node) {
		count += InOrder(node.LeftChild)
	}
	fmt.Println("key: ", node.Key, ", element: ", node.Element)
	if IsInternal(node) {
		count += InOrder(node.RightChild)
	}
	return count
}
func EulerTour(node *LinkedBinaryTreeNode) {
	fmt.Println("key: ", node.LeftChild.Key, ", element: ", node.LeftChild.Element)
	if IsInternal(node) {
		EulerTour(node.LeftChild)
	}
	fmt.Println("key: ", node.Key, ", element: ", node.Element)
	if IsInternal(node) {
		EulerTour(node.RightChild)
	}
	fmt.Println("key: ", node.RightChild.Key, ", element: ", node.RightChild.Element)
}

func (node *LinkedBinaryTreeNode) PreOrderSucc() *LinkedBinaryTreeNode {
	if IsInternal(node) {
		return node.LeftChild
	}
	parent := node.Parent
	for parent.LeftChild != node {
		if IsRoot(parent) {
			err := utils.InvalidNodeException()
			if err != nil {
				return nil
			}
		}
		node = parent
		parent = parent.Parent
	}
	return parent.RightChild
}

func (node *LinkedBinaryTreeNode) InOrderSucc() *LinkedBinaryTreeNode {
	if IsInternal(node) {
		node = node.RightChild
		for IsInternal(node) {
			node = node.LeftChild
		}
		return node
	}
	parent := node.Parent
	for parent.LeftChild != node {
		if IsRoot(parent) {
			err := utils.InvalidNodeException()
			if err != nil {
				return nil
			}
		}
		node = parent
		parent = parent.Parent
	}
	return parent
}

func (node *LinkedBinaryTreeNode) PostOrderSucc() *LinkedBinaryTreeNode {
	if IsRoot(node) {
		err := utils.InvalidNodeException()
		if err != nil {
			return nil
		}
	}
	parent := node.Parent
	for parent.RightChild != node {
		return parent
	}
	node = parent.RightChild
	for !IsExternal(node) {
		node = node.LeftChild
	}
	return node
}

func (list *SinglyLinkedList) ListConvert2CompleteBinaryTree(typeOfOrder string) *LinkedBinaryTree {
	tree := Initialize_LinkedBinaryTree(typeOfOrder)
	Q := Initialize_LinkedQueue_biT()
	node := tree.Root
	Q.Enqueue_biT(node)
	for !list.IsEmpty() {
		node, err := Q.Dequeue_biT()
		if err != nil {
			break
		}
		// Left Child
		e, err := list.RemoveFirst()
		if err != nil {
			break
		}
		newnode := GetLinkedBinaryTreeNode()
		newnode.Element = e
		node.LeftChild = newnode
		newnode.Parent = node
		Q.Enqueue_biT(node.LeftChild)
		// Right Child
		e, err = list.RemoveFirst()
		if err != nil {
			break
		}
		newnode = GetLinkedBinaryTreeNode()
		newnode.Element = e
		node.RightChild = newnode
		newnode.Parent = node
		Q.Enqueue_biT(node.RightChild)
	}
	return tree
}
