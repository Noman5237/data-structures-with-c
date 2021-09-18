/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 8/26/2021; 3:06 PM
 */

#include "init.h"

void printShortestPath(Any *start, Any *end, Any *prevNodes) {
	if (any_compare(start, end) == 0) {
		any_print(start);
		return;
	}
	printShortestPath(start, map_get(prevNodes, end), prevNodes);
	printf(" -> ");
	any_print(end);
}

void dijkstra(Any *graph, Any *start, Any *distances, Any *prevNodes) {
	let nodes = map_getKeys(graph);
	let q = Queue();
	let startNeighbours = map_get(graph, start);
	for (int i = 0; i < list_size(nodes); i++) {
		let node = list_get(nodes, i);
		if (ll_search(startNeighbours, node) != NULL) {
			map_put(distances, any_clone(node), Int(1));
		} else {
			map_put(distances, any_clone(node), Int(INT_MAX));
		}
		if (any_compare(node, start) != 0) {
			queue_enqueue(q, any_clone(node));
		}
		map_put(prevNodes, any_clone(node), any_clone(start));
	}
	
	map_put(distances, any_clone(start), Int(0));
	
	while (queue_size(q) != 0) {
		let node = queue_front(q);
		
		let neighbours = map_get(graph, node);
		for (int i = 0; i < ll_size(neighbours); i++) {
			let neighbour = ll_get(neighbours, i);
			let tempDistance = any_add(map_get(distances, node), Int(1));
			if (any_compare(tempDistance, map_get(distances, neighbour)) < 0) {
				map_put(distances, any_clone(neighbour), tempDistance);
				map_put(prevNodes, any_clone(neighbour), any_clone(node));
			} else {
				any_destroy(tempDistance);
			}
		}
		
		queue_dequeue(q);
	}
	
	any_destroy(q);
}

int main() {
	registerTypes();
	
	let graph = constructGraph();
	printf("Graph:\n");
	any_print(graph);
	printf("\n");
	
	let distances = Map(IList_BinarySearchTree());
	let prevNodes = Map(IList_BinarySearchTree());
	let start = String("B");
	
	dijkstra(graph, start, distances, prevNodes);
	
	printf("Shortest Distances:\n");
	any_print(distances);
	printf("\n");
	
	printf("Shortest Paths:\n");
	let nodes = map_getKeys(graph);
	for (int i = 0; i < map_size(prevNodes); i++) {
		let node = list_get(nodes, i);
		any_print(node);
		printf(": ");
		printShortestPath(start, node, prevNodes);
		printf("\n");
	}
	
	any_destroy(distances);
	any_destroy(prevNodes);
	any_destroy(graph);
	
	deRegisterTypes();
	return 0;
}

