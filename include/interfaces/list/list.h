/**
 * @file: list.h
 * @author: Anonyman637
 * @date: 9/11/2021; 7:48 PM
 */

#ifndef DATASTRUCTURESCOURSE_INTERFACE_LIST_H
#define DATASTRUCTURESCOURSE_INTERFACE_LIST_H

#include <type.h>

/* ============================== Runtime Registry ========================= */

Type *i_list;

void i_list_register();

void i_list_deregister();

/* ============================== Core Type Functions ========================= */

Any *List();

/* ============================== Interface Helper Functions ========================= */

void list_print(Any *this);

int list_size(Any *this);

int list_isEmpty(Any *this);

void list_append(Any *this, Any *newDatum);

void list_insert(Any *this, int index, Any *newDatum);

Any *list_get(Any *this, int index);

void list_set(Any *this, int index, Any *newDatum);

void list_remove(Any *this, int index);

int list_getIndexOf(Any *this, Any *itemToSearch);

#endif //DATASTRUCTURESCOURSE_INTERFACE_LIST_H
