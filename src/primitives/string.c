/**
 * @file: string.c
 * @author: Anonyman637
 * @date: 8/26/2021; 4:00 PM
 */

#include <internals/primitives/string.h>

/* ============================== Runtime Registry ========================= */

void t_string_register() {
	if (t_string != NULL) {
		return;
	}
	
	t_string = type_new("string");
	t_string->clone = string_clone;
	t_string->compare = string_compare;
	t_string->print = string_print;
	t_string->destroyData = string_data_destroy;
}

void t_string_deregister() {
	if (t_string == NULL) {
		return;
	}
	
	type_destroy(t_string);
	t_string = NULL;
}

/* ============================== Core Type Functions ========================= */

Any *String(char *string) {
	char *data = malloc(strlen(string) + 1);
	strcpy(data, string);
	Any *this = any_new(data, t_string);
	return this;
}

char *string_data(Any *this) {
	return (char *) this->data;
}

Any *string_clone(Any *this) {
	char *data = (char *) this->data;
	return String(data);
}

int string_compare(Any *this, Any *other) {
	char *thisData = (char *) this->data;
	char *otherData = (char *) other->data;
	return strcmp(thisData, otherData);
}

void string_print(Any *this) {
	printf("%s", (char *) this->data);
}

void string_data_destroy(Any *this) {
	free(this->data);
}
