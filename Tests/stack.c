/**
 * @file: stack.c
 * @author: Anonyman637
 * @date: 9/8/2021; 5:21 PM
 */

#include <criterion/criterion.h>
#include <stack.h>
#include <dscommon.h>

void setup(void) {
	t_primitives_register();
	t_stack_register();
}

void teardown(void) {
	t_primitives_deregister();
	t_stack_deregister();
}

TestSuite(TypeStack, .init = setup, .fini = teardown);

Test(TypeStack, TypeName) {
	let stack = Stack();
	
	cr_assert_str_eq(any_type(stack), "Stack");
	
	any_destroy(stack);
}

Test(TypeStack, Empty) {
	let stack = Stack();
	
	cr_assert_eq(stack_isEmpty(stack), 1);
	stack_push(stack, Int(1));
	cr_assert_eq(stack_isEmpty(stack), 0);
	
	any_destroy(stack);
}

Test(TypeStack, Push) {
	let stack = Stack();
	
	stack_push(stack, Int(1));
	cr_assert_eq(stack_size(stack), 1);
	cr_assert_eq(*int_data(stack_top(stack)), 1);
	
	stack_push(stack, Int(2));
	cr_assert_eq(stack_size(stack), 2);
	cr_assert_eq(*int_data(stack_top(stack)), 2);
	
	stack_push(stack, Int(3));
	cr_assert_eq(stack_size(stack), 3);
	cr_assert_eq(*int_data(stack_top(stack)), 3);
	
	any_destroy(stack);
}


Test(TypeStack, Pop) {
	let stack = Stack();
	
	stack_push(stack, Int(1));
	stack_push(stack, Int(2));
	stack_push(stack, Int(3));
	
	stack_pop(stack);
	cr_assert_eq(stack_size(stack), 2);
	cr_assert_eq(*int_data(stack_top(stack)), 2);
	
	stack_pop(stack);
	cr_assert_eq(stack_size(stack), 1);
	cr_assert_eq(*int_data(stack_top(stack)), 1);
	
	stack_pop(stack);
	cr_assert_eq(stack_size(stack), 0);
	cr_assert_null(stack_top(stack));
	
	any_destroy(stack);
}
