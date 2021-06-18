/**
 * @file: binarySearchTree.h
 * @author: Anonyman637
 * @date: 6/17/2021; 7:51 PM
 */

#ifndef DATASTRUCTURESCOURSE_BINARYSEARCHTREE_H
#define DATASTRUCTURESCOURSE_BINARYSEARCHTREE_H

#include <dsCommon.h>

typedef struct BST_Node {
	int data;
	
	struct BST_Node *parent;
	struct BST_Node *leftChild;
	struct BST_Node *rightChild;
} BST_Node;

BST_Node *bst_node_create(int data);

int bst_isEmpty(BST_Node *root);

void bst_recursivePreOrderTraversal(BST_Node *root);

void bst_preOrderTraversal(BST_Node *root);

void bst_recursiveInOrderTraversal(BST_Node *root);

void bst_inOrderTraversal(BST_Node *root);

void bst_recursivePostOrderTraversal(BST_Node *root);

void bst_postOrderTraversal(BST_Node *root);

BST_Node *bst_recursiveSearch(int data, BST_Node *root);

BST_Node *bst_search(int data, BST_Node *root);

BST_Node *bst_recursiveMaximum(BST_Node *root);

BST_Node *bst_maximum(BST_Node *root);

BST_Node *bst_recursiveMinimum(BST_Node *root);

BST_Node *bst_minimum(BST_Node *root);

BST_Node *bst_recursiveInOrderPredecessor(BST_Node *node);

BST_Node *bst_InOrderPredecessor(BST_Node *node);

BST_Node *bst_recursiveInOrderSuccessor(BST_Node *node);

BST_Node *bst_InOrderSuccessor(BST_Node *node);

void bst_recursiveFree(BST_Node *root);

void bst_free(BST_Node *root);


#endif //DATASTRUCTURESCOURSE_BINARYSEARCHTREE_H
