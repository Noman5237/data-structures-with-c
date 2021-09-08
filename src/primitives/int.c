/**
 * @file: t_int.c
 * @author: Anonyman637
 * @date: 8/26/2021; 4:00 PM
 */

#include <primitives/int.h>

/* ============================== Runtime Registry ========================= */

void t_int_register() {
	if (t_int != NULL) {
		return;
	}
	
	t_int = type_new("Int");
	t_int->clone = int_clone;
	t_int->compare = int_compare;
	t_int->print = int_print;
	t_int->destroy = int_destroy;
}

void t_int_deregister() {
	if (t_int == NULL) {
		return;
	}
	
	type_destroy(t_int);
	t_int = NULL;
}

/* ============================== Core Type Functions ========================= */

Any *Int(int data) {
	int *dataInMemory = malloc(sizeof(int));
	*dataInMemory = data;
	Any *int_any = any_new(dataInMemory, t_int);
	return int_any;
}

inline int *int_data(Any *this) {
	return (int *) this->data;
}

Any *int_clone(Any *this) {
	int data = *(int *) this->data;
	return Int(data);
}

int int_compare(Any *this, Any *other) {
	int num1 = *(int *) this->data;
	int num2 = *(int *) other->data;
	return num1 - num2;
}

void int_print(Any *this) {
	printf("%d", *(int *) this->data);
}

void int_destroy(Any *this) {
	free(this->data);
}
