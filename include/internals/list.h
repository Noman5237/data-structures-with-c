/**
 * @file: list.h
 * @author: Anonyman637
 * @date: 9/8/2021; 1:29 PM
 */

#ifndef DATASTRUCTURESCOURSE_INTERNAL_LIST_H
#define DATASTRUCTURESCOURSE_INTERNAL_LIST_H

#include <dscommon.h>
#include <list.h>

/* ============================== List Node ========================= */

struct ListNode {
	Any *datum;
	
	struct ListNode *prev;
	struct ListNode *next;
};

typedef struct ListNode ListNode;

ListNode *list_node_new(Any *datum);

void list_node_destroy(ListNode *node);

/* ============================== Struct Data ========================= */

struct ListData {
	ListNode *head;
	ListNode *tail;
	int size;
};

typedef struct ListData ListData;

ListData *list_data(Any *this);

ListData *list_data_new();

void list_data_destroy(Any *list);

/* ============================== Helper Functions ========================= */

ListNode *list_getNode(ListData *list, int index);

void list_insertBefore(ListData *list, ListNode *node, ListNode *newNode);

void list_insertAfter(ListData *list, ListNode *node, ListNode *newNode);

void list_removeNode(ListData *list, ListNode *node);

#endif // DATASTRUCTURESCOURSE_INTERNAL_LIST_H
