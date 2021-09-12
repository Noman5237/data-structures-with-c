/**
 * @file: list.h
 * @author: Anonyman637
 * @date: 9/8/2021; 1:29 PM
 */

#ifndef DATASTRUCTURESCOURSE_INTERNAL_LL_H
#define DATASTRUCTURESCOURSE_INTERNAL_LL_H

#include <dscommon.h>
#include <ll.h>

/* ============================== List Node ========================= */

struct LLNode {
	let datum;
	
	struct LLNode *prev;
	struct LLNode *next;
};

typedef struct LLNode LLNode;

LLNode *ll_node_new(Any *datum);

void ll_node_destroy(LLNode *node);

/* ============================== Struct Data ========================= */

struct LLData {
	LLNode *head;
	LLNode *tail;
	int size;
};

typedef struct LLData LLData;

LLData *ll_data(Any *this);

LLData *ll_data_new();

void ll_data_destroy(Any *this);

/* ============================== Helper Functions ========================= */

LLNode *ll_getNode(LLData *list, int index);

void ll_insertBefore(LLData *list, LLNode *node, LLNode *newNode);

void ll_insertAfter(LLData *list, LLNode *node, LLNode *newNode);

void ll_removeNode(LLData *list, LLNode *node);

#endif // DATASTRUCTURESCOURSE_INTERNAL_LL_H

