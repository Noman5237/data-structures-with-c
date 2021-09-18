/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 8/26/2021; 3:06 PM
 */

#include "init.h"

int main() {
	registerTypes();
	
	let graph = constructGraph();
	any_print(graph);
	printf("\n");
	
	any_destroy(graph);
	
	deRegisterTypes();
	return 0;
}
