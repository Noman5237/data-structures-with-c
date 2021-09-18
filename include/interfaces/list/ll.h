/**
 * @file: ll.h
 * @author: Anonyman637
 * @date: 9/12/2021; 9:59 AM
 */
#ifndef DATASTRUCTURESCOURSE_INTERFACE_LIST_LL_H
#define DATASTRUCTURESCOURSE_INTERFACE_LIST_LL_H

#include <interfaces/list/list.h>
#include <ll.h>

/* ============================== Runtime Registry ========================= */
void i_list_ll_register();

void i_list_ll_deregister();

/* ============================== Interface Implementation ========================= */

Any *IList_LinkedList();

#endif //DATASTRUCTURESCOURSE_INTERFACE_LIST_LL_H
