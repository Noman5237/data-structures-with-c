/**
 * @file: BinarySearchTree.h
 * @author: Anonyman637
 * @date: 8/5/2021; 2:35 PM
 */

#ifndef DATASTRUCTURESCOURSE_BST_H
#define DATASTRUCTURESCOURSE_BINARYSEARCHTREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
	int data;
	struct Node *parent;
	struct Node *left;
	struct Node *right;
} Node;

Node *node_create(int data);

void node_free(Node *node);

Node *bst_insert(int data, Node *root);

Node *bst_search(int data, Node *root);

Node *bst_minimum(Node *root);

Node *bst_remove(int data, Node *root);

void bst_print(Node *root);

void bst_free(Node *root);

#endif //DATASTRUCTURESCOURSE_BST_H
