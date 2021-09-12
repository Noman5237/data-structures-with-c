/**
 * @file: list.c
 * @author: Anonyman637
 * @date: 9/8/2021; 2:07 AM
 */

#include <criterion/criterion.h>
#include <ll.h>
#include <dscommon.h>

void setup(void) {
	t_primitives_register();
	t_ll_register();
}

void teardown(void) {
	t_primitives_deregister();
	t_ll_deregister();
}

TestSuite(TypeLL, .init = setup, .fini = teardown);

Test(TypeLL, TypeName) {
	let list = LinkedList();
	
	cr_assert_str_eq(any_type(list), "LinkedList");
	
	any_destroy(list);
}

Test(TypeLL, Empty) {
	let list = LinkedList();
	
	cr_assert_eq(ll_isEmpty(list), 1);
	ll_append(list, Int(1));
	cr_assert_eq(ll_isEmpty(list), 0);
	
	any_destroy(list);
}

Test(TypeLL, Append) {
	let list = LinkedList();
	
	ll_append(list, Int(1));
	ll_append(list, Int(2));
	ll_append(list, Int(3));
	
	cr_assert_eq(ll_size(list), 3);
	cr_assert_eq(*int_data(ll_get(list, 0)), 1);
	cr_assert_eq(*int_data(ll_get(list, 1)), 2);
	cr_assert_eq(*int_data(ll_get(list, 2)), 3);
	
	any_destroy(list);
}

Test(TypeLL, Insert) {
	let list = LinkedList();
	
	ll_insert(list, 0, Int(1));
	cr_assert_eq(ll_size(list), 0);
	
	ll_append(list, Int(1));
	ll_insert(list, 0, Int(2));
	cr_assert_eq(ll_size(list), 2);
	cr_assert_eq(*int_data(ll_get(list, 0)), 2);
	
	ll_insert(list, ll_size(list), Int(3));
	cr_assert_eq(ll_size(list), 2);
	
	ll_insert(list, ll_size(list) - 1, Int(3));
	cr_assert_eq(ll_size(list), 3);
	cr_assert_eq(*int_data(ll_get(list, 1)), 3);
	
	any_destroy(list);
}

Test(TypeLL, Get) {
	let list = LinkedList();
	
	ll_append(list, Int(2));
	cr_assert_not_null(ll_get(list, 0));
	cr_assert_null(ll_get(list, -1));
	cr_assert_null(ll_get(list, 100));
	
	any_destroy(list);
}

Test(TypeLL, Set) {
	let list = LinkedList();
	
	ll_set(list, 0, Int(1));
	cr_assert_eq(ll_size(list), 0);
	
	ll_append(list, Int(1));
	ll_set(list, 0, Int(2));
	cr_assert_eq(ll_size(list), 1);
	cr_assert_eq(*int_data(ll_get(list, 0)), 2);
	
	any_destroy(list);
}

Test(TypeLL, Remove) {
	let list = LinkedList();
	
	ll_append(list, Int(1));
	ll_append(list, Int(2));
	ll_remove(list, 0);
	cr_assert_eq(ll_size(list), 1);
	
	ll_append(list, Int(1));
	ll_remove(list, -1);
	ll_remove(list, 100);
	cr_assert_eq(ll_size(list), 2);
	
	ll_remove(list, ll_size(list) - 1);
	cr_assert_eq(ll_size(list), 1);
	
	any_destroy(list);
}

Test(TypeLL, GetIndexOf) {
	let list = LinkedList();
	
	ll_append(list, Int(1));
	ll_append(list, Int(2));
	ll_append(list, Int(3));
	
	cr_assert_eq(ll_getIndexOf(list, Int(1)), 0);
	cr_assert_eq(ll_getIndexOf(list, Int(2)), 1);
	cr_assert_eq(ll_getIndexOf(list, Int(3)), 2);
	cr_assert_eq(ll_getIndexOf(list, Int(4)), -1);
	
	any_destroy(list);
}

Test(TypeLL, Print) {
	let list = LinkedList();
	
	let item0 = LinkedList();
	ll_append(item0, Int(0));
	ll_append(item0, Int(1));
	ll_append(item0, Int(2));
	
	let item1 = LinkedList();
	ll_append(item1, Int(4));
	ll_append(item1, Int(5));
	ll_append(item1, Int(6));
	
	ll_append(list, item0);
	ll_append(list, Int(10));
	ll_append(list, item1);
	
	any_print(list);
	
	any_destroy(list);
}
