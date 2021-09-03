/**
 * @file: dll_stack.c
 * @author: Anonyman637
 * @date: 6/17/2021; 12:58 AM
 */

#include <dllStack.h>

DLL_Stack *dll_stack_create() {
	return dll_create();
}

void dll_stack_push(int data, DLL_Stack *stack) {
	dll_insertAtEnd(dll_node_create(data), stack);
}

void dll_stack_pop(DLL_Stack *stack) {
	dll_removeFromEnd(stack);
}

void dll_stack_display(DLL_Stack *stack) {
	dll_forward(stack);
}

void dll_stack_free(DLL_Stack *stack) {
	dll_free(stack);
}

