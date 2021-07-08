/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 7/1/2021; 3:12 PM
 */

#include <binarySearchTree.h>

int main() {
	BST *tree = bst_create();
	
	bst_insertNode(bst_node_create(5), tree);
	bst_insertNode(bst_node_create(1), tree);
	bst_insertNode(bst_node_create(7), tree);
	bst_insertNode(bst_node_create(8), tree);
	bst_insertNode(bst_node_create(7), tree);
	bst_insertNode(bst_node_create(1), tree);
	bst_insertNode(bst_node_create(5), tree);
	bst_insertNode(bst_node_create(4), tree);
	bst_insertNode(bst_node_create(3), tree);
	bst_insertNode(bst_node_create(0), tree);
	bst_insertNode(bst_node_create(10), tree);
	
	bst_recursiveInOrderTraversal(tree->root);
	printf("\n");
	
	bst_deleteNode(tree->root, tree);
	bst_deleteNode(bst_search(4, tree), tree);
	
	bst_recursiveInOrderTraversal(tree->root);
	printf("\n");
	
	bst_recursiveFree(tree->root);
}
