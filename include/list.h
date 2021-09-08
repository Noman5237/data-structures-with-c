/**
 * @file: doubleLinkedList.h
 * @author: Anonyman637
 * @date: 6/16/2021; 11:35 PM
 */

#ifndef DATASTRUCTURESCOURSE_LIST_H
#define DATASTRUCTURESCOURSE_LIST_H

#include <type.h>

/* ============================== Runtime Registry ========================= */

Type *t_list;

void t_list_register();

void t_list_deregister();

/* ============================== Core Type Functions ========================= */

Any *List();

void list_print(Any *this);

void list_destroy(Any *this);

/* ============================== Advanced Type Functions ========================= */

int list_size(Any *this);

int list_isEmpty(Any *this);

void list_append(Any *this, Any *newDatum);

/**
 * @brief
 * Inserts new data at specified index given the index already exists in provided list
 *
 * @attention
 * insert cannot create position that doesn't exist!!!
 * <br>
 * For example you cannot insert new data at the beginning of the list
 * when the size of the list is 0. For that you must use append().
 * <br>
 * Just remember, insert cannot be used into non-existing index and
 * the newly inserted data will always hold the given index in the modified list.*
 *
 * @param this Pointer to the list instantiated by List()
 * @param index Existing index for the new data to insert at
 * @param newDatum Data to be inserted at desired index of the list
 */
void list_insert(Any *this, int index, Any *newDatum);

Any *list_get(Any *this, int index);

void list_set(Any *this, int index, Any *newDatum);

void list_remove(Any *this, int index);

int list_getIndexOf(Any *this, Any *itemToSearch);

#endif //DATASTRUCTURESCOURSE_LIST_H
