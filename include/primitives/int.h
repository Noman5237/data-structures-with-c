/**
 * @file: int.h
 * @author: Anonyman637
 * @date: 8/26/2021; 5:41 PM
 */

#ifndef DATASTRUCTURESCOURSE_INT_H
#define DATASTRUCTURESCOURSE_INT_H

#include <dsCommon.h>

/* ============================== Runtime Registry ========================= */

Type *t_int;

void t_int_register();

void t_int_deregister();

/* ============================== Core Type Functions ========================= */

Any *Int(int integer);

int *int_data(Any *this);

Any *int_clone(Any *this);

int int_compare(Any *this, Any *other);

void int_print(Any *this);

void int_destroy(Any *this);

#endif //DATASTRUCTURESCOURSE_INT_H
