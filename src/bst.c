/**
 * @file: binarySearchTree.c
 * @author: Anonyman637
 * @date: 6/17/2021; 7:51 PM
 */

#include <internals/bst.h>

/* ============================== Runtime Registry ========================= */

Type *t_bst;

void t_bst_register() {
	if (t_bst != NULL) {
		return;
	}
	
	t_bst = type_new("BinarySearchTree");
	t_bst->print = bst_print;
	t_bst->destroyData = bst_data_destroy;
}

void t_bst_deregister() {
	if (t_bst == NULL) {
		return;
	}
	
	type_destroy(t_bst);
	t_bst = NULL;
}

/* ============================== BST_NODE ========================= */

BSTNode *bst_node_new(Any *datum) {
	BSTNode *newNode = malloc(sizeof(BSTNode));
	newNode->datum = datum;
	newNode->parent = NULL;
	newNode->leftChild = NULL;
	newNode->rightChild = NULL;
	
	return newNode;
}

void bst_node_destroy(BSTNode *node) {
	any_destroy(node->datum);
	free(node);
}

/* ============================== BS TREE ========================= */

BSTData *bst_data_new() {
	BSTData *tree = malloc(sizeof(BSTData));
	tree->root = NULL;
	
	return tree;
}

void bst_data_destroy(Any *this) {
	BSTData *tree = this->data;
	bst_recursiveDestroy(tree->root);
	free(tree);
}

/* ============================== Core Type Functions ========================= */

Any *BinarySearchTree() {
	BSTData *tree = bst_data_new();
	let this = any_new(tree, t_bst);
	return this;
}

void bst_print(Any *this) {
	BSTData *tree = this->data;
	
	printf("[");
	bst_recursiveInOrderTraversal(tree->root);
	printf("]");
}

/* ============================== Advanced Type Functions ========================= */

int bst_size(Any *this) {
	return 0;
}

int bst_isEmpty(Any *this) {
	return 1;
}

void bst_append(Any *this, Any *newDatum) {
	BSTData *tree = this->data;
	BSTNode *newNode = bst_node_new(newDatum);
	tree->root = bst_recursiveInsertNode(tree->root, newNode);
}

Any *bst_get(Any *this, int index) {
	return NULL;
}

void bst_remove(Any *this, int index) {

}

int bst_getIndexOf(Any *this, Any *itemToSearch) {
	return -1;
}

/* ============================== Helper Functions ========================= */

/* ============================== RECURSIVE ========================= */

BSTNode *bst_recursiveInsertNode(BSTNode *root, BSTNode *newNode) {
	if (root == NULL) {
		root = newNode;
		return root;
	}
	
	newNode->parent = root;
	
	if (any_compare(newNode->datum, root->datum) < 0) {
		root->leftChild = bst_recursiveInsertNode(root->leftChild, newNode);
	} else {
		root->rightChild = bst_recursiveInsertNode(root->rightChild, newNode);
	}
	
	return root;
}

void bst_recursivePreOrderTraversal(BSTNode *root) {
	if (root == NULL) {
		return;
	}
	
	any_print(root->datum);
	printf(", ");
	
	bst_recursivePreOrderTraversal(root->leftChild);
	bst_recursivePreOrderTraversal(root->rightChild);
}

void bst_recursiveInOrderTraversal(BSTNode *root) {
	if (root == NULL) {
		return;
	}
	
	bst_recursiveInOrderTraversal(root->leftChild);
	
	any_print(root->datum);
	printf(", ");
	
	bst_recursiveInOrderTraversal(root->rightChild);
}

void bst_recursivePostOrderTraversal(BSTNode *root) {
	if (root == NULL) {
		return;
	}
	
	bst_recursivePostOrderTraversal(root->leftChild);
	bst_recursivePostOrderTraversal(root->rightChild);
	
	any_print(root->datum);
	printf(", ");
}

BSTNode *bst_recursiveSearch(BSTNode *root, Any *itemToSearch) {
	if (root == NULL || any_compare(root->datum, itemToSearch) == 0) {
		return root;
	} else if (any_compare(itemToSearch, root->datum) < 0) {
		return bst_recursiveSearch(root->leftChild, itemToSearch);
	} else {
		return bst_recursiveSearch(root->rightChild, itemToSearch);
	}
}

BSTNode *bst_recursiveMaximum(BSTNode *root) {
	if (root == NULL) {
		return NULL;
	}
	
	if (root->rightChild != NULL) {
		return bst_recursiveMaximum(root->rightChild);
	}
	
	return root;
}

BSTNode *bst_recursiveMinimum(BSTNode *root) {
	if (root == NULL) {
		return NULL;
	}
	
	if (root->leftChild != NULL) {
		return bst_recursiveMaximum(root->leftChild);
	}
	
	return root;
}

BSTNode *bst_recursiveInOrderPredecessor(BSTNode *node) {
	if (node == NULL) {
		return NULL;
	}
	
	if (node->leftChild != NULL) {
		return bst_recursiveMaximum(node->leftChild);
	}
	
	BSTNode *ancestor = node->parent;
	while (ancestor->leftChild == node) {
		node = ancestor;
		ancestor = ancestor->parent;
	}
	
	return ancestor;
}

BSTNode *bst_recursiveInOrderSuccessor(BSTNode *node) {
	if (node == NULL) {
		return NULL;
	}
	
	if (node->rightChild != NULL) {
		return bst_recursiveMinimum(node->rightChild);
	}
	
	BSTNode *ancestor = node->parent;
	while (ancestor->rightChild == node) {
		node = ancestor;
		ancestor = ancestor->parent;
	}
	
	return ancestor;
}

BSTNode *bst_recursiveRemoveNode(BSTNode *root, BSTNode *node) {
	if (root == NULL) {
		return NULL;
	}
	
	if (any_compare(node->datum, root->datum) < 0) {
		root->leftChild = bst_recursiveRemoveNode(root->leftChild, node);
	} else if (any_compare(node->datum, root->datum) > 0) {
		root->rightChild = bst_recursiveRemoveNode(root->rightChild, node);
	} else {
		BSTNode *replacer;
		if (root->leftChild == NULL) {
			replacer = root->rightChild;
			bst_node_destroy(root);
			return replacer;
		}
		
		if (root->rightChild == NULL) {
			replacer = root->leftChild;
			bst_node_destroy(root);
			return replacer;
		}
		
		// local in order successor
		replacer = bst_recursiveMinimum(root->rightChild);
		root->datum = replacer->datum;
		root->rightChild = bst_recursiveRemoveNode(root->rightChild, replacer);
	}
	
	return root;
}

void bst_recursiveDestroy(BSTNode *root) {
	if (root == NULL) {
		return;
	}
	
	if (root->leftChild != NULL) {
		bst_recursiveDestroy(root->leftChild);
	}
	
	if (root->rightChild != NULL) {
		bst_recursiveDestroy(root->rightChild);
	}
	
	bst_node_destroy(root);
}

///* ============================== ITERATIVE ========================= */
//
//void bst_insertNode(BSTNode *newNode, BSTData *tree) {
//	if (tree->root == NULL) {
//		tree->root = newNode;
//		return;
//	}
//
//	BSTNode *parent = tree->root;
//	while (true) {
//		if (parent->leftChild != NULL && newNode->datum < parent->datum) {
//			parent = parent->leftChild;
//		} else if (parent->rightChild != NULL && newNode->datum >= parent->datum) {
//			parent = parent->rightChild;
//		} else {
//			break;
//		}
//	}
//
//	newNode->parent = parent;
//	if (newNode->datum < parent->datum) {
//		parent->leftChild = newNode;
//	} else {
//		parent->rightChild = newNode;
//	}
//}
//
//void bst_preOrderTraversal(BSTData *root) {
//
//}
//
//void bst_inOrderTraversal(BSTData *root) {}
//
//void bst_postOrderTraversal(BSTData *root) {}
//
//BSTNode *bst_search(int datum, BSTData *tree) {
//	BSTNode *root = tree->root;
//
//	while (root != NULL && root->datum != datum) {
//		if (datum < root->datum) {
//			root = root->leftChild;
//		} else {
//			root = root->rightChild;
//		}
//	}
//
//	return root;
//}
//
//BSTNode *bst_maximum(BSTNode *root) {
//	while (root->rightChild) {
//		root = root->rightChild;
//	}
//
//	return root;
//}
//
//BSTNode *bst_minimum(BSTNode *root) {
//	while (root->leftChild) {
//		root = root->leftChild;
//	}
//
//	return root;
//}
//
//BSTNode *bst_InOrderPredecessor(BSTNode *node) {
//	if (node->leftChild != NULL) {
//		return bst_maximum(node->leftChild);
//	}
//
//	BSTNode *ancestor = node->parent;
//	while (ancestor->leftChild == node) {
//		node = ancestor;
//		ancestor = ancestor->parent;
//	}
//
//	return ancestor;
//}
//
//BSTNode *bst_InOrderSuccessor(BSTNode *node) {
//
//	if (node->rightChild != NULL) {
//		return bst_maximum(node->rightChild);
//	}
//
//	BSTNode *ancestor = node->parent;
//	while (ancestor->rightChild == node) {
//		node = ancestor;
//		ancestor = ancestor->parent;
//	}
//
//	return ancestor;
//}
//
//void bst_deleteNode(BSTNode *node, BSTData *tree) {
//	if (node->leftChild == NULL) {
//		bst_transplantNode(node->rightChild, node, tree);
//	} else if (node->rightChild == NULL) {
//		bst_transplantNode(node->leftChild, node, tree);
//	} else {
//		BSTNode *nodeLocalSuccessor = bst_minimum(node->rightChild);
//
//		if (nodeLocalSuccessor->parent != node) {
//			// If the local successor is the right child of node
//			// then the following lines do not have any effect on deleting on
//			// and we can skip this lines and replace node with its right child directly
//			bst_transplantNode(nodeLocalSuccessor->rightChild, nodeLocalSuccessor, tree);
//			nodeLocalSuccessor->rightChild = node->rightChild;
//			node->rightChild->parent = nodeLocalSuccessor;
//		}
//
//		bst_transplantNode(nodeLocalSuccessor, node, tree);
//		nodeLocalSuccessor->leftChild = node->leftChild;
//		node->leftChild->parent = nodeLocalSuccessor;
//	}
//
//	free(node);
//}
//
//void bst_free(BSTData *tree) {
//	BSTNode *child = tree->root;
//	BSTNode *parent = child->parent;
//
//	do {
//		if (child->leftChild != NULL) {
//			parent = child;
//			child = parent->leftChild;
//			parent->leftChild = NULL;
//			continue;
//		}
//
//		if (child->rightChild != NULL) {
//			parent = child;
//			child = parent->rightChild;
//			parent->rightChild = NULL;
//			continue;
//		}
//
//		free(child);
//		child = parent;
//		parent = child->parent;
//
//	} while (parent);
//}
//
///* ============================== UTILITY ========================= */
//
//void bst_transplantNode(BSTNode *transplanter, BSTNode *node, BSTData *tree) {
//	if (node->parent == NULL) {
//		tree->root = transplanter;
//	} else if (node == node->parent->leftChild) {
//		node->parent->leftChild = transplanter;
//	} else {
//		node->parent->rightChild = transplanter;
//	}
//
//	if (transplanter != NULL) {
//		transplanter->parent = node->parent;
//	}
//}
