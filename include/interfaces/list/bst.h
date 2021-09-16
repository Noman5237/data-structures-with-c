/**
 * @file: ll.h
 * @author: Anonyman637
 * @date: 9/12/2021; 9:59 AM
 */
#ifndef DATASTRUCTURESCOURSE_INTERFACE_LIST_BST_H
#define DATASTRUCTURESCOURSE_INTERFACE_LIST_BST_H

#include <interfaces/list/list.h>
#include <bst.h>

/* ============================== Runtime Registry ========================= */
void i_list_bst_register();

void i_list_bst_deregister();

/* ============================== Interface Implementation ========================= */

Any *IList_BinarySearchTree();

#endif //DATASTRUCTURESCOURSE_INTERFACE_LIST_BST_H
