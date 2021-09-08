/**
 * @file: dll_stack.h
 * @author: Anonyman637
 * @date: 6/17/2021; 1:02 AM
 */

#ifndef DATASTRUCTURESCOURSE_STACK_H
#define DATASTRUCTURESCOURSE_STACK_H

#include <type.h>

/* ============================== Runtime Registry ========================= */

Type *t_stack;

void t_stack_register();

void t_stack_deregister();

/* ============================== Core Type Functions ========================= */

Any *Stack();

/* ============================== Advanced Type Functions ========================= */

int (*stack_size)(Any *this);

int (*stack_isEmpty)(Any *this);

Any *stack_top(Any *this);

void stack_push(Any *this, Any *newDatum);

void stack_pop(Any *this);

#endif //DATASTRUCTURESCOURSE_STACK_H
