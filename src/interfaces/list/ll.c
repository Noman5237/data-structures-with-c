/**
 * @file: ll.c
 * @author: Anonyman637
 * @date: 9/12/2021; 10:25 AM
 */

#include <internals/interfaces/list/ll.h>

/* ============================== Runtime Registry ========================= */

void i_list_ll_register() {
	if (i_list_ll != NULL) {
		return;
	}
	i_list_ll_functions_new();
}

void i_list_ll_deregister() {
	if (i_list_ll == NULL) {
		return;
	}
	free(i_list_ll);
	i_list_ll = NULL;
}

/* ============================== Interface Implementation ========================= */

Any *IList_LinkedList() {
	let this = List();
	IListInstance *instance = this->data;
	instance->list = LinkedList();
	instance->functions = i_list_ll;
	return this;
}

void IList_LinkedListDestroy(IListInstance *instance) {
	any_destroy(instance->list);
}

void i_list_ll_functions_new() {
	i_list_ll = malloc(sizeof(IList));
	i_list_ll->new = IList_LinkedList;
	i_list_ll->print = ll_print;
	i_list_ll->size = ll_size;
	i_list_ll->isEmpty = ll_isEmpty;
	i_list_ll->append = ll_append;
	i_list_ll->insert = ll_insert;
	i_list_ll->get = ll_get;
	i_list_ll->set = ll_set;
	i_list_ll->remove = ll_remove;
	i_list_ll->getIndexOf = ll_getIndexOf;
	i_list_ll->search = ll_search;
	i_list_ll->destroy = IList_LinkedListDestroy;
}
