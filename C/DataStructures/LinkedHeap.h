#pragma once
// #ifdef __LINKEDHEAP_H__
// #define __LINKEDHEAP_H__
#include <stdlib.h>
#include "../utils/utils.h"
#include "./LinkedBinaryTreeNode.h"
#include "./LinkedBinaryTree.h"
#include "./SequentialStack.h"


typedef struct LinkedHeap {
    LinkedBinaryTreeNode* root;
    int size; // 노드 개수
    int type; // ascending(1), descending(2)
} LinkedHeap;

LinkedHeap* LinkedHeap_initialize(int type) {
    LinkedHeap* newheap = (LinkedHeap*)malloc(sizeof(LinkedHeap));
    if (newheap == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newheap->root = LinkedBinaryTreeNode_getNode();
    if (newheap->root == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newheap->size = 0;
    newheap->type = type;
    return newheap;
}

int LinkedHeap_isRoot(LinkedBinaryTreeNode* node) {
    return node->parent == NULL;
}
LinkedBinaryTreeNode* LinkedHeap_parent(LinkedBinaryTreeNode* node) {
    return node->parent;
}
LinkedBinaryTreeNode* LinkedHeap_leftChild(LinkedBinaryTreeNode* node) {
    return node->leftChild;
}
LinkedBinaryTreeNode* LinkedHeap_righttChild(LinkedBinaryTreeNode* node) {
    return node->rightChild;
}
LinkedBinaryTreeNode* LinkedHeap_sibling(LinkedBinaryTreeNode* node) {
    LinkedBinaryTreeNode* parent = node->parent;
    if (parent->leftChild == node) {
        return parent->rightChild;
    } else {
        return parent->leftChild;
    }
}
int LinkedHeap_isInternal(LinkedBinaryTreeNode* node) {
    return node->leftChild != NULL || node->rightChild != NULL;
}
int LinkedHeap_isExternal(LinkedBinaryTreeNode* node) {
    return node->leftChild == NULL && node->rightChild == NULL;
}
void LinkedHeap_swap(LinkedBinaryTreeNode* v, LinkedBinaryTreeNode* w) {
    int k = v->key;
    v->key = w->key;
    w->key = k;

    int e = v->element;
    v->element = w->element;
    w->element = e;
}
void LinkedHeap_expandExternal(LinkedBinaryTreeNode* node) {
    LinkedBinaryTreeNode* left = LinkedBinaryTreeNode_getNode();
    if (left == NULL) {
        notEnoughMemory();
        return;
    }
    LinkedBinaryTreeNode* right = LinkedBinaryTreeNode_getNode();
    if (right == NULL) {
        notEnoughMemory();
        return;
    }
    left->leftChild = NULL;
    left->rightChild = NULL;
    left->parent = node;
    right->leftChild = NULL;
    right->rightChild = NULL;
    right->parent = node;
    node->leftChild = left;
    node->rightChild = right;
}
LinkedBinaryTreeNode* reduceExternal(LinkedHeap* H, LinkedBinaryTreeNode* z) {
    LinkedBinaryTreeNode* z_parent = z->parent;
    LinkedBinaryTreeNode* z_sibiling = LinkedHeap_sibling(z);
    if (LinkedHeap_isRoot(z_parent)) {
        H->root = z_sibiling;
        z_sibiling->parent = NULL;
    } else {
        LinkedBinaryTreeNode* z_grandparent = z_parent->parent;
        z_sibiling->parent = z_grandparent;
        if (z->parent == z_grandparent->leftChild) {
            z_grandparent->leftChild = z_sibiling;
        } else {
            z_grandparent->rightChild = z_sibiling;
        }
    }
    LinkedBinaryTreeNode_putNode(z);
    LinkedBinaryTreeNode_putNode(z_parent);
    return z_sibiling;
}

void LinkedHeap_binaryExpansion(SequentialStack* S, int n) {
    while (n >= 2) {
        // 왼쪽 이동(0), 오른쪽 이동(1)
        SequentialStack_push(S, n%2);
        n = n%2;
    }
    SequentialStack_push(S, n);
}
LinkedBinaryTreeNode* LinkedHeap_findLastNode(LinkedHeap* H) {
    LinkedBinaryTreeNode* node = H->root;
    SequentialStack* S = SequentialStack_initialize(H->size);
    LinkedHeap_binaryExpansion(S, H->size);
    SequentialStack_pop(S);
    while(!SequentialStack_isEmpty(S)) {
        int bit = SequentialStack_pop(S);
        if (bit == 0) { //왼쪽 이동
            node = node->leftChild;
        } else { // bit == 1 오른쪽 이동
            node = node->rightChild;
        }
    }
    return node;
}
LinkedBinaryTreeNode* LinkedHeap_advanceLastNode(LinkedHeap* H, LinkedBinaryTreeNode* lastnode) {
    while (lastnode != H->root && (lastnode->parent)->rightChild == lastnode)  {
        lastnode = lastnode->parent;
    }
    while (lastnode != H->root && (lastnode->parent)->leftChild == lastnode)  {
        lastnode = LinkedHeap_sibling(lastnode);
    }
    while(LinkedHeap_isInternal(lastnode)) {
        lastnode = lastnode->leftChild;
    }
    return lastnode;
}
LinkedBinaryTreeNode* LinkedHeap_advanceLast(LinkedHeap* H) {
    LinkedBinaryTreeNode* lastnode = LinkedHeap_findLastNode(H);
    return LinkedHeap_advanceLastNode(H, lastnode);
}

LinkedBinaryTreeNode* LinkedHeap_retreatLastNode(LinkedHeap* H,LinkedBinaryTreeNode* lastnode) {
    while (lastnode != H->root && (lastnode->parent)->leftChild == lastnode)  {
        lastnode = lastnode->parent;
    }
    while (lastnode != H->root && (lastnode->parent)->rightChild == lastnode)  {
        lastnode = LinkedHeap_sibling(lastnode);
    }
    while(LinkedHeap_isInternal(lastnode)) {
        lastnode = lastnode->rightChild;
    }
    return lastnode->parent;
}
LinkedBinaryTreeNode* LinkedHeap_retreatLast(LinkedHeap* H) {
    LinkedBinaryTreeNode* lastnode = LinkedHeap_findLastNode(H);
    return LinkedHeap_retreatLastNode(H, lastnode);
}

int LinkedHeap_depth(LinkedBinaryTreeNode* node) {
    if (LinkedHeap_isRoot(node)) {
        return 0;
    } else {
        return 1 + LinkedHeap_depth(node->parent);
    }
}
int LinkedHeap_height(LinkedBinaryTreeNode* node) {
    if (LinkedHeap_isInternal(node)) {
        return 0;
    } else {
        int leftH = LinkedHeap_height(node->leftChild);
        int rightH = LinkedHeap_height(node->rightChild);
        if (leftH <= rightH) {
            return 1 + rightH;
        } else {
            return 1 + leftH;
        }        
    }
}

void LinkedHeap_upHeap_minHeap(LinkedBinaryTreeNode* node) {
    if (LinkedHeap_isRoot(node)) {
        return;
    }
    if (node->key <= (node->parent)->key) {
        return;
    }
    LinkedHeap_swap(node, node->parent);
    LinkedHeap_upHeap_minHeap(node->parent);
}
void LinkedHeap_downHeap_minHeap(LinkedBinaryTreeNode* node) {
    if (LinkedHeap_isExternal(node->leftChild) && LinkedHeap_isExternal(node->rightChild)) {
        return;
    }
    LinkedBinaryTreeNode* smaller = node->leftChild;
    if (LinkedHeap_isInternal(node->rightChild)) {
        if ((node->rightChild)->key < smaller->key) {
            smaller = node->rightChild;
        }
    }
    if (node->key <= smaller->key) {
        return;
    }
    LinkedHeap_swap(node, smaller);
    LinkedHeap_downHeap_minHeap(smaller);
}
void LinkedHeap_insertItem_minHeap(LinkedHeap* H, int k, int e) {
    LinkedBinaryTreeNode* newnode = LinkedHeap_advanceLast(H);
    newnode->key = k;
    newnode->element = e;
    H->size++;
    LinkedHeap_expandExternal(newnode);
    LinkedHeap_upHeap_minHeap(newnode);
}
LinkedBinaryTreeNode* LinkedHeap_removeMin_minHeap(LinkedHeap* H) {
    LinkedBinaryTreeNode* root = H->root;
    LinkedBinaryTreeNode* lastNode = LinkedHeap_findLastNode(H);
    (H->root)->key = lastNode->key;
    (H->root)->element = lastNode->element;
    LinkedBinaryTreeNode* node = LinkedHeap_retreatLast(H);
    LinkedBinaryTreeNode* z = lastNode->rightChild;
    reduceExternal(H, z);
    H->size--;
    LinkedHeap_downHeap_minHeap(H->root);

    root->leftChild = NULL;
    root->rightChild = NULL;
    return root;
}

void LinkedHeap_upHeap_maxHeap(LinkedBinaryTreeNode* node) {
    if (LinkedHeap_isRoot(node)) {
        return;
    }
    if (node->key >= (node->parent)->key) {
        return;
    }
    LinkedHeap_swap(node, node->parent);
    LinkedHeap_upHeap_maxHeap(node->parent);
}
void LinkedHeap_downHeap_maxHeap(LinkedBinaryTreeNode* node) {
    if (LinkedHeap_isExternal(node->leftChild) && LinkedHeap_isExternal(node->rightChild)) {
        return;
    }
    LinkedBinaryTreeNode* bigger = node->leftChild;
    if (LinkedHeap_isInternal(node->rightChild)) {
        if ((node->rightChild)->key > bigger->key) {
            bigger = node->rightChild;
        }
    }
    if (node->key >= bigger->key) {
        return;
    }
    LinkedHeap_swap(node, bigger);
    LinkedHeap_downHeap_maxHeap(bigger);
}
void LinkedHeap_insertItem_maxHeap(LinkedHeap* H, int k, int e) {
    LinkedBinaryTreeNode* newnode = LinkedHeap_advanceLast(H);
    newnode->key = k;
    newnode->element = e;
    H->size++;
    LinkedHeap_expandExternal(newnode);
    LinkedHeap_upHeap_maxHeap(newnode);
}
LinkedBinaryTreeNode* LinkedHeap_removeMax_maxHeap(LinkedHeap* H) {
    LinkedBinaryTreeNode* root = H->root;
    LinkedBinaryTreeNode* lastNode = LinkedHeap_findLastNode(H);
    (H->root)->key = lastNode->key;
    (H->root)->element = lastNode->element;
    LinkedBinaryTreeNode* node = LinkedHeap_retreatLast(H);
    LinkedBinaryTreeNode* z = lastNode->rightChild;
    reduceExternal(H, z);
    H->size--;
    LinkedHeap_downHeap_maxHeap(H->root);

    root->leftChild = NULL;
    root->rightChild = NULL;
    return root;
}

void LinkedHeap_expandExternalAll(LinkedBinaryTreeNode* node) {
    if(LinkedBinaryTree_isInternal(node)) {
        LinkedHeap_expandExternalAll(node->leftChild);
        LinkedHeap_expandExternalAll(node->rightChild);
    } else if (LinkedBinaryTree_isExternal(node)) {
        LinkedHeap_expandExternal(node);
    } else {
        if (node->leftChild == NULL) {
            LinkedBinaryTreeNode* left = LinkedBinaryTreeNode_getNode();
            if (left == NULL) {
                notEnoughMemory();
                return;
            }
            left->leftChild = NULL;
            left->rightChild = NULL;
            left->parent = node;
            node->leftChild = left;
        } else if (node->rightChild == NULL) {
            LinkedBinaryTreeNode* right = LinkedBinaryTreeNode_getNode();
            if (right == NULL) {
                notEnoughMemory();
                return;
            }
            right->leftChild = NULL;
            right->rightChild = NULL;
            right->parent = node;
            node->rightChild = right;
        }
    }
}

LinkedHeap* CompleteBinaryTreeConvert2LinkedHeap(LinkedBinaryTree* tree) {
    LinkedHeap* heap =  LinkedHeap_initialize(tree->type);
    if (heap == NULL) {
        return NULL;
    }
    heap->root = tree->root;
    heap->size = LinkedBinaryTree_binaryPreOrder(tree->root);
    LinkedHeap_expandExternalAll(heap->root);
    return heap;
}
LinkedHeap* ListConvert2LinkedHeap(SinglyLinkedList* list, int type) {
    LinkedBinaryTree* tree = ListConvert2CompleteBinaryTree(list, type);
    if (tree == NULL) {
        return NULL;
    }

    LinkedHeap* heap =  LinkedHeap_initialize(tree->type);
    if (heap == NULL) {
        return NULL;
    }
    heap->root = tree->root;
    heap->size = LinkedBinaryTree_binaryPreOrder(tree->root);
    LinkedHeap_expandExternalAll(heap->root);
    return heap;
}

// Build Bottom-Up Linked Heap
LinkedHeap* LinkedHeap_RecursiveBuildHeap_minHeap(SinglyLinkedList* list, int type) {    
    LinkedHeap* heap = ListConvert2LinkedHeap(list, type);
    if (heap == NULL) {
        return;
    }
    LinkedHeap_rBuildHeap_minHeap(heap->root);
    return heap;
}
void LinkedHeap_rBuildHeap_minHeap(LinkedBinaryTreeNode* node) {
    if (LinkedHeap_isRoot(node)) {
        return;
    }
    LinkedHeap_rBuildHeap_minHeap(node->leftChild);
    LinkedHeap_rBuildHeap_minHeap(node->rightChild);
    LinkedHeap_downHeap_minHeap(node);
}

LinkedHeap* LinkedHeap_RecursiveBuildHeap_maxHeap(SinglyLinkedList* list, int type) {    
    LinkedHeap* heap = ListConvert2LinkedHeap(list, type);
    if (heap == NULL) {
        return;
    }
    LinkedHeap_rBuildHeap_maxHeap(heap->root);
    return heap;
}
void LinkedHeap_rBuildHeap_maxHeap(LinkedBinaryTreeNode* node) {
    if (LinkedHeap_isRoot(node)) {
        return;
    }
    LinkedHeap_rBuildHeap_maxHeap(node->leftChild);
    LinkedHeap_rBuildHeap_maxHeap(node->rightChild);
    LinkedHeap_downHeap_maxHeap(node);
}

// #endif