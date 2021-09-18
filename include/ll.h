/**
 * @file: doubleLinkedList.h
 * @author: Anonyman637
 * @date: 6/16/2021; 11:35 PM
 */

#ifndef DATASTRUCTURESCOURSE_LL_H
#define DATASTRUCTURESCOURSE_LL_H

#include <type.h>

/* ============================== Runtime Registry ========================= */

Type *t_ll;


void t_ll_register();

void t_ll_deregister();

/* ============================== Core Type Functions ========================= */

Any *LinkedList();

void ll_print(Any *this);

/* ============================== Advanced Type Functions ========================= */

int ll_size(Any *this);

int ll_isEmpty(Any *this);

void ll_append(Any *this, Any *newDatum);

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
 * @param this Pointer to the list instantiated by LinkedList()
 * @param index Existing index for the new data to insert at
 * @param newDatum Data to be inserted at desired index of the list
 */
void ll_insert(Any *this, int index, Any *newDatum);

Any *ll_get(Any *this, int index);

void ll_set(Any *this, int index, Any *newDatum);

void ll_remove(Any *this, int index);

int ll_getIndexOf(Any *this, Any *itemToSearch);

Any *ll_search(Any *this, Any *itemToSearch);

#endif //DATASTRUCTURESCOURSE_LL_H
