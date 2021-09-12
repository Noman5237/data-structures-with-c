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
	
	bst_append(list, Int(1));
	bst_append(list, Int(2));
	bst_append(list, Int(3));
	
	any_destroy(list);
}

Test(TypeBST, Print) {
	let list = BinarySearchTree();
	
	bst_append(list, Int(3));
	bst_append(list, Int(1));
	bst_append(list, Int(2));
	
	any_print(list);
	
	any_destroy(list);
}
