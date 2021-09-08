/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 6/3/2021; 2:53 PM
 */

#include <dscommon.h>
#include <list.h>

int main() {
	
	t_primitives_register();
	t_list_register();
	
	let list = List();
	
	list_append(list, Int(1));
	list_insert(list, 0, Int(2));
	list_insert(list, list_size(list) - 1, Int(3));
	list_append(list, Int(4));
	list_insert(list, 1, Int(5));
	list_append(list, Int(6));
	
	any_print(list);
	
	list_remove(list, 2);
	any_print(list);
	
	list_remove(list, 4);
	any_print(list);
	
	list_remove(list, 0);
	any_print(list);
	
	list_remove(list, 2);
	any_print(list);
	
	list_remove(list, list_size(list) - 1);
	any_print(list);
	
	list_remove(list, 0);
	any_print(list);
	
	any_destroy(list);
	
	printf("done");
	
	t_primitives_deregister();
	t_list_deregister();
	
	return 0;
}
