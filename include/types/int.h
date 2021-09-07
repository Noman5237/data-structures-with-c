/**
 * @file: int.h
 * @author: Anonyman637
 * @date: 8/26/2021; 5:41 PM
 */

#ifndef DATASTRUCTURESCOURSE_INT_H
#define DATASTRUCTURESCOURSE_INT_H

#include <type.h>

Any *Int(int data);

Any *t_int_copy(Any *this);

int t_int_compare(Any *this, Any *other);

void t_int_print(Any *this);

void t_int_destroy(Any *this);

Type *t_int;

void t_int_register();

void t_int_deregister();

#endif //DATASTRUCTURESCOURSE_INT_H
