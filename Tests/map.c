/**
 * @file: map.c
 * @author: Anonyman637
 * @date: 9/16/2021; 11:12 PM
 */

#include <dscommon.h>
#include <map.h>
#include <interfaces/list/bst.h>
#include <ll.h>

void registerTypes();

void deRegisterTypes();

int main() {
	registerTypes();
	
	let m0 = LinkedList();
	ll_append(m0, Int(0));
	ll_append(m0, Int(1));
	ll_append(m0, Int(2));
	
	let m1 = LinkedList();
	ll_append(m1, Int(1));
	ll_append(m1, Int(2));
	ll_append(m1, Int(0));
	
	let m2 = LinkedList();
	ll_append(m2, Int(2));
	ll_append(m2, Int(0));
	ll_append(m2, Int(1));
	
	let map = Map(IList_BinarySearchTree());
	map_put(map, String("D"), m0);
	map_put(map, String("B"), m1);
	map_put(map, String("C"), m2);
	
	any_print(map);
	printf("\n");
	map_put(map, String("A"), Int(555));
	any_print(map);
	printf("\n");
	
	any_destroy(map);
	deRegisterTypes();
	
	return 0;
}

void registerTypes() {
	t_primitives_register();
	t_bst_register();
	t_ll_register();
	t_map_register();
	i_list_register();
	i_list_bst_register();
}

void deRegisterTypes() {
	t_primitives_deregister();
	i_list_bst_deregister();
	i_list_deregister();
	t_map_deregister();
	t_ll_deregister();
	t_bst_deregister();
}
