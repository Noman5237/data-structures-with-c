/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 8/19/2021; 2:30 PM
 */

#include <binarySearchTree.h>

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, x;
		scanf("%d %d", &n, &x);
		BST *set = bst_create();
		int numOfDistinctElements = 0;
		int temp;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			if (bst_search(temp, set) == NULL) {
				bst_insertNode(bst_node_create(temp), set);
				++numOfDistinctElements;
			}
		}
		
		if (numOfDistinctElements < x) {
			printf("Bad");
		} else if (numOfDistinctElements == x) {
			printf("Good");
		} else {
			printf("Average");
		}
		
		printf("\n");
		
	}
}
