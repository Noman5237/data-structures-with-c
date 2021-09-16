/**
 * @file: ll.c
 * @author: Anonyman637
 * @date: 9/12/2021; 10:25 AM
 */

#include <internals/interfaces/list/bst.h>

/* ============================== Runtime Registry ========================= */

void i_list_bst_register() {
	if (i_list_bst != NULL) {
		return;
	}
	i_list_bst_functions_new();
}

void i_list_bst_deregister() {
	if (i_list_bst == NULL) {
		return;
	}
	free(i_list_bst);
	i_list_bst = NULL;
}

/* ============================== Interface Implementation ========================= */

Any *IList_BinarySearchTree() {
	let this = List();
	IListInstance *instance = this->data;
	instance->list = BinarySearchTree();
	instance->functions = i_list_bst;
	return this;
}

void IList_BSTDestroy(IListInstance *instance) {
	any_destroy(instance->list);
}

void i_list_bst_functions_new() {
	i_list_bst = malloc(sizeof(IList));
	i_list_bst->print = bst_print;
	i_list_bst->size = bst_size;
	i_list_bst->isEmpty = bst_isEmpty;
	i_list_bst->append = bst_append;
	i_list_bst->get = bst_get;
	i_list_bst->remove = bst_remove;
	i_list_bst->removeItem = bst_removeItem;
	i_list_bst->search = bst_search;
	i_list_bst->getIndexOf = bst_getIndexOf;
	i_list_bst->destroy = IList_BSTDestroy;
}
