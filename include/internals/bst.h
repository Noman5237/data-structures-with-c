/**
 * @file: bst.h
 * @author: Anonyman637
 * @date: 9/12/2021; 11:14 AM
 */

#ifndef DATASTRUCTURESCOURSE_INTERNAL_BST_H
#define DATASTRUCTURESCOURSE_INTERNAL_BST_H

#include <dscommon.h>
#include <bst.h>

/* ============================== BST_NODE ========================= */

typedef struct BSTNode {
	let datum;
	
	struct BSTNode *parent;
	struct BSTNode *leftChild;
	struct BSTNode *rightChild;
} BSTNode;

/* ============================== BS TREE ========================= */

typedef struct BSTData {
	BSTNode *root;
} BSTData;

/* ============================== Data Functions ========================= */

BSTNode *bst_node_new(Any *datum);

void bst_node_destroy(BSTNode *node);

BSTData *bst_data_new();

void bst_data_destroy(Any *this);

/* ============================== Helper Functions ========================= */

/* ============================== RECURSIVE ========================= */

BSTNode *bst_recursiveInsertNode(BSTNode *root, BSTNode *newNode);

void bst_recursivePreOrderTraversal(BSTNode *root);

void bst_recursiveInOrderTraversal(BSTNode *root);

void bst_recursivePostOrderTraversal(BSTNode *root);

BSTNode *bst_recursiveSearch(BSTNode *root, Any *itemToSearch);

BSTNode *bst_recursiveMaximum(BSTNode *root);

BSTNode *bst_recursiveMinimum(BSTNode *root);

BSTNode *bst_recursiveInOrderPredecessor(BSTNode *node);

__attribute__((unused)) BSTNode *bst_recursiveInOrderSuccessor(BSTNode *node);

BSTNode *bst_recursiveRemoveNode(BSTNode *root, BSTNode *node);

void bst_recursiveDestroy(BSTNode *root);

/* ============================== ITERATIVE ========================= */

void bst_insertNode(BSTNode *newNode, BSTData *tree);

void bst_preOrderTraversal(BSTData *tree);

void bst_inOrderTraversal(BSTData *tree);

void bst_postOrderTraversal(BSTData *tree);

BSTNode *bst_search(int data, BSTData *tree);

BSTNode *bst_maximum(BSTNode *root);

BSTNode *bst_minimum(BSTNode *root);

BSTNode *bst_InOrderPredecessor(BSTNode *node);

BSTNode *bst_InOrderSuccessor(BSTNode *node);

void bst_deleteNode(BSTNode *node, BSTData *tree);

void bst_free(BSTData *tree);

/* ============================== UTILITY ========================= */

void bst_transplantNode(BSTNode *transplanter, BSTNode *node, BSTData *tree);

BSTNode bst_leftRotate(BSTNode *node);

BSTNode bst_rightRotate(BSTNode *node);

#endif //DATASTRUCTURESCOURSE_INTERNAL_BST_H
