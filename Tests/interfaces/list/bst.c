/**
 * @file: list.c
 * @author: Anonyman637
 * @date: 9/12/2021; 12:05 AM
 */

#include <criterion/criterion.h>
#include <dscommon.h>
#include <interfaces/list/bst.h>

void setup(void) {
	t_primitives_register();
	t_bst_register();
	i_list_register();
	i_list_bst_register();
}

void teardown(void) {
	t_primitives_deregister();
	i_list_bst_deregister();
	i_list_deregister();
	t_bst_deregister();
}

TestSuite(TypeList_BST, .init = setup, .fini = teardown);

Test(TypeList_BST, TypeName) {
	let list = IList_BinarySearchTree();
	
	cr_assert_str_eq(any_type(list), "List");
	
	any_destroy(list);
}

Test(TypeList_BST, Empty) {
	let list = IList_BinarySearchTree();
	
	cr_assert_eq(list_isEmpty(list), 1);
	list_append(list, Int(1));
	cr_assert_eq(list_isEmpty(list), 0);
	
	any_destroy(list);
}

Test(TypeList_BST, Append) {
	let list = IList_BinarySearchTree();
	
	list_append(list, Int(1));
	list_append(list, Int(2));
	list_append(list, Int(3));
	
	cr_assert_eq(list_size(list), 3);
	cr_assert_eq(*int_data(list_get(list, 0)), 1);
	cr_assert_eq(*int_data(list_get(list, 1)), 2);
	cr_assert_eq(*int_data(list_get(list, 2)), 3);
	
	any_destroy(list);
}

Test(TypeList_BST, Get) {
	let list = IList_BinarySearchTree();
	
	list_append(list, Int(2));
	cr_assert_not_null(list_get(list, 0));
	cr_assert_null(list_get(list, -1));
	cr_assert_null(list_get(list, 100));
	
	any_destroy(list);
}

Test(TypeList_BST, Remove) {
	let list = IList_BinarySearchTree();
	
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

Test(TypeList_BST, GetIndexOf) {
	let list = IList_BinarySearchTree();
	
	list_append(list, Int(1));
	list_append(list, Int(2));
	list_append(list, Int(3));
	
	cr_assert_eq(list_getIndexOf(list, Int(1)), 0);
	cr_assert_eq(list_getIndexOf(list, Int(2)), 1);
	cr_assert_eq(list_getIndexOf(list, Int(3)), 2);
	cr_assert_eq(list_getIndexOf(list, Int(4)), -1);
	
	any_destroy(list);
}

Test(TypeList_BST, Print) {
	let list = IList_BinarySearchTree();
	
	list_append(list, Int(8));
	list_append(list, Int(4));
	list_append(list, Int(12));
	list_append(list, Int(2));
	list_append(list, Int(6));
	list_append(list, Int(10));
	list_append(list, Int(13));
	list_append(list, Int(1));
	list_append(list, Int(3));
	list_append(list, Int(5));
	list_append(list, Int(7));
	list_append(list, Int(9));
	list_append(list, Int(11));
	list_append(list, Int(14));
	
	any_print(list);
	
	any_destroy(list);
}
