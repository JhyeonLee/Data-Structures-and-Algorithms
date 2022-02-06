 #pragma once
// #ifdef __LINKEDBINARYTREE_H__
// #define __LINKEDBINARYTREE_H__
#include<stdlib.h>
#include "../utils/utils.h"
#include "./SinglyLinkedList.h"
#include "./LinkedBinaryTreeNode.h"
#include "./LinkedQueue.h"

typedef struct LinkedBinaryTree {
    LinkedBinaryTreeNode* root;
    int type; // ascending(1), descending(2)
} LinkedBinaryTree;

LinkedBinaryTree* LinkedBinaryTree_initialize(int type) {
    LinkedBinaryTree* newtree = (LinkedBinaryTree*)malloc(sizeof(LinkedBinaryTree));
    if (newtree == NULL) {
        notEnoughMemory();
        return NULL;
    }
    newtree->root = LinkedBinaryTreeNode_getNode();
    if (newtree->root == NULL) {
        return NULL;
    }
    newtree->type = type;
    return newtree;
}

int LinkedBinaryTree_element(LinkedBinaryTreeNode* node) {
    return node->element;
}
LinkedBinaryTreeNode* LinkedBinaryTree_root(LinkedBinaryTree* tree) {
    return tree->root;
}
int LinkedBinaryTree_isRoot(LinkedBinaryTreeNode* node) {
    return node->parent == NULL;
}
LinkedBinaryTreeNode* LinkedBinaryTree_parent(LinkedBinaryTreeNode* node) {
    return node->parent;
}
LinkedBinaryTreeNode* LinkedBinaryTree_leftChild(LinkedBinaryTreeNode* node) {
    return node->leftChild;
}
LinkedBinaryTreeNode* LinkedBinaryTree_righttChild(LinkedBinaryTreeNode* node) {
    return node->rightChild;
}
LinkedBinaryTreeNode* LinkedBinaryTree_sibling(LinkedBinaryTreeNode* node) {
    LinkedBinaryTreeNode* parent = node->parent;
    if (parent->leftChild == node) {
        return parent->rightChild;
    } else {
        return parent->leftChild;
    }
}
int LinkedBinaryTree_isInternal(LinkedBinaryTreeNode* node) {
    return node->leftChild != NULL && node->rightChild != NULL;
}
int LinkedBinaryTree_isExternal(LinkedBinaryTreeNode* node) {
    return node->leftChild == NULL && node->rightChild == NULL;
}
void LinkedBinaryTree_setElement(LinkedBinaryTreeNode* node, int k, int e) {
    node->key = k;
    node->element = e;
}
void LinkedBinaryTree_swap(LinkedBinaryTreeNode* v, LinkedBinaryTreeNode* w) {
    int k = v->key;
    v->key = w->key;
    w->key = k;

    int e = v->element;
    v->element = w->element;
    w->element = e;
}

int LinkedBinaryTree_depth(LinkedBinaryTreeNode* node) {
    if (LinkedBinaryTree_isRoot(node)) {
        return 0;
    } else {
        return 1 + LinkedBinaryTree_depth(node->parent);
    }
}
int LinkedBinaryTree_height(LinkedBinaryTreeNode* node) {
    if (LinkedBinaryTree_isInternal(node)) {
        return 0;
    } else {
        int leftH = LinkedBinaryTree_height(node->leftChild);
        int rightH = LinkedBinaryTree_height(node->rightChild);
        if (leftH <= rightH) {
            return 1 + rightH;
        } else {
            return 1 + leftH;
        }        
    }
}
int LinkedBinaryTree_binaryPreOrder(LinkedBinaryTreeNode* node) {
    int count = 0;
    printf("key: %d, element: %d\n", node->key, node->element);
    if(LinkedBinaryTree_isInternal(node)) {
        count += LinkedBinaryTree_binaryPreOrder(node->leftChild);
        count += LinkedBinaryTree_binaryPreOrder(node->rightChild);
    }
    return count;
}
int LinkedBinaryTree_binaryPostOrder(LinkedBinaryTreeNode* node) {
    int count = 0;
    if(LinkedBinaryTree_isInternal(node)) {
        count += LinkedBinaryTree_binaryPostOrder(node->leftChild);
        count += LinkedBinaryTree_binaryPostOrder(node->rightChild);
    }
    printf("key: %d, element: %d\n", node->key, node->element);
    return count;
}
int LinkedBinaryTree_binaryInOrder(LinkedBinaryTreeNode* node) {
    int count = 0;
    if(LinkedBinaryTree_isInternal(node)) {
        count += LinkedBinaryTree_binaryInOrder(node->leftChild);
    }
    printf("key: %d, element: %d\n", node->key, node->element);
    if(LinkedBinaryTree_isInternal(node)) {
        count += LinkedBinaryTree_binaryInOrder(node->rightChild);
    }
    return count;
}
void LinkedBinaryTree_levelOrder(LinkedBinaryTreeNode* node) {
    LinkedQueue* Q = LinkedQueue_initialize();
    if (Q == NULL) {
        return;
    }
    LinkedQueue_enqueue(Q, node);
    while(!LinkedQueue_isEmpty(Q)) {
        node = LinkedQueue_dequeue(Q);
        // visit(v);
        if (LinkedBinaryTree_isInternal(node->leftChild)) {
            LinkedQueue_enqueue(Q, node->leftChild);
        }
        if (LinkedBinaryTree_isInternal(node->rightChild)) {
            LinkedQueue_enqueue(Q, node->rightChild);
        }
    }
}
float LinkedBinaryTree_eulerTour(LinkedBinaryTreeNode* node) {
    float count = 0;
    printf("key: %d, element: %d\n", node->leftChild->key, node->leftChild->element);
    if(LinkedBinaryTree_isInternal(node)) {
        count += LinkedBinaryTree_eulerTour(node->leftChild);
    }
    printf("key: %d, element: %d\n", node->key, node->element);
    if(LinkedBinaryTree_isInternal(node)) {
        count += LinkedBinaryTree_eulerTour(node->rightChild);
    }
    printf("key: %d, element: %d\n", node->rightChild->key, node->rightChild->element);
    return count;
}

LinkedBinaryTreeNode* LinkedBinaryTree_preOrderSucc(LinkedBinaryTreeNode* node) {
    if (LinkedBinaryTree_isInternal(node)) {
        return node->leftChild;
    }
    LinkedBinaryTreeNode* parent = node->parent;
    while(parent->leftChild != node) {
        if (LinkedBinaryTree_isRoot(parent)) {
            invalidNodeException();
            return NULL;
        }
        node = parent;
        parent = parent->parent;
    }
    return parent->rightChild;
}
LinkedBinaryTreeNode* LinkedBinaryTree_inOrderSucc(LinkedBinaryTreeNode* node) {
    if (LinkedBinaryTree_isInternal(node)) {
        node = node->rightChild;
        while(LinkedBinaryTree_isInternal(node)) {
            node = node->leftChild;
        }
        return node;
    }
    LinkedBinaryTreeNode* parent = node->parent;
    while(parent->leftChild != node) {
        if (LinkedBinaryTree_isRoot(parent)) {
            invalidNodeException();
            return NULL;
        }
        node = parent;
        parent = parent->parent;
    }
    return parent;
}
LinkedBinaryTreeNode* LinkedBinaryTree_postOrderSucc(LinkedBinaryTreeNode* node) {
    if (LinkedBinaryTree_isRoot(node)) {
        invalidNodeException();
        return NULL;
    }
    LinkedBinaryTreeNode* parent = node->parent;
    while(parent->rightChild != node) {
        return parent;
    }
    node = parent->rightChild;
    while(!LinkedBinaryTree_isExternal(node)) {
        node = node->leftChild;
    }
    return node;
}

LinkedBinaryTree* ListConvert2CompleteBinaryTree(SinglyLinkedList* list, int type) {
    LinkedBinaryTree* tree = LinkedBinaryTree_initialize(type);
    if (tree == NULL) {
        return NULL;
    }
    
    LinkedQueue* Q = LinkedQueue_initialize();
    if (Q == NULL) {
        return;
    }
    LinkedBinaryTreeNode* node = tree->root;
    LinkedQueue_enqueue(Q, node);
    while(!SinglyLinkedList_isEmpty(list)) {
        node = LinkedQueue_dequeue(Q);
        // visit(v);
        node->leftChild = SinglyLinkedList_removeFirst(list);
        if(node->leftChild == NULL) {
            break;
        }
        LinkedQueue_enqueue(Q, node->leftChild);
        node->rightChild = SinglyLinkedList_removeFirst(list);
        if(node->rightChild == NULL) {
            break;
        }
        LinkedQueue_enqueue(Q, node->rightChild);
    }

    return tree;
}

// #endif