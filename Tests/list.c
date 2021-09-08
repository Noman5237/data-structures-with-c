/**
 * @file: list.c
 * @author: Anonyman637
 * @date: 9/8/2021; 2:07 AM
 */

#include <list.h>
#include <dscommon.h>
#include <criterion/criterion.h>

void setup(void) {
	t_primitives_register();
	t_list_register();
}

void teardown(void) {
	t_primitives_deregister();
	t_list_deregister();
}

TestSuite(TypeList, .init = setup, .fini = teardown);

Test(TypeList, TypeName) {
	let list = List();
	
	cr_assert_str_eq(any_type(list), "List");
	
	any_destroy(list);
}

Test(TypeList, Empty) {
	let list = List();
	
	cr_assert_eq(list_isEmpty(list), 1);
	list_append(list, Int(1));
	cr_assert_eq(list_isEmpty(list), 0);
	
	any_destroy(list);
}

Test(TypeList, Append) {
	let list = List();
	
	list_append(list, Int(1));
	list_append(list, Int(2));
	list_append(list, Int(3));
	
	cr_assert_eq(list_size(list), 3);
	cr_assert_eq(*int_data(list_get(list, 0)), 1);
	cr_assert_eq(*int_data(list_get(list, 1)), 2);
	cr_assert_eq(*int_data(list_get(list, 2)), 3);
	
	any_destroy(list);
}

Test(TypeList, Insert) {
	let list = List();
	
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

Test(TypeList, Get) {
	let list = List();
	
	list_append(list, Int(2));
	cr_assert_not_null(list_get(list, 0));
	cr_assert_null(list_get(list, -1));
	cr_assert_null(list_get(list, 100));
	
	any_destroy(list);
}

Test(TypeList, Set) {
	let list = List();
	
	list_set(list, 0, Int(1));
	cr_assert_eq(list_size(list), 0);
	
	list_append(list, Int(1));
	list_set(list, 0, Int(2));
	cr_assert_eq(list_size(list), 1);
	cr_assert_eq(*int_data(list_get(list, 0)), 2);
	
	any_destroy(list);
}

Test(TypeList, Remove) {
	let list = List();
	
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

Test(TypeList, GetIndexOf) {
	let list = List();
	
	list_append(list, Int(1));
	list_append(list, Int(2));
	list_append(list, Int(3));
	
	cr_assert_eq(list_getIndexOf(list, Int(1)), 0);
	cr_assert_eq(list_getIndexOf(list, Int(2)), 1);
	cr_assert_eq(list_getIndexOf(list, Int(3)), 2);
	cr_assert_eq(list_getIndexOf(list, Int(4)), -1);
	
	any_destroy(list);
}

Test(TypeList, Print) {
	let list = List();
	
	let item0 = List();
	list_append(item0, Int(0));
	list_append(item0, Int(1));
	list_append(item0, Int(2));
	
	let item1 = List();
	list_append(item1, Int(4));
	list_append(item1, Int(5));
	list_append(item1, Int(6));
	
	list_append(list, item0);
	list_append(list, Int(10));
	list_append(list, item1);
	
	any_print(list);
	
	any_destroy(list);
}
