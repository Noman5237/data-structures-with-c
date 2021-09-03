/**
 * @file: t_int.c
 * @author: Anonyman637
 * @date: 8/26/2021; 4:00 PM
 */

#include <types/int.h>

Any *Int(int data) {
	int *dataInMemory = (int *) malloc(sizeof(int));
	*dataInMemory = data;
	Any *int_any = any_create(dataInMemory, t_int);
	return int_any;
}

int t_int_compare(Any *arg1, Any *arg2) {
	int num1 = *(int *) arg1->data;
	int num2 = *(int *) arg2->data;
	return num1 - num2;
}

void t_int_print(Any *any) {
	printf("%d", *(int *) any->data);
}

void t_int_free(Any *any) {
	free(any->data);
	any_free(any);
}

void t_int_register() {
	t_int = type_create("Int");
	t_int->compare = t_int_compare;
	t_int->print = t_int_print;
	t_int->free = t_int_free;
}

void t_int_deregister() {
	type_free(t_int);
	t_int = NULL;
}
