/**
 * @file: int.h
 * @author: Anonyman637
 * @date: 8/26/2021; 5:41 PM
 */

#ifndef DATASTRUCTURESCOURSE_INT_H
#define DATASTRUCTURESCOURSE_INT_H

#include <type.h>

Type *t_int;

Any *Int(int data);

int t_int_compare(Any *arg1, Any *arg2);

void t_int_print(Any *any);

void t_int_free(Any *any);

void t_int_register();

void t_int_deregister();

#endif //DATASTRUCTURESCOURSE_INT_H
