/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 7/1/2021; 3:12 PM
 */

#include <binarySearchTree.h>

int main() {
	BST *tree = bst_create();
	
	tree->root = bst_recursiveInsertNode(bst_node_create(5), tree->root);
	tree->root = bst_recursiveInsertNode(bst_node_create(1), tree->root);
	tree->root = bst_recursiveInsertNode(bst_node_create(7), tree->root);
	tree->root = bst_recursiveInsertNode(bst_node_create(8), tree->root);
	tree->root = bst_recursiveInsertNode(bst_node_create(7), tree->root);
	tree->root = bst_recursiveInsertNode(bst_node_create(1), tree->root);
	tree->root = bst_recursiveInsertNode(bst_node_create(5), tree->root);
	tree->root = bst_recursiveInsertNode(bst_node_create(4), tree->root);
	tree->root = bst_recursiveInsertNode(bst_node_create(3), tree->root);
	tree->root = bst_recursiveInsertNode(bst_node_create(0), tree->root);
	tree->root = bst_recursiveInsertNode(bst_node_create(10), tree->root);
	
	bst_recursiveInOrderTraversal(tree->root);
	printf("\n");
	
	bst_deleteNode(tree->root, tree);
	bst_deleteNode(bst_search(4, tree), tree);
	
	bst_recursiveInOrderTraversal(tree->root);
	printf("\n");
	
	bst_recursiveFree(tree->root);
}
