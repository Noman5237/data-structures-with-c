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
	
	printf("Inorder traversal\n");
	bst_recursiveInOrderTraversal(tree->root);
	printf("\n");
	
	printf("Preorder traversal\n");
	bst_recursivePreOrderTraversal(tree->root);
	printf("\n");
	
	printf("Postorder traversal\n");
	bst_recursivePostOrderTraversal(tree->root);
	printf("\n");
	
	printf("Deleting tree root\n");
	bst_deleteNode(tree->root, tree);
	bst_recursiveInOrderTraversal(tree->root);
	printf("\n");
	
	printf("Deleting 4 from tree\n");
	bst_deleteNode(bst_search(4, tree), tree);
	bst_recursiveInOrderTraversal(tree->root);
	printf("\n");
	
	printf("Deleting max element from tree root\n");
	bst_deleteNode(bst_maximum(tree->root), tree);
	bst_recursiveInOrderTraversal(tree->root);
	printf("\n");
	
	printf("Deleting min element from tree root\n");
	bst_deleteNode(bst_minimum(tree->root), tree);
	bst_recursiveInOrderTraversal(tree->root);
	printf("\n");
	
	bst_recursiveFree(tree->root);
}
