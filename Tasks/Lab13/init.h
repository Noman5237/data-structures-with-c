/**
 * @file: init.c
 * @author: Anonyman637
 * @date: 9/17/2021; 4:30 AM
 */

#include <dscommon.h>
#include <map.h>
#include <interfaces/list/bst.h>
#include <ll.h>
#include <queue.h>
#include <stack.h>

void registerTypes() {
	t_primitives_register();
	t_bst_register();
	t_ll_register();
	t_queue_register();
	t_stack_register();
	t_map_register();
	i_list_register();
	i_list_bst_register();
}

void deRegisterTypes() {
	t_primitives_deregister();
	i_list_bst_deregister();
	i_list_deregister();
	t_map_deregister();
	t_stack_deregister();
	t_queue_deregister();
	t_ll_deregister();
	t_bst_deregister();
}

Any *constructGraph() {
	let neighboursA = LinkedList();
	let neighboursB = LinkedList();
	let neighboursC = LinkedList();
	let neighboursD = LinkedList();
	let neighboursE = LinkedList();
	let neighboursF = LinkedList();
	
	ll_append(neighboursA, String("B"));
	
	ll_append(neighboursB, String("C"));
	
	ll_append(neighboursC, String("D"));
	
	ll_append(neighboursD, String("F"));
	ll_append(neighboursD, String("E"));
	
	ll_append(neighboursE, String("F"));
	
	ll_append(neighboursF, String("A"));
	ll_append(neighboursF, String("B"));
	
	let graph = Map(IList_BinarySearchTree());
	map_put(graph, String("A"), neighboursA);
	map_put(graph, String("B"), neighboursB);
	map_put(graph, String("C"), neighboursC);
	map_put(graph, String("D"), neighboursD);
	map_put(graph, String("E"), neighboursE);
	map_put(graph, String("F"), neighboursF);
	
	return graph;
}
