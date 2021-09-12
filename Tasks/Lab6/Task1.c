/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 6/3/2021; 2:53 PM
 */

#include <dscommon.h>
#include <ll.h>

int main() {
	
	t_primitives_register();
	t_ll_register();
	
	let list = LinkedList();
	
	ll_append(list, Int(1));
	ll_insert(list, 0, Int(2));
	ll_insert(list, ll_size(list) - 1, Int(3));
	ll_append(list, Int(4));
	ll_insert(list, 1, Int(5));
	ll_append(list, Int(6));
	
	any_print(list);
	
	ll_remove(list, 2);
	any_print(list);
	
	ll_remove(list, 4);
	any_print(list);
	
	ll_remove(list, 0);
	any_print(list);
	
	ll_remove(list, 2);
	any_print(list);
	
	ll_remove(list, ll_size(list) - 1);
	any_print(list);
	
	ll_remove(list, 0);
	any_print(list);
	
	any_destroy(list);
	
	printf("done");
	
	t_primitives_deregister();
	t_ll_deregister();
	
	return 0;
}
