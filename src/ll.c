/**
 * @file: doubleLinkedList.c
 * @author: Anonyman637
 * @date: 5/27/2021; 2:29 PM
 */

#include <internals/ll.h>

/* ============================== Runtime Registry ========================= */

void t_ll_register() {
	if (t_ll != NULL) {
		return;
	}
	
	t_ll = type_new("LinkedList");
	t_ll->print = ll_print;
	t_ll->destroyData = ll_data_destroy;
}

void t_ll_deregister() {
	if (t_ll == NULL) {
		return;
	}
	
	type_destroy(t_ll);
	t_ll = NULL;
}

/* ============================== Data Functions ========================= */

LLNode *ll_node_new(Any *datum) {
	//Declare a pointer to hold the address of a node
	LLNode *node;
	
	//Allocate the memory and assign the value to the data and addresses
	node = malloc(sizeof(LLNode));
	node->datum = datum;
	node->prev = NULL;
	node->next = NULL;
	
	//return the address of the created node
	return node;
}

void ll_node_destroy(LLNode *node) {
	any_destroy(node->datum);
	free(node);
}

LLData *ll_data_new() {
	LLData *list = malloc(sizeof(LLData));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	
	return list;
}

void ll_data_destroy(Any *this) {
	LLData *list = this->data;
	LLNode *current = list->head;
	
	while (current != NULL) {
		ll_node_destroy(current);
		current = current->next;
	}
	
	free(list);
}

/* ============================== Core Type Functions ========================= */

Any *LinkedList() {
	LLData *list = ll_data_new();
	let this = any_new(list, t_ll);
	return this;
}

void ll_print(Any *this) {
	LLData *list = this->data;
	LLNode *current = list->head;
	
	printf("[");
	if (list->size > 0) {
		any_print(current->datum);
		current = current->next;
	}
	
	while (current != NULL) {
		printf(", ");
		any_print(current->datum);
		current = current->next;
	}
	
	printf("]");
}

/* ============================== Advanced Type Functions ========================= */

int ll_size(Any *this) {
	return ll_data(this)->size;
}

int ll_isEmpty(Any *this) {
	return ll_size(this) == 0;
}

void ll_append(Any *this, Any *newDatum) {
	LLData *list = this->data;
	LLNode *newNode = ll_node_new(newDatum);
	if (list->tail == NULL) {
		list->tail = newNode;
		list->head = newNode;
		++list->size;
	} else {
		ll_insertAfter(list, list->tail, newNode);
	}
}

void ll_insert(Any *this, int index, Any *newDatum) {
	LLData *list = this->data;
	LLNode *node = ll_getNode(list, index);
	if (node == NULL) {
		return;
	}
	LLNode *newNode = ll_node_new(newDatum);
	ll_insertBefore(list, node, newNode);
}

Any *ll_get(Any *this, int index) {
	LLNode *node = ll_getNode(ll_data(this), index);
	return node != NULL ? node->datum : NULL;
}

void ll_set(Any *this, int index, Any *newDatum) {
	LLNode *node = ll_getNode(ll_data(this), index);
	if (node == NULL) {
		return;
	}
	
	node->datum = newDatum;
}

void ll_remove(Any *this, int index) {
	LLData *list = this->data;
	LLNode *node = ll_getNode(list, index);
	if (node == NULL) {
		return;
	}
	
	ll_removeNode(list, node);
}

int ll_getIndexOf(Any *this, Any *itemToSearch) {
	LLNode *current = ll_data(this)->head;
	int index = 0;
	
	while (current != NULL) {
		if (any_compare(current->datum, itemToSearch) == 0) {
			return index;
		}
		
		current = current->next;
		++index;
	}
	
	return -1;
}

/* ============================== Helper Function ========================= */

inline LLData *ll_data(Any *this) {
	return (LLData *) this->data;
}

LLNode *ll_getNode(LLData *list, int index) {
	int size = list->size;
	if (index < 0 || index >= size) {
		return NULL;
	}
	
	LLNode *node = list->head;
	for (int i = 0; i < index; i++) {
		node = node->next;
	}
	
	return node;
}

void ll_insertBefore(LLData *list, LLNode *node, LLNode *newNode) {
	newNode->prev = node->prev;
	newNode->next = node;
	
	if (node->prev == NULL) {
		list->head = newNode;
	} else {
		node->prev->next = newNode;
	}
	
	node->prev = newNode;
	++list->size;
}

void ll_insertAfter(LLData *list, LLNode *node, LLNode *newNode) {
	newNode->prev = node;
	newNode->next = node->next;
	
	if (node->next == NULL) {
		list->tail = newNode;
	} else {
		node->next->prev = newNode;
	}
	
	node->next = newNode;
	++list->size;
}

void ll_removeNode(LLData *list, LLNode *node) {
	if (list->size == 0) {
		return;
	}
	
	if (node->prev != NULL) {
		node->prev->next = node->next;
	} else {
		list->head = node->next;
	}
	
	if (node->next != NULL) {
		node->next->prev = node->prev;
	} else {
		list->tail = node->prev;
	}
	
	ll_node_destroy(node);
	--list->size;
}
