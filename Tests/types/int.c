/**
 * @file: int.c
 * @author: Anonyman637
 * @date: 8/26/2021; 8:27 PM
 */

#include <criterion/criterion.h>
#include <types/primitives.h>

void setup(void) {
	t_int_register();
}

void teardown(void) {
	t_int_deregister();
}

TestSuite(TypeInt, .init = setup, .fini = teardown);

Test(TypeInt, TypeName) {
	let num = Int(5);
	cr_assert_str_eq(type(num), "Int");
	destroy(num);
}

Test(TypeInt, VarCreateDataFree) {
	let num = Int(5);
	cr_assert_eq(*(int *) num->data, 5);
	destroy(num);
}

Test(TypeInt, Compare) {
	let num1 = Int(4);
	let num2 = Int(5);
	let num3 = Int(5);
	let num4 = Int(7);
	
	cr_expect_eq(compare(num2, num3), 0);
	cr_expect_lt(compare(num1, num2), 0);
	cr_expect_gt(compare(num4, num2), 0);
	
	destroy(num1);
	destroy(num2);
	destroy(num3);
	destroy(num4);
}

Test(TypeInt, Copy) {
	let num1 = Int(4);
	let numCopy = copy(num1);
	
	cr_expect_eq(compare(num1, numCopy), 0);
	
	destroy(num1);
	destroy(numCopy);
}
