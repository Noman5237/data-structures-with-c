/**
 * @file: list.c
 * @author: Anonyman637
 * @date: 9/11/2021{} 7:48 PM
 */

#include <internals/interfaces/list/list.h>
#include <stdlib.h>

/* ============================== Runtime Registry ========================= */

void i_list_register() {
	if (i_list != NULL) {
		return;
	}
	
	i_list = type_new("List");
	i_list->print = list_print;
	i_list->destroyData = list_destroy;
}

void i_list_deregister() {
	if (i_list == NULL) {
		return;
	}
	
	type_destroy(i_list);
	i_list = NULL;
}

/* ============================== Core Type Functions ========================= */

Any *List() {
	IListInstance *instance = malloc(sizeof(IListInstance));
	let this = any_new(instance, i_list);
	return this;
}

void list_destroy(Any *this) {
	IListInstance *instance = this->data;
	instance->functions->destroy(instance);
}

/* ============================== Advanced Type Functions ========================= */

void list_print(Any *this) {
	IListInstance *instance = this->data;
	instance->functions->print(instance->list);
}

int list_size(Any *this) {
	IListInstance *instance = this->data;
	return instance->functions->size(instance->list);
}

int list_isEmpty(Any *this) {
	IListInstance *instance = this->data;
	return instance->functions->isEmpty(instance->list);
}

void list_append(Any *this, Any *newDatum) {
	IListInstance *instance = this->data;
	instance->functions->append(instance->list, newDatum);
}

void list_insert(Any *this, int index, Any *newDatum) {
	IListInstance *instance = this->data;
	instance->functions->insert(instance->list, index, newDatum);
}

Any *list_get(Any *this, int index) {
	IListInstance *instance = this->data;
	return instance->functions->get(instance->list, index);
}

void list_set(Any *this, int index, Any *newDatum) {
	IListInstance *instance = this->data;
	instance->functions->set(instance->list, index, newDatum);
}

void list_remove(Any *this, int index) {
	IListInstance *instance = this->data;
	instance->functions->remove(instance->list, index);
}

int list_getIndexOf(Any *this, Any *itemToSearch) {
	IListInstance *instance = this->data;
	return instance->functions->getIndexOf(instance->list, itemToSearch);
}
