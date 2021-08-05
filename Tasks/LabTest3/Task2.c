/**
 * @file: Task2.c
 * @author: Anonyman637
 * @date: 8/5/2021; 3:32 PM
 */

#include "BinarySearchTree.h"

int main(int argc, char **argv) {
	if (argc != 3) {
		printf("Usage: program dataFile noOfElements\n");
	}
	
	FILE *source = fopen(argv[1], "r");
	int noOfElements = atoi(argv[2]);
	int data;
	fscanf(source, "%d", &data);
	Node *root = node_create(data);
	for (int i = 0; i < noOfElements; i++) {
		fscanf(source, "%d", &data);
		bst_insert(data, root);
	}
	
	extern int SEARCH_OPS_COUNT;
	bst_search(1234567, root);
	printf("SEARCH_OPS_COUNT is %d", SEARCH_OPS_COUNT);
}
