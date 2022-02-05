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
func PreOrder(node *LinkedBinaryTreeNode) {
	fmt.Println("key: ", node.Key, ", element: ", node.Element)
	if IsInternal(node) {
		PreOrder(node.LeftChild)
		PreOrder(node.RightChild)
	}
}
func PostOrder(node *LinkedBinaryTreeNode) {
	if IsInternal(node) {
		PostOrder(node.LeftChild)
		PostOrder(node.RightChild)
	}
	fmt.Println("key: ", node.Key, ", element: ", node.Element)
}
func InOrder(node *LinkedBinaryTreeNode) {
	if IsInternal(node) {
		InOrder(node.LeftChild)
	}
	fmt.Println("key: ", node.Key, ", element: ", node.Element)
	if IsInternal(node) {
		InOrder(node.RightChild)
	}
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
