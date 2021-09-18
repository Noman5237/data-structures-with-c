/**
 * @file: dll_stack.c
 * @author: Anonyman637
 * @date: 6/17/2021 12:58 AM
 */

#include <stack.h>
#include <dscommon.h>
#include <internals/ll.h>

/* ============================== Runtime Registry ========================= */

void t_stack_register() {
	if (t_stack != NULL) {
		return;
	}
	
	t_ll_register();
	t_stack = type_new("Stack");
	t_stack->print = ll_print;
	t_stack->destroyData = ll_data_destroy;
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
	LLData *stack = ll_data_new();
	let this = any_new(stack, t_stack);
	return this;
}

/* ============================== Advanced Type Functions ========================= */

int (*stack_size)(Any *this) = ll_size;

int (*stack_isEmpty)(Any *this) = ll_isEmpty;

Any *stack_top(Any *this) {
	return ll_get(this, 0);
}

void stack_push(Any *this, Any *newDatum) {
	if (stack_isEmpty(this)) {
		ll_append(this, newDatum);
	} else {
		ll_insert(this, 0, newDatum);
	}
}

void stack_pop(Any *this) {
	ll_remove(this, 0);
}
