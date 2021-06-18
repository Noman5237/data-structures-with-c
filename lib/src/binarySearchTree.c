/**
 * @file: binarySearchTree.c
 * @author: Anonyman637
 * @date: 6/17/2021; 7:51 PM
 */

#include <binarySearchTree.h>


BST_Node *bst_node_create(int data) {
	BST_Node *newNode = malloc(sizeof(BST_Node));
	if (newNode) {
		newNode->data = data;
		newNode->parent = NULL;
		newNode->leftChild = NULL;
		newNode->rightChild = NULL;
	}
	
	return newNode;
}

int bst_isEmpty(BST_Node *root) {
	return root == NULL;
}

void bst_recursivePreOrderTraversal(BST_Node *root) {
	if (root == NULL) {
		return;
	}
	
	printf("%d ", root->data);
	bst_recursivePreOrderTraversal(root->leftChild);
	bst_recursivePreOrderTraversal(root->rightChild);
}

void bst_preOrderTraversal(BST_Node *root) {

}

void bst_recursiveInOrderTraversal(BST_Node *root) {
	if (root == NULL) {
		return;
	}
	
	bst_recursiveInOrderTraversal(root->leftChild);
	printf("%d ", root->data);
	bst_recursiveInOrderTraversal(root->rightChild);
	
}

void bst_inOrderTraversal(BST_Node *root) {}

void bst_recursivePostOrderTraversal(BST_Node *root) {
	
	if (root == NULL) {
		return;
	}
	
	bst_recursivePostOrderTraversal(root->leftChild);
	bst_recursivePostOrderTraversal(root->rightChild);
	printf("%d ", root->data);
	
}

void bst_postOrderTraversal(BST_Node *root) {}

BST_Node *bst_recursiveSearch(int data, BST_Node *root) {
	if (root == NULL || root->data == data) {
		return root;
	} else if (data < root->data) {
		return bst_recursiveSearch(data, root->leftChild);
	} else {
		return bst_recursiveSearch(data, root->rightChild);
	}
	
}

BST_Node *bst_search(int data, BST_Node *root) {
	while (root != NULL || root->data != data) {
		if (data < root->data) {
			root = root->leftChild;
		} else {
			root = root->rightChild;
		}
	}
	
	return root;
}

BST_Node *bst_recursiveMaximum(BST_Node *root) {
	if (root->rightChild != NULL) {
		return bst_recursiveMaximum(root->rightChild);
	}
	
	return root;
}

BST_Node *bst_maximum(BST_Node *root) {
	while (root->rightChild) {
		root = root->rightChild;
	}
	
	return root;
}

BST_Node *bst_recursiveMinimum(BST_Node *root) {
	
	if (root->leftChild != NULL) {
		return bst_recursiveMaximum(root->leftChild);
	}
	
	return root;
}

BST_Node *bst_minimum(BST_Node *root) {
	
	while (root->leftChild) {
		root = root->leftChild;
	}
	
	return root;
}

BST_Node *bst_recursiveInOrderPredecessor(BST_Node *node) {
	if (node->leftChild != NULL) {
		return bst_recursiveMaximum(node->leftChild);
	}
	
	BST_Node *ancestor = node->parent;
	while (ancestor->leftChild == node) {
		node = ancestor;
		ancestor = ancestor->parent;
	}
	
	return ancestor;
	
}

BST_Node *bst_InOrderPredecessor(BST_Node *node) {
	if (node->leftChild != NULL) {
		return bst_maximum(node->leftChild);
	}
	
	BST_Node *ancestor = node->parent;
	while (ancestor->leftChild == node) {
		node = ancestor;
		ancestor = ancestor->parent;
	}
	
	return ancestor;
	
	
}

BST_Node *bst_recursiveInOrderSuccessor(BST_Node *node) {
	if (node->rightChild != NULL) {
		return bst_recursiveMinimum(node->rightChild);
	}
	
	BST_Node *ancestor = node->parent;
	while (ancestor->rightChild == node) {
		node = ancestor;
		ancestor = ancestor->parent;
	}
	
	return ancestor;
}

BST_Node *bst_InOrderSuccessor(BST_Node *node) {
	
	if (node->rightChild != NULL) {
		return bst_maximum(node->rightChild);
	}
	
	BST_Node *ancestor = node->parent;
	while (ancestor->rightChild == node) {
		node = ancestor;
		ancestor = ancestor->parent;
	}
	
	return ancestor;
}

void bst_recursiveFree(BST_Node *root) {
	if (root->leftChild != NULL) {
		bst_recursiveFree(root->leftChild);
	}
	
	if (root->rightChild != NULL) {
		bst_recursiveFree(root->leftChild);
	}
	
	free(root);
}

void bst_free(BST_Node *root) {
	BST_Node *child = root;
	BST_Node *parent = child->parent;
	
	do {
		if (child->leftChild != NULL) {
			parent = child;
			child = parent->leftChild;
			parent->leftChild = NULL;
			continue;
		}
		
		if (child->rightChild != NULL) {
			parent = child;
			child = parent->rightChild;
			parent->rightChild = NULL;
			continue;
		}
		
		free(child);
		child = parent;
		parent = child->parent;
		
	} while (parent);
	
}
