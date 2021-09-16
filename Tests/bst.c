/**
 * @file: bst.c
 * @author: Anonyman637
 * @date: 9/9/2021; 10:00 AM
 */

#include <criterion/criterion.h>
#include <bst.h>
#include <dscommon.h>

void setup(void) {
	t_primitives_register();
	t_bst_register();
}

void teardown(void) {
	t_primitives_deregister();
	t_bst_deregister();
}

TestSuite(TypeBST, .init = setup, .fini = teardown);

Test(TypeBST, TypeName) {
	let list = BinarySearchTree();

	cr_assert_str_eq(any_type(list), "BinarySearchTree");

	any_destroy(list);
}

Test(TypeBST, Append) {
	let list = BinarySearchTree();

	cr_assert_eq(bst_size(list), 0);
	cr_assert_eq(bst_isEmpty(list), 1);

	bst_append(list, Int(1));
	bst_append(list, Int(2));
	bst_append(list, Int(3));

	cr_assert_eq(bst_size(list), 3);
	cr_assert_eq(bst_isEmpty(list), 0);

	any_destroy(list);
}

Test(TypeBST, Get) {
	let list = BinarySearchTree();

	bst_append(list, Int(3));
	bst_append(list, Int(1));
	bst_append(list, Int(2));

	cr_assert_eq(*int_data(bst_get(list, 0)), 1);
	cr_assert_eq(*int_data(bst_get(list, 1)), 2);
	cr_assert_eq(*int_data(bst_get(list, 2)), 3);

	cr_assert_null(bst_get(list, -1));
	cr_assert_null(bst_get(list, 3));
	cr_assert_null(bst_get(list, 10));

	any_destroy(list);
}

Test(TypeBST, Remove) {
	
	let list = BinarySearchTree();
	
	bst_append(list, Int(8));
	bst_append(list, Int(4));
	bst_append(list, Int(12));
	bst_append(list, Int(2));
	bst_append(list, Int(6));
	bst_append(list, Int(10));
	bst_append(list, Int(13));
	bst_append(list, Int(1));
	bst_append(list, Int(3));
	bst_append(list, Int(5));
	bst_append(list, Int(7));
	bst_append(list, Int(9));
	bst_append(list, Int(11));
	bst_append(list, Int(14));
	
	bst_remove(list, 0);
	cr_assert_null(bst_search(list, Int(1)));
	bst_remove(list, 1);
	cr_assert_null(bst_search(list, Int(3)));
	bst_remove(list, 2);
	cr_assert_null(bst_search(list, Int(5)));
	bst_remove(list, 3);
	cr_assert_null(bst_search(list, Int(7)));
	cr_assert_eq(bst_size(list), 10);
	
	any_print(list);
	
	any_destroy(list);
}

Test(TypeBST, RemoveItem) {
	
	let list = BinarySearchTree();
	
	bst_append(list, Int(8));
	bst_append(list, Int(4));
	bst_append(list, Int(12));
	bst_append(list, Int(2));
	bst_append(list, Int(6));
	bst_append(list, Int(10));
	bst_append(list, Int(13));
	bst_append(list, Int(1));
	bst_append(list, Int(3));
	bst_append(list, Int(5));
	bst_append(list, Int(7));
	bst_append(list, Int(9));
	bst_append(list, Int(11));
	bst_append(list, Int(14));
	
	bst_removeItem(list, Int(8));
	cr_assert_null(bst_search(list, Int(8)));
	bst_removeItem(list, Int(12));
	cr_assert_null(bst_search(list, Int(12)));
	bst_removeItem(list, Int(4));
	cr_assert_null(bst_search(list, Int(4)));
	bst_removeItem(list, Int(14));
	cr_assert_null(bst_search(list, Int(14)));
	cr_assert_eq(bst_size(list), 10);
	
	any_destroy(list);
}

Test(TypeBST, GetIndexOf) {
	let list = BinarySearchTree();

	bst_append(list, Int(3));
	bst_append(list, Int(1));
	bst_append(list, Int(2));

	cr_assert_eq(bst_getIndexOf(list, Int(1)), 0);
	cr_assert_eq(bst_getIndexOf(list, Int(2)), 1);
	cr_assert_eq(bst_getIndexOf(list, Int(3)), 2);

	cr_assert_eq(bst_getIndexOf(list, Int(5)), -1);
	cr_assert_eq(bst_getIndexOf(list, Int(0)), -1);

	any_destroy(list);
}

Test(TypeBST, Print) {
	let list = BinarySearchTree();

	bst_append(list, Int(3));
	bst_append(list, Int(1));
	bst_append(list, Int(2));

	any_destroy(list);
}
