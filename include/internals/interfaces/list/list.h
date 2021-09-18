/**
 * @file: list.h
 * @author: Anonyman637
 * @date: 9/12/2021; 9:47 AM
 */

#ifndef DATASTRUCTURESCOURSE_INTERNAL_INTERFACE_LIST_H
#define DATASTRUCTURESCOURSE_INTERNAL_INTERFACE_LIST_H

#include <interfaces/list/list.h>

/* ============================== Data ========================= */

typedef struct IListInstance IListInstance;

typedef struct IList IList;

struct IList {
	Any *(*new)();
	
	void (*print)(Any *this);
	
	int (*size)(Any *this);
	
	int (*isEmpty)(Any *this);
	
	void (*append)(Any *this, Any *newDatum);
	
	void (*insert)(Any *this, int index, Any *newDatum);
	
	Any *(*get)(Any *this, int index);
	
	void (*set)(Any *this, int index, Any *newDatum);
	
	void (*remove)(Any *this, int index);
	
	void (*removeItem)(Any *this, Any *itemToRemove);
	
	Any *(*search)(Any *this, Any *itemToSearch);
	
	int (*getIndexOf)(Any *this, Any *itemToSearch);
	
	void (*destroy)(IListInstance *instance);
};

struct IListInstance {
	Any *list;
	IList *functions;
};

/* ============================== Core Type Functions ========================= */

/**
 * List interface gives the implementation full control over the lifecycle of
 * both the list data and the functions implementation i.e. over full list instance.
 * @param this
 */
void list_destroy(Any *this);

#endif //DATASTRUCTURESCOURSE_INTERNAL_INTERFACE_LIST_H
