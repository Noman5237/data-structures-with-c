/**
 * @file: Task2.c
 * @author: Anonyman637
 * @date: 8/19/2021; 2:34 PM
 */

#include <binarySearchTree.h>

int main() {
	
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		BST *tree = bst_create();
		int temp;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			bst_insertNode(bst_node_create(temp), tree);
		}
		for (int i = 0; i < m; i++) {
			scanf("%d", &temp);
			if (bst_search(temp, tree) == NULL) {
				bst_insertNode(bst_node_create(temp), tree);
				printf("NO");
			} else {
				printf("YES");
			}
			
			printf("\n");
		}
		
	}
}
