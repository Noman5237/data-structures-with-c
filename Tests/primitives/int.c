/**
 * @file: int.c
 * @author: Anonyman637
 * @date: 8/26/2021; 8:27 PM
 */

#include <primitives/primitives.h>
#include <criterion/criterion.h>

void setup(void) {
	t_int_register();
}

void teardown(void) {
	t_int_deregister();
}

TestSuite(TypeInt, .init = setup, .fini = teardown);

/* ============================== Core Type Functions ========================= */

Test(TypeInt, TypeName) {
	let num = Int(5);
	
	cr_assert_str_eq(any_type(num), "Int");
	
	any_destroy(num);
}

Test(TypeInt, VarCreateDataFree) {
	let num = Int(5);
	
	cr_assert_eq(*int_data(num), 5);
	
	any_destroy(num);
}

Test(TypeInt, Compare) {
	let num1 = Int(4);
	let num2 = Int(5);
	let num3 = Int(5);
	let num4 = Int(7);
	
	cr_expect_eq(any_compare(num2, num3), 0);
	cr_expect_lt(any_compare(num1, num2), 0);
	cr_expect_gt(any_compare(num4, num2), 0);
	
	any_destroy(num1);
	any_destroy(num2);
	any_destroy(num3);
	any_destroy(num4);
}

Test(TypeInt, Clone) {
	let num1 = Int(4);
	let numCopy = any_clone(num1);
	
	cr_expect_eq(any_compare(num1, numCopy), 0);
	
	any_destroy(num1);
	any_destroy(numCopy);
}
