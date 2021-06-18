/**
 * @file: Task2.c
 * @author: Anonyman637
 * @date: 6/3/2021; 2:53 PM
 */

#include <doublyLinkedList.h>

typedef DLL Stack;

Stack *stack_create() {
	Stack *stack = malloc(sizeof(Stack));
	stack->firstnode = NULL;
	stack->lastnode = NULL;
	return stack;
}

void stack_push(int data, Stack *stack) {
	dll_insertAtEnd(dll_node_create(data), stack);
}

void stack_pop(Stack *stack) {
	dll_removeFromEnd(stack);
}

void stack_display(Stack *stack) {
	dll_forward(stack);
}

void stack_free(Stack *stack) {
	while (!dll_isEmpty(stack)) {
		stack_pop(stack);
	}
	free(stack);
}

int main() {
	Stack *stack = stack_create();
	stack_push(1, stack);
	stack_push(2, stack);
	stack_push(3, stack);
	stack_push(4, stack);
	stack_display(stack);
	
	stack_pop(stack);
	stack_display(stack);
	
	stack_pop(stack);
	stack_display(stack);
	
	stack_push(5, stack);
	stack_display(stack);
	
	stack_pop(stack);
	stack_display(stack);
	
	stack_pop(stack);
	stack_pop(stack);
	stack_display(stack);
	
	stack_pop(stack);
	
	stack_free(stack);
}