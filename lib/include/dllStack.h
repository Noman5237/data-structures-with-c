/**
 * @file: dll_stack.h
 * @author: Anonyman637
 * @date: 6/17/2021; 1:02 AM
 */
 
#ifndef DATASTRUCTURESCOURSE_DLLSTACK_H
#define DATASTRUCTURESCOURSE_DLLSTACK_H

#include <doublyLinkedList.h>

typedef DLL DLL_Stack;

DLL_Stack *dll_stack_create();

void dll_stack_push(int data, DLL_Stack *stack);

void dll_stack_pop(DLL_Stack *stack);

void dll_stack_display(DLL_Stack *stack);

void dll_stack_free(DLL_Stack *stack);

#endif //DATASTRUCTURESCOURSE_DLLSTACK_H
