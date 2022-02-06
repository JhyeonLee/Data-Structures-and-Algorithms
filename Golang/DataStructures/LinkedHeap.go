package DataStructures

type LinkedHeap struct {
	Root        *LinkedBinaryTreeNode
	N           int
	typeOfOrder string
}

func Initialize_LinkedHeap(typeOfOrder string) *LinkedHeap {
	heap := &LinkedHeap{
		typeOfOrder: typeOfOrder,
	}
	heap.Root = GetLinkedBinaryTreeNode()
	return heap
}

func ExpandExternal(node *LinkedBinaryTreeNode) {
	left := GetLinkedBinaryTreeNode()
	right := GetLinkedBinaryTreeNode()
	left.LeftChild = nil
	left.RightChild = nil
	left.Parent = node
	right.LeftChild = nil
	right.RightChild = nil
	right.Parent = node
	node.LeftChild = left
	node.RightChild = right
}

func (H *LinkedHeap) ReduceExternal(z *LinkedBinaryTreeNode) *LinkedBinaryTreeNode {
	z_parent := z.Parent
	z_sibling := Sibling(z)
	if IsRoot(z_parent) {
		H.Root = z_sibling
		z_sibling.Parent = nil
	} else {
		z_grandparent := z_parent.Parent
		z_sibling.Parent = z_grandparent
		if z.Parent == z_grandparent.LeftChild {
			z_grandparent.LeftChild = z_sibling
		} else {
			z_grandparent.RightChild = z_sibling
		}
	}
	// PutLinkedBinaryTreeNode(z)
	// PutLinkedBinaryTreeNode(z_parent)
	return z_sibling
}

func (S *SequentialStack) BinaryExpansion(n int) {
	for n >= 2 {
		S.push(n % 2)
		n = n % 2
	}
	S.push(n)
}
func (H *LinkedHeap) LastNode() *LinkedBinaryTreeNode {
	node := H.Root
	S := Initialize_SequentialStack()
	S.BinaryExpansion(H.N)
	_, _ = S.pop()
	for !S.IsEmpty() {
		bit, _ := S.pop()
		if bit == 0 {
			node = node.LeftChild
		} else {
			node = node.RightChild
		}
	}
	return node
}

func AdvanceLastNode(H *LinkedHeap, lastnode *LinkedBinaryTreeNode) *LinkedBinaryTreeNode {
	for lastnode != H.Root && (lastnode.Parent).RightChild == lastnode {
		lastnode = lastnode.Parent
	}
	for lastnode != H.Root && (lastnode.Parent).LeftChild == lastnode {
		lastnode = Sibling(lastnode)
	}
	for IsInternal(lastnode) {
		lastnode = lastnode.LeftChild
	}
	return lastnode
}
func AdvanceLast(H *LinkedHeap) *LinkedBinaryTreeNode {
	lastnode := H.LastNode()
	return AdvanceLastNode(H, lastnode)
}

func RetreatLastNode(H *LinkedHeap, lastnode *LinkedBinaryTreeNode) *LinkedBinaryTreeNode {
	for lastnode != H.Root && (lastnode.Parent).LeftChild == lastnode {
		lastnode = lastnode.Parent
	}
	for lastnode != H.Root && (lastnode.Parent).RightChild == lastnode {
		lastnode = Sibling(lastnode)
	}
	for IsInternal(lastnode) {
		lastnode = lastnode.RightChild
	}
	return lastnode.Parent
}
func RetreatLast(H *LinkedHeap) *LinkedBinaryTreeNode {
	lastnode := H.LastNode()
	return RetreatLastNode(H, lastnode)
}

func (node *LinkedBinaryTreeNode) UpHeap_minHeap() {
	if IsRoot(node) {
		return
	}
	if node.Key <= (node.Parent).Key {
		return
	}
	Swap(node, node.Parent)
	node.UpHeap_minHeap()
}
func (node *LinkedBinaryTreeNode) DownHeap_minHeap() {
	if IsExternal(node.LeftChild) && IsExternal(node.RightChild) {
		return
	}
	smaller := node.LeftChild
	if IsInternal(node.RightChild) {
		if (node.RightChild).Key < smaller.Key {
			smaller = node.RightChild
		}
	}
	if node.Key <= smaller.Key {
		return
	}
	Swap(node, smaller)
	smaller.DownHeap_minHeap()
}
func (H *LinkedHeap) InsertItem_minHeap(k, e int) {
	newnode := AdvanceLast(H)
	newnode.Key = k
	newnode.Element = e
	H.N++
	ExpandExternal(newnode)
	newnode.UpHeap_minHeap()
}
func (H *LinkedHeap) RemoveMin() *LinkedBinaryTreeNode {
	root := H.Root
	lastnode := H.LastNode()
	(H.Root).Key = lastnode.Key
	(H.Root).Element = lastnode.Element
	// node := RetreatLast(H)
	z := lastnode.RightChild
	H.ReduceExternal(z)
	H.N--
	(H.Root).DownHeap_minHeap()

	root.LeftChild = nil
	root.RightChild = nil
	return root
}

func (node *LinkedBinaryTreeNode) UpHeap_maxHeap() {
	if IsRoot(node) {
		return
	}
	if node.Key >= (node.Parent).Key {
		return
	}
	Swap(node, node.Parent)
	node.UpHeap_maxHeap()
}
func (node *LinkedBinaryTreeNode) DownHeap_maxHeap() {
	if IsExternal(node.LeftChild) && IsExternal(node.RightChild) {
		return
	}
	bigger := node.LeftChild
	if IsInternal(node.RightChild) {
		if (node.RightChild).Key > bigger.Key {
			bigger = node.RightChild
		}
	}
	if node.Key >= bigger.Key {
		return
	}
	Swap(node, bigger)
	bigger.DownHeap_maxHeap()
}
func (H *LinkedHeap) InsertItem_maxHeap(k, e int) {
	newnode := AdvanceLast(H)
	newnode.Key = k
	newnode.Element = e
	H.N++
	ExpandExternal(newnode)
	newnode.UpHeap_maxHeap()
}
func (H *LinkedHeap) RemoveMax() *LinkedBinaryTreeNode {
	root := H.Root
	lastnode := H.LastNode()
	(H.Root).Key = lastnode.Key
	(H.Root).Element = lastnode.Element
	// node := RetreatLast(H)
	z := lastnode.RightChild
	H.ReduceExternal(z)
	H.N--
	(H.Root).DownHeap_maxHeap()

	root.LeftChild = nil
	root.RightChild = nil
	return root
}

func ExpandExternalAll(node *LinkedBinaryTreeNode) {
	if IsInternal(node) {
		ExpandExternalAll(node.LeftChild)
		ExpandExternalAll(node.RightChild)
	} else if IsExternal(node) {
		ExpandExternal(node)
	} else {
		if node.LeftChild == nil {
			left := GetLinkedBinaryTreeNode()
			left.LeftChild = nil
			left.RightChild = nil
			left.Parent = node
			node.LeftChild = left
		} else if node.RightChild == nil {
			right := GetLinkedBinaryTreeNode()
			right.LeftChild = nil
			right.RightChild = nil
			right.Parent = node
			node.RightChild = right
		}
	}
}

func (tree *LinkedBinaryTree) CompleteBinaryTreeConvert2LinkedHeap() *LinkedHeap {
	heap := Initialize_LinkedHeap(tree.typeOfOrder)
	heap.Root = tree.Root
	heap.N = PreOrder(tree.Root)
	ExpandExternalAll(heap.Root)
	return heap
}
func (list *SinglyLinkedList) ListConvert2LinkedHeap(typeOfOrder string) *LinkedHeap {
	tree := list.ListConvert2CompleteBinaryTree(typeOfOrder)
	heap := Initialize_LinkedHeap(typeOfOrder)
	heap.Root = tree.Root
	heap.N = InOrder(tree.Root)
	ExpandExternalAll(heap.Root)
	return heap
}

func RecursiveBuildHeap_minHeap(list *SinglyLinkedList, typeOfOrder string) *LinkedHeap {
	heap := list.ListConvert2LinkedHeap(typeOfOrder)
	(heap.Root).RBuildHeap_minHeap()
	return heap
}
func (node *LinkedBinaryTreeNode) RBuildHeap_minHeap() {
	if IsRoot(node) {
		return
	}
	(node.LeftChild).RBuildHeap_minHeap()
	(node.RightChild).RBuildHeap_minHeap()
	node.DownHeap_minHeap()
}

func RecursiveBuildHeap_maxHeap(list *SinglyLinkedList, typeOfOrder string) *LinkedHeap {
	heap := list.ListConvert2LinkedHeap(typeOfOrder)
	(heap.Root).RBuildHeap_minHeap()
	return heap
}
func (node *LinkedBinaryTreeNode) RBuildHeap_maxHeap() {
	if IsRoot(node) {
		return
	}
	(node.LeftChild).RBuildHeap_maxHeap()
	(node.RightChild).RBuildHeap_maxHeap()
	node.DownHeap_maxHeap()
}
