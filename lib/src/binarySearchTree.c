/**
 * @file: binarySearchTree.c
 * @author: Anonyman637
 * @date: 6/17/2021; 7:51 PM
 */

#include <binarySearchTree.h>

/* ============================== BST_NODE ========================= */

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

/* ============================== BS TREE ========================= */

BST *bst_create() {
	BST *tree = malloc(sizeof(BST));
	if (tree) {
		tree->root = NULL;
	}
	
	return tree;
}

/* ============================== RECURSIVE ========================= */
BST_Node *bst_recursiveInsertNode(BST_Node *newNode, BST_Node *root) {
	if (root == NULL) {
		root = newNode;
		return root;
	}
	
	newNode->parent = root;
	
	if (newNode->data < root->data) {
		root->leftChild = bst_recursiveInsertNode(newNode, root->leftChild);
	} else {
		root->rightChild = bst_recursiveInsertNode(newNode, root->rightChild);
	}
	
	return root;
}

void bst_recursivePreOrderTraversal(BST_Node *root) {
	if (root == NULL) {
		return;
	}
	
	printf("%d ", root->data);
	bst_recursivePreOrderTraversal(root->leftChild);
	bst_recursivePreOrderTraversal(root->rightChild);
}

void bst_recursiveInOrderTraversal(BST_Node *root) {
	if (root == NULL) {
		return;
	}
	
	bst_recursiveInOrderTraversal(root->leftChild);
	printf("%d ", root->data);
	bst_recursiveInOrderTraversal(root->rightChild);
	
}

void bst_recursivePostOrderTraversal(BST_Node *root) {
	
	if (root == NULL) {
		return;
	}
	
	bst_recursivePostOrderTraversal(root->leftChild);
	bst_recursivePostOrderTraversal(root->rightChild);
	printf("%d ", root->data);
	
}

BST_Node *bst_recursiveSearch(int data, BST_Node *root) {
	if (root == NULL || root->data == data) {
		return root;
	} else if (data < root->data) {
		return bst_recursiveSearch(data, root->leftChild);
	} else {
		return bst_recursiveSearch(data, root->rightChild);
	}
	
}

BST_Node *bst_recursiveMaximum(BST_Node *root) {
	if (root->rightChild != NULL) {
		return bst_recursiveMaximum(root->rightChild);
	}
	
	return root;
}

BST_Node *bst_recursiveMinimum(BST_Node *root) {
	
	if (root->leftChild != NULL) {
		return bst_recursiveMaximum(root->leftChild);
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

BST_Node *bst_recursiveDeleteNode(BST_Node *node, BST_Node *root) {

}

void bst_recursiveFree(BST_Node *root) {
	if (root->leftChild != NULL) {
		bst_recursiveFree(root->leftChild);
	}
	
	if (root->rightChild != NULL) {
		bst_recursiveFree(root->rightChild);
	}
	
	free(root);
}

/* ============================== ITERATIVE ========================= */

void bst_insertNode(BST_Node *newNode, BST *tree) {

}

void bst_preOrderTraversal(BST *root) {

}

void bst_inOrderTraversal(BST *root) {}

void bst_postOrderTraversal(BST *root) {}

BST_Node *bst_search(int data, BST *tree) {
	BST_Node *root = tree->root;
	
	while (root != NULL && root->data != data) {
		if (data < root->data) {
			root = root->leftChild;
		} else {
			root = root->rightChild;
		}
	}
	
	return root;
}

BST_Node *bst_maximum(BST_Node *root) {
	while (root->rightChild) {
		root = root->rightChild;
	}
	
	return root;
}

BST_Node *bst_minimum(BST_Node *root) {
	while (root->leftChild) {
		root = root->leftChild;
	}
	
	return root;
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

void bst_deleteNode(BST_Node *node, BST *tree) {
	if (node->leftChild == NULL) {
		bst_transplantNode(node->rightChild, node, tree);
	} else if (node->rightChild == NULL) {
		bst_transplantNode(node->leftChild, node, tree);
	} else {
		BST_Node *nodeRightMinimum = bst_minimum(node->rightChild);
		if (node != nodeRightMinimum->parent) {
			nodeRightMinimum->parent->leftChild = nodeRightMinimum->rightChild;
			nodeRightMinimum->rightChild->parent = nodeRightMinimum->parent;
		} else {
		
		}
		
	}
	
	free(node);
}

void bst_free(BST *tree) {
	BST_Node *child = tree->root;
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

/* ============================== UTILITY ========================= */

void bst_transplantNode(BST_Node *transplanter, BST_Node *node, BST *tree) {
	if (node == node->parent->leftChild) {
		node->parent->leftChild = transplanter;
	} else {
		node->parent->rightChild = transplanter;
	}
	
	if (transplanter != NULL) {
		transplanter->parent = node->parent;
	}
	
	if (node->parent == NULL) {
		tree->root = transplanter;
	}
	
}
