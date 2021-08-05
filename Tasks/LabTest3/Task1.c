/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 8/5/2021; 3:26 PM
 */

#include "BinarySearchTree.h"

int main() {
	int i;
	int size = 10;
	int insertTestData[10] = {11, 5, 51, 21, 35, 50, 75, 25, 19, 37};
	
	/* ============================== Insert ========================= */
	Node *root = node_create(insertTestData[0]);
	
	for (i = 1; i < size; i++) {
		bst_insert(insertTestData[i], root);
	}
	
	printf("Inserted Elements: \n");
	bst_print(root);
	printf("\n");
	
	/* ============================== Search ========================= */
	int toBeFoundInSearchTestData[5] = {5, 11, 51, 21, 35};
	int notToBeFoundInSearchTestData[5] = {6, 12, 55, 23, 45};
	
	printf("Test: Search (to be found)\n");
	for (i = 0; i < size / 2; i++) {
		Node *node = bst_search(toBeFoundInSearchTestData[i], root);
		if (node == NULL || node->data != toBeFoundInSearchTestData[i]) {
			printf("Test Failed!\n");
			break;
		}
	}
	if (i == 5) {
		printf("Test Passed\n");
	}
	
	printf("Test: Search (not to be found)\n");
	for (int i = 0; i < size / 2; i++) {
		Node *node = bst_search(notToBeFoundInSearchTestData[i], root);
		if (node != NULL) {
			printf("Test Failed!\n");
			break;
		}
	}
	if (i == 5) {
		printf("Test Passed\n");
	}
	
	/* ============================== Remove ========================= */
	int toBeDeleted[5] = {51, 11, 5, 21, 35};
	printf("Test: Remove\n");
	for (i = 0; i < size / 2; i++) {
		Node *node = bst_search(toBeDeleted[i], root);
		if (node == NULL || node->data != toBeDeleted[i]) {
			printf("Test Failed!\n");
			break;
		}
		root = bst_remove(toBeDeleted[i], root);
		node = bst_search(toBeDeleted[i], root);
		if (node != NULL) {
			printf("Test Failed!\n");
			break;
		}
		printf("%d removed.\n", toBeDeleted[i]);
	}
	if (i == 5) {
		printf("Test Passed\n");
	}
	
	printf("Elements are removing:\n");
	bst_print(root);
	printf("\n");
	
	bst_free(root);
}
