/**
 * @file: Task2.c
 * @author: Anonyman637
 * @date: 6/3/2021; 2:53 PM
 */

#include <dscommon.h>
#include <stack.h>

int main() {
	t_primitives_register();
	t_stack_register();
	
	let stack = Stack();
	stack_push(stack, Int(1));
	stack_push(stack, Int(2));
	stack_push(stack, Int(3));
	stack_push(stack, Int(4));
	any_print(stack);
	
	stack_pop(stack);
	any_print(stack);
	
	stack_pop(stack);
	any_print(stack);
	
	stack_push(stack, Int(5));
	any_print(stack);
	
	stack_pop(stack);
	any_print(stack);
	
	stack_pop(stack);
	stack_pop(stack);
	any_print(stack);
	
	stack_pop(stack);
	
	any_destroy(stack);
	
	t_primitives_deregister();
	t_stack_deregister();
	
	return 0;
}
