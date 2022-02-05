package DataStructures

// import "github.com/JhyeonLee/DataStructuresAndAlgorithms/golang/utils"

// type SequentialBinaryTree struct {
// 	Keys        []int
// 	Elements    map[int]int
// 	N           int
// 	typeOfOrder string
// }

// func Initialize_SequentialBinaryTree(typeOfOrder string) *SequentialBinaryTree {
// 	binarytree := &SequentialBinaryTree{
// 		N:           0,
// 		typeOfOrder: typeOfOrder,
// 	}
// 	binarytree.Keys = append(binarytree.Keys, 0) // 0번째는 사용하지 않음
// 	binarytree.Elements = make(map[int]int)
// 	return binarytree
// }

// func (biT *SequentialBinaryTree) Element(v int) int {
// 	return biT.Elements[biT.Keys[v]]
// }
// func Root() int {
// 	return 1
// }
// func IsRoot(v int) bool {
// 	return v == Root()
// }
// func Parent(v int) int {
// 	return v / 2
// }
// func LeftChild(v int) int {
// 	return 2 * v
// }
// func RighttChild(v int) int {
// 	return 2*v + 1
// }
// func Sibling(v int) int {
// 	if utils.Even(v) {
// 		return v + 1
// 	} else {
// 		return v - 1
// 	}
// }
// func (biT *SequentialBinaryTree) IsInternal(v int) bool {
// 	return 2*v <= biT.N && biT.Keys[2*v] != nil
// }
