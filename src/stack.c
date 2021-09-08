/**
 * @file: dll_stack.c
 * @author: Anonyman637
 * @date: 6/17/2021 12:58 AM
 */

#include <stack.h>
#include <dscommon.h>
#include <internals/list.h>

/* ============================== Runtime Registry ========================= */

Type *t_stack;

void t_stack_register() {
	if (t_stack != NULL) {
		return;
	}
	
	t_list_register();
	t_stack = type_new("Stack");
	t_stack->print = list_print;
	t_stack->destroyData = list_data_destroy;
}

void t_stack_deregister() {
	if (t_stack == NULL) {
		return;
	}
	
	type_destroy(t_stack);
	t_stack = NULL;
}

/* ============================== Core Type Functions ========================= */

Any *Stack() {
	ListData *stack = list_data_new();
	let this = any_new(stack, t_stack);
	return this;
}

/* ============================== Advanced Type Functions ========================= */

int (*stack_size)(Any *this) = list_size;

int (*stack_isEmpty)(Any *this) = list_isEmpty;

Any *stack_top(Any *this) {
	return list_get(this, 0);
}

void stack_push(Any *this, Any *newDatum) {
	if (stack_isEmpty(this)) {
		list_append(this, newDatum);
	} else {
		list_insert(this, 0, newDatum);
	}
}

void stack_pop(Any *this) {
	list_remove(this, 0);
}
