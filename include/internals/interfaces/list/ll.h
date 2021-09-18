/**
 * @file: ll.h
 * @author: Anonyman637
 * @date: 9/12/2021; 10:29 AM
 */

#ifndef DATASTRUCTURESCOURSE_INTERNAL_INTERFACE_LIST_LL_H
#define DATASTRUCTURESCOURSE_INTERNAL_INTERFACE_LIST_LL_H

#include <interfaces/list/ll.h>
#include <internals/interfaces/list/list.h>
#include <internals/ll.h>

/* ============================== Interface Implementation ========================= */

IList *i_list_ll;

void IList_LinkedListDestroy(IListInstance *instance);

void i_list_ll_functions_new();

#endif //DATASTRUCTURESCOURSE_INTERNAL_INTERFACE_LIST_LL_H
