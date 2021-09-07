/**
 * @file: t_int.c
 * @author: Anonyman637
 * @date: 8/26/2021; 4:00 PM
 */

#include <types/int.h>

Any *Int(int data) {
	int *dataInMemory = malloc(sizeof(int));
	*dataInMemory = data;
	Any *int_any = any_new(dataInMemory, t_int);
	return int_any;
}

Any *t_int_copy(Any *this) {
	int data = *(int *) this->data;
	return Int(data);
}

int t_int_compare(Any *this, Any *other) {
	int num1 = *(int *) this->data;
	int num2 = *(int *) other->data;
	return num1 - num2;
}

void t_int_print(Any *this) {
	printf("%d", *(int *) this->data);
}

void t_int_destroy(Any *this) {
	free(this->data);
	any_destroy(this);
}

void t_int_register() {
	t_int = type_new("Int");
	t_int->copy = t_int_copy;
	t_int->compare = t_int_compare;
	t_int->print = t_int_print;
	t_int->destroy = t_int_destroy;
}

void t_int_deregister() {
	type_destroy(t_int);
	t_int = NULL;
}
