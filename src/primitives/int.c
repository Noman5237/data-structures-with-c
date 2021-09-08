/**
 * @file: t_int.c
 * @author: Anonyman637
 * @date: 8/26/2021; 4:00 PM
 */

#include <internals/primitives/int.h>

/* ============================== Runtime Registry ========================= */

void t_int_register() {
	if (t_int != NULL) {
		return;
	}
	
	t_int = type_new("Int");
	t_int->clone = int_clone;
	t_int->compare = int_compare;
	t_int->print = int_print;
	t_int->destroyData = int_data_destroy;
}

void t_int_deregister() {
	if (t_int == NULL) {
		return;
	}
	
	type_destroy(t_int);
	t_int = NULL;
}

/* ============================== Core Type Functions ========================= */

Any *Int(int integer) {
	int *data = malloc(sizeof(int));
	*data = integer;
	Any *this = any_new(data, t_int);
	return this;
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

void int_data_destroy(Any *this) {
	free(this->data);
}
