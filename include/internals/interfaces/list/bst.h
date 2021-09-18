/**
 * @file: ll.h
 * @author: Anonyman637
 * @date: 9/12/2021; 10:29 AM
 */

#ifndef DATASTRUCTURESCOURSE_INTERNAL_INTERFACE_LIST_BST_H
#define DATASTRUCTURESCOURSE_INTERNAL_INTERFACE_LIST_BST_H

#include <interfaces/list/bst.h>
#include <internals/interfaces/list/list.h>
#include <internals/bst.h>

/* ============================== Interface Implementation ========================= */

IList *i_list_bst;

void IList_BSTDestroy(IListInstance *instance);

void i_list_bst_functions_new();

#endif //DATASTRUCTURESCOURSE_INTERNAL_INTERFACE_LIST_BST_H
