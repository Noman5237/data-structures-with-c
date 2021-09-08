/**
 * @file: doubleLinkedList.c
 * @author: Anonyman637
 * @date: 5/27/2021; 2:29 PM
 */

#include <internals/list.h>

/* ============================== Runtime Registry ========================= */

void t_list_register() {
	if (t_list != NULL) {
		return;
	}
	
	t_list = type_new("List");
	t_list->print = list_print;
	t_list->destroyData = list_data_destroy;
}

void t_list_deregister() {
	if (t_list == NULL) {
		return;
	}
	
	type_destroy(t_list);
	t_list = NULL;
}

/* ============================== Data Functions ========================= */

ListNode *list_node_new(Any *datum) {
	//Declare a pointer to hold the address of a node
	ListNode *node;
	
	//Allocate the memory and assign the value to the data and addresses
	node = malloc(sizeof(ListNode));
	node->datum = datum;
	node->prev = NULL;
	node->next = NULL;
	
	//return the address of the created node
	return node;
}

void list_node_destroy(ListNode *node) {
	any_destroy(node->datum);
	free(node);
}

ListData *list_data_new() {
	ListData *list = malloc(sizeof(ListData));
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	
	return list;
}

void list_data_destroy(Any *this) {
	ListData *list = this->data;
	ListNode *current = list->head;
	
	while (current != NULL) {
		list_node_destroy(current);
		current = current->next;
	}
	
	free(list);
}

/* ============================== Core Type Functions ========================= */

Any *List() {
	ListData *list = list_data_new();
	let this = any_new(list, t_list);
	return this;
}

void list_print(Any *this) {
	ListData *list = this->data;
	ListNode *current = list->head;
	
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

int list_size(Any *this) {
	return list_data(this)->size;
}

int list_isEmpty(Any *this) {
	return list_size(this) == 0;
}

void list_append(Any *this, Any *newDatum) {
	ListData *list = this->data;
	ListNode *newNode = list_node_new(newDatum);
	if (list->tail == NULL) {
		list->tail = newNode;
		list->head = newNode;
		++list->size;
	} else {
		list_insertAfter(list, list->tail, newNode);
	}
}

void list_insert(Any *this, int index, Any *newDatum) {
	ListData *list = this->data;
	ListNode *node = list_getNode(list, index);
	if (node == NULL) {
		return;
	}
	ListNode *newNode = list_node_new(newDatum);
	list_insertBefore(list, node, newNode);
}

Any *list_get(Any *this, int index) {
	ListNode *node = list_getNode(list_data(this), index);
	return node != NULL ? node->datum : NULL;
}

void list_set(Any *this, int index, Any *newDatum) {
	ListNode *node = list_getNode(list_data(this), index);
	if (node == NULL) {
		return;
	}
	
	node->datum = newDatum;
}

void list_remove(Any *this, int index) {
	ListData *list = this->data;
	ListNode *node = list_getNode(list, index);
	if (node == NULL) {
		return;
	}
	
	list_removeNode(list, node);
}

int list_getIndexOf(Any *this, Any *itemToSearch) {
	ListNode *current = list_data(this)->head;
	int index = 0;
	
	while (current != NULL) {
		if (!any_compare(current->datum, itemToSearch)) {
			return index;
		}
		
		current = current->next;
		++index;
	}
	
	return -1;
}

/* ============================== Helper Function ========================= */

inline ListData *list_data(Any *this) {
	return (ListData *) this->data;
}

ListNode *list_getNode(ListData *list, int index) {
	int size = list->size;
	if (index < 0 || index >= size) {
		return NULL;
	}
	
	ListNode *node = list->head;
	for (int i = 0; i < index; i++) {
		node = node->next;
	}
	
	return node;
}

void list_insertBefore(ListData *list, ListNode *node, ListNode *newNode) {
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

void list_insertAfter(ListData *list, ListNode *node, ListNode *newNode) {
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

void list_removeNode(ListData *list, ListNode *node) {
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
	
	list_node_destroy(node);
	--list->size;
}
