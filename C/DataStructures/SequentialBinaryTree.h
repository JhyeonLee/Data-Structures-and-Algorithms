 #pragma once
// #ifdef __SEQUENTIALBINARYTREE_H__
// #define __SEQUENTIALBINARYTREE_H__
#include<stdlib.h>
#include "../utils/utils.h"

#include "./SequentialBinaryTreeNode.h"

typedef struct SequentialBinaryTree {
    SequentialBinaryTreeNode** nodes;\
    int acceptableSize;
    int n;
    int type; // ascending(1), descending(2)
} SequentialBinaryTree;

SequentialBinaryTree* SequentialBinaryTree_initialize(int N, int type) {
    SequentialBinaryTree* newTree = (SequentialBinaryTree*)malloc(sizeof(SequentialBinaryTree));
    if (newTree == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newTree->nodes = (SequentialBinaryTreeNode**)malloc((N+1)*sizeof(SequentialBinaryTreeNode*));
    if (newTree->nodes == NULL) {
        notEnoughMemory();
        return NULL;
    }
    for(int i = 0; i < N+1; i++) {
        newTree->nodes = NULL;
    }
    newTree->nodes[0] = SequentialBinaryTreeNode_getNode();
    newTree->acceptableSize = N;
    newTree->n = 0;
    newTree->type = type;
    return newTree;
}

int SequentialBinaryTree_element(SequentialBinaryTree* tree, int v) {
    return tree->nodes[v]->element;
}
int SequentialBinaryTree_root() {
    return 1;
}
int SequentialBinaryTree_isRoot(int v) {
    return v == 1;
}
int SequentialBinaryTree_parent(int v) {
    return v / 2;
}
int SequentialBinaryTree_lefChild(int v) {
    return 2 * v;
}
int SequentialBinaryTree_rightChild(int v) {
    return 2 * v + 1;
}
int SequentialBinaryTree_sibling(int v) {
    if (even(v)) {
        return v + 1;
    } else {
        return v - 1;
    }
}
int SequentialBinaryTree_isInternal(SequentialBinaryTree* tree, int v) {
    return 2*v < tree->acceptableSize && tree->nodes[2*v] != NULL;
}
int SequentialBinaryTree_isExternal(SequentialBinaryTree* tree, int v) {
    return 2*v >= tree->acceptableSize || tree->nodes[2*v] == NULL;
}
void SequentialBinaryTree_setElement(SequentialBinaryTree* tree, int v, int k, int e){
    tree->nodes[v]->key = k;
    tree->nodes[v]->element = e;
}
void SequentialBinaryTree_swap(SequentialBinaryTree* tree, int v, int w) {
    int k = tree->nodes[v]->key;
    tree->nodes[v]->key = tree->nodes[w]->key;
    tree->nodes[w]->key = k;

    int e = tree->nodes[v]->element;
    tree->nodes[v]->element = tree->nodes[w]->element;
    tree->nodes[w]->element = e;
}

int SequentialBinaryTree_depth(int v) {
    if (SequentialBinaryTree_isRoot(v)) {
        return 0;
    } else {
        1 + SequentialBinaryTree_depth(SequentialBinaryTree_parent(v));
    }
}
int SequentialBinaryTree_height(SequentialBinaryTree* tree, int v) {
    if (SequentialBinaryTree_isInternal(tree, v)) {
        return 0;
    } else {
        int leftH = SequentialBinaryTree_height(tree, tree->nodes[v]->leftChild);
        int rightH = SequentialBinaryTree_height(tree, tree->nodes[v]->rightChild);
        if (leftH <= rightH) {
            return 1 + rightH;
        } else {
            return 1 + leftH;
        } 
    }
}

void SequentialBinaryTree_binaryPreOrder(SequentialBinaryTree* tree, int v) {
    printf("key: %d, element: %d\n", tree->nodes[v]->key, tree->nodes[v]->element);
    if(SequentialBinaryTree_isInternal(tree, v)) {
        SequentialBinaryTree_binaryPreOrder(tree, tree->nodes[v]->leftChild);
        SequentialBinaryTree_binaryPreOrder(tree, tree->nodes[v]->rightChild);
    }
}
void SequentialBinaryTree_binaryPostOrder(SequentialBinaryTree* tree, int v) {
    if(SequentialBinaryTree_isInternal(tree, v)) {
        SequentialBinaryTree_binaryPostOrder(tree, tree->nodes[v]->leftChild);
        SequentialBinaryTree_binaryPostOrder(tree, tree->nodes[v]->rightChild);
    }
    printf("key: %d, element: %d\n", tree->nodes[v]->key, tree->nodes[v]->element);
}
void SequentialBinaryTree_binaryInOrder(SequentialBinaryTree* tree, int v) {
    if(SequentialBinaryTree_isInternal(tree, v)) {
        SequentialBinaryTree_binaryInOrder(tree, tree->nodes[v]->leftChild);
    }
    printf("key: %d, element: %d\n", tree->nodes[v]->key, tree->nodes[v]->element);
    if(SequentialBinaryTree_isInternal(tree, v)) {
        SequentialBinaryTree_binaryInOrder(tree, tree->nodes[v]->rightChild);
    }
}
void SequentialBinaryTree_eulerTour(SequentialBinaryTree* tree, int v) {
    printf("key: %d, element: %d\n", tree->nodes[tree->nodes[v]->leftChild]->key, tree->nodes[tree->nodes[v]->leftChild]->element);
    if(SequentialBinaryTree_isInternal(tree, v)) {
        SequentialBinaryTree_eulerTour(tree, tree->nodes[v]->leftChild);
    }
    printf("key: %d, element: %d\n", tree->nodes[v]->key, tree->nodes[v]->element);
    if(SequentialBinaryTree_isInternal(tree, v)) {
        SequentialBinaryTree_eulerTour(tree, tree->nodes[v]->rightChild);
    }
    printf("key: %d, element: %d\n", tree->nodes[tree->nodes[v]->rightChild]->key, tree->nodes[tree->nodes[v]->rightChild]->element);
}

int SequentialBinaryTree_preOrderSucc(SequentialBinaryTree* tree, int v) {
    if (SequentialBinaryTree_isInternal(tree, v)) {
        return tree->nodes[v]->leftChild;
    }
    int parent = tree->nodes[v]->parent;
    while(tree->nodes[parent]->leftChild != v) {
        if (SequentialBinaryTree_isRoot(parent)) {
            invalidNodeException();
            return NULL;
        }
        v = parent;
        parent = tree->nodes[parent]->parent;
    }
    return tree->nodes[parent]->rightChild;
}
int SequentialBinaryTree_inOrderSucc(SequentialBinaryTree* tree, int v) {
    if (SequentialBinaryTree_isInternal(tree, v)) {
        v = tree->nodes[v]->rightChild;
        while(SequentialBinaryTree_isInternal(tree, v)) {
            v = tree->nodes[v]->leftChild;
        }
        return v;
    }
    int parent = tree->nodes[v]->parent;
    while(tree->nodes[parent]->leftChild != v) {
        if (SequentialBinaryTree_isRoot(parent)) {
            invalidNodeException();
            return NULL;
        }
        v = parent;
        parent = tree->nodes[parent]->parent;
    }
    return parent;
}
int SequentialBinaryTree_postOrderSucc(SequentialBinaryTree* tree, int v) {
    if (SequentialBinaryTree_isRoot(v)) {
        invalidNodeException();
        return NULL;
    }
    int parent = tree->nodes[v]->parent;
    while(tree->nodes[parent]->rightChild != v) {
        return parent;
    }
    v = tree->nodes[parent]->rightChild;
    while(!SequentialBinaryTree_isExternal(tree, v)) {
        v = tree->nodes[v]->leftChild;
    }
    return v;
}

// #endif