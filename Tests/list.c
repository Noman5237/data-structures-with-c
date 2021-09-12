/**
 * @file: list.c
 * @author: Anonyman637
 * @date: 9/12/2021; 12:05 AM
 */

#include <criterion/criterion.h>
#include <dscommon.h>
#include <interfaces/list/ll.h>

void setup(void) {
	t_primitives_register();
	t_ll_register();
	i_list_register();
	i_list_ll_register();
}

void teardown(void) {
	t_primitives_deregister();
	i_list_ll_deregister();
	i_list_deregister();
	t_ll_deregister();
}

TestSuite(TypeList_LL, .init = setup, .fini = teardown);

Test(TypeList_LL, TypeName) {
	let list = IList_LinkedList();
	
	cr_assert_str_eq(any_type(list), "List");
	
	any_destroy(list);
}

Test(TypeList_LL, Empty) {
	let list = IList_LinkedList();
	
	cr_assert_eq(list_isEmpty(list), 1);
	list_append(list, Int(1));
	cr_assert_eq(list_isEmpty(list), 0);
	
	any_destroy(list);
}

Test(TypeList_LL, Append) {
	let list = IList_LinkedList();
	
	list_append(list, Int(1));
	list_append(list, Int(2));
	list_append(list, Int(3));
	
	cr_assert_eq(list_size(list), 3);
	cr_assert_eq(*int_data(list_get(list, 0)), 1);
	cr_assert_eq(*int_data(list_get(list, 1)), 2);
	cr_assert_eq(*int_data(list_get(list, 2)), 3);
	
	any_destroy(list);
}

Test(TypeList_LL, Insert) {
	let list = IList_LinkedList();
	
	list_insert(list, 0, Int(1));
	cr_assert_eq(list_size(list), 0);
	
	list_append(list, Int(1));
	list_insert(list, 0, Int(2));
	cr_assert_eq(list_size(list), 2);
	cr_assert_eq(*int_data(list_get(list, 0)), 2);
	
	list_insert(list, list_size(list), Int(3));
	cr_assert_eq(list_size(list), 2);
	
	list_insert(list, list_size(list) - 1, Int(3));
	cr_assert_eq(list_size(list), 3);
	cr_assert_eq(*int_data(list_get(list, 1)), 3);
	
	any_destroy(list);
}

Test(TypeList_LL, Get) {
	let list = IList_LinkedList();
	
	list_append(list, Int(2));
	cr_assert_not_null(list_get(list, 0));
	cr_assert_null(list_get(list, -1));
	cr_assert_null(list_get(list, 100));
	
	any_destroy(list);
}

Test(TypeList_LL, Set) {
	let list = IList_LinkedList();
	
	list_set(list, 0, Int(1));
	cr_assert_eq(list_size(list), 0);
	
	list_append(list, Int(1));
	list_set(list, 0, Int(2));
	cr_assert_eq(list_size(list), 1);
	cr_assert_eq(*int_data(list_get(list, 0)), 2);
	
	any_destroy(list);
}

Test(TypeList_LL, Remove) {
	let list = IList_LinkedList();
	
	list_append(list, Int(1));
	list_append(list, Int(2));
	list_remove(list, 0);
	cr_assert_eq(list_size(list), 1);
	
	list_append(list, Int(1));
	list_remove(list, -1);
	list_remove(list, 100);
	cr_assert_eq(list_size(list), 2);
	
	list_remove(list, list_size(list) - 1);
	cr_assert_eq(list_size(list), 1);
	
	any_destroy(list);
}

Test(TypeList_LL, GetIndexOf) {
	let list = IList_LinkedList();
	
	list_append(list, Int(1));
	list_append(list, Int(2));
	list_append(list, Int(3));
	
	cr_assert_eq(list_getIndexOf(list, Int(1)), 0);
	cr_assert_eq(list_getIndexOf(list, Int(2)), 1);
	cr_assert_eq(list_getIndexOf(list, Int(3)), 2);
	cr_assert_eq(list_getIndexOf(list, Int(4)), -1);
	
	any_destroy(list);
}

Test(TypeList_LL, Print) {
	let list = IList_LinkedList();
	
	let item0 = IList_LinkedList();
	list_append(item0, Int(0));
	list_append(item0, Int(1));
	list_append(item0, Int(2));
	
	let item1 = LinkedList();
	ll_append(item1, Int(4));
	ll_append(item1, Int(5));
	ll_append(item1, Int(6));
	
	list_append(list, item0);
	list_append(list, Int(10));
	list_append(list, item1);
	
	any_print(list);
	
	any_destroy(list);
}
