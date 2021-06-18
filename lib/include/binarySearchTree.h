/**
 * @file: binarySearchTree.h
 * @author: Anonyman637
 * @date: 6/17/2021; 7:51 PM
 */

#ifndef DATASTRUCTURESCOURSE_BINARYSEARCHTREE_H
#define DATASTRUCTURESCOURSE_BINARYSEARCHTREE_H

#include <dsCommon.h>

/* ============================== BST_NODE ========================= */

typedef struct BST_Node {
	int data;
	
	struct BST_Node *parent;
	struct BST_Node *leftChild;
	struct BST_Node *rightChild;
} BST_Node;

BST_Node *bst_node_create(int data);

/* ============================== BS TREE ========================= */

typedef struct BST {
	BST_Node *root;
} BST;

BST *bst_create();

/* ============================== RECURSIVE ========================= */

BST_Node *bst_recursiveInsertNode(BST_Node *newNode, BST_Node *root);

void bst_recursivePreOrderTraversal(BST_Node *root);

void bst_recursiveInOrderTraversal(BST_Node *root);

void bst_recursivePostOrderTraversal(BST_Node *root);

BST_Node *bst_recursiveSearch(int data, BST_Node *root);

BST_Node *bst_recursiveMaximum(BST_Node *root);

BST_Node *bst_recursiveMinimum(BST_Node *root);

BST_Node *bst_recursiveInOrderPredecessor(BST_Node *node);

BST_Node *bst_recursiveInOrderSuccessor(BST_Node *node);

BST_Node *bst_recursiveDeleteNode(BST_Node *node, BST_Node *root);

void bst_recursiveFree(BST_Node *root);

/* ============================== ITERATIVE ========================= */

void bst_insertNode(BST_Node *newNode, BST *tree);

void bst_preOrderTraversal(BST *tree);

void bst_inOrderTraversal(BST *tree);

void bst_postOrderTraversal(BST *tree);

BST_Node *bst_search(int data, BST *tree);

BST_Node *bst_maximum(BST *tree);

BST_Node *bst_minimum(BST *tree);

BST_Node *bst_InOrderPredecessor(BST *tree);

BST_Node *bst_InOrderSuccessor(BST *tree);

void bst_deleteNode(BST_Node *node, BST *tree);

void bst_free(BST *tree);

#endif //DATASTRUCTURESCOURSE_BINARYSEARCHTREE_H
