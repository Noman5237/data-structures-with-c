/**
 * @file: BinarySearchTree.c
 * @author: Anonyman637
 * @date: 8/5/2021; 2:35 PM
 */
#include "BinarySearchTree.h"

Node *node_create(int data) {
	Node *node = (Node *) malloc(sizeof(Node));
	node->data = data;
	node->parent = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void node_free(Node *node) {
	free(node);
}

Node *bst_insert(int data, Node *root) {
	Node *node = node_create(data);
	if (root == NULL) {
		root = node;
	} else if (data <= root->data) {
		root->left = bst_insert(data, root->left);
	} else {
		root->right = bst_insert(data, root->right);
	}
	
	return root;
}

int SEARCH_OPS_COUNT = 0;

Node *bst_search(int data, Node *root) {
	if (root == NULL) {
		++SEARCH_OPS_COUNT;
		return NULL;
	}
	
	if (root->data == data) {
		++SEARCH_OPS_COUNT;
		return root;
	} else if (data < root->data) {
		++SEARCH_OPS_COUNT;
		return bst_search(data, root->left);
	} else {
		++SEARCH_OPS_COUNT;
		return bst_search(data, root->right);
	}
}

Node *bst_minimum(Node *root) {
	if (root->left == NULL) {
		return root;
	} else {
		return bst_minimum(root->left);
	}
}

Node *bst_remove(int data, Node *root) {
	if (root == NULL) {
		return NULL;
	}
	
	if (data < root->data) {
		root->left = bst_remove(data, root->left);
	} else if (data > root->data) {
		root->right = bst_remove(data, root->right);
	} else {
		Node *replacer;
		if (root->left == NULL) {
			replacer = root->right;
			node_free(root);
			return replacer;
		}
		
		if (root->right == NULL) {
			replacer = root->left;
			node_free(root);
			return replacer;
		}
		
		// local in order successor
		replacer = bst_minimum(root->right);
		root->data = replacer->data;
		root->right = bst_remove(replacer->data, root->right);
	}
	
	return root;
}

void bst_print(Node *root) {
	if (root->left != NULL) {
		bst_print(root->left);
	}
	
	printf("%d, ", root->data);
	
	if (root->right != NULL) {
		bst_print(root->right);
	}
}

void bst_free(Node *root) {
	
	if (root->left != NULL) {
		bst_free(root->left);
	}
	
	if (root->right != NULL) {
		bst_free(root->right);
	}
	
	node_free(root);
	
}
