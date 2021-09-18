/**
 * @file: string.h
 * @author: Anonyman637
 * @date: 8/26/2021; 5:41 PM
 */

#ifndef DATASTRUCTURESCOURSE_PRIMITIVE_STRING_H
#define DATASTRUCTURESCOURSE_PRIMITIVE_STRING_H

#include <type.h>

/* ============================== Runtime Registry ========================= */

Type *t_string;

void t_string_register();

void t_string_deregister();

/* ============================== Core Type Functions ========================= */

Any *String(char *string);

char *string_data(Any *this);

Any *string_clone(Any *this);

int string_compare(Any *this, Any *other);

void string_print(Any *this);

#endif //DATASTRUCTURESCOURSE_PRIMITIVE_STRING_H
