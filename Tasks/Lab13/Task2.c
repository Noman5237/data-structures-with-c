/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 8/26/2021; 3:06 PM
 */

#include "init.h"

void bfs(Any *graph, Any *start) {
	let visited = BinarySearchTree();
	let q = Queue();
	
	printf("BFS Traversal: ");
	
	queue_enqueue(q, any_clone(start));
	bst_append(visited, any_clone(start));
	
	while (queue_size(q) != 0) {
		let current = any_clone(queue_front(q));
		queue_dequeue(q);
		
		let neighbours = map_get(graph, current);
		for (int i = 0; i < ll_size(neighbours); i++) {
			let v = ll_get(neighbours, i);
			if (bst_search(visited, v) == NULL) {
				queue_enqueue(q, any_clone(v));
				bst_append(visited, any_clone(v));
			}
		}
		
		any_print(current);
		printf(", ");
		any_destroy(current);
	}
	
	any_destroy(q);
	any_destroy(visited);
	printf("\n");
}

void dfs(Any *graph, Any *start) {
	let visited = BinarySearchTree();
	let s = Stack();
	
	printf("DFS Traversal: ");
	
	stack_push(s, any_clone(start));
	bst_append(visited, any_clone(start));
	
	while (stack_size(s) != 0) {
		let current = any_clone(stack_top(s));
		stack_pop(s);
		
		let neighbours = map_get(graph, current);
		for (int i = 0; i < ll_size(neighbours); i++) {
			let v = ll_get(neighbours, i);
			if (bst_search(visited, v) == NULL) {
				stack_push(s, any_clone(v));
				bst_append(visited, any_clone(v));
			}
		}
		any_print(current);
		printf(", ");
		any_destroy(current);
	}
	
	any_destroy(s);
	any_destroy(visited);
	printf("\n");
	
}

int main() {
	registerTypes();
	
	let graph = constructGraph();
	any_print(graph);
	printf("\n");
	
	bfs(graph, String("D"));
	dfs(graph, String("D"));
	
	any_destroy(graph);
	
	deRegisterTypes();
	return 0;
}
