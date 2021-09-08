/**
 * @file: type.c
 * @author: Anonyman637
 * @date: 8/26/2021; 3:33 PM
 */

#include <type.h>
#include <stdlib.h>
#include <string.h>

Type *type_new(char *typeName) {
	Type *newType = malloc(sizeof(Type));
	newType->typeName = malloc(strlen(typeName) + 1);
	strcpy(newType->typeName, typeName);
	return newType;
}

void type_destroy(Type *type) {
	free(type->typeName);
	free(type);
}

Any *any_new(void *data, Type *type) {
	Any *any = malloc(sizeof(Any));
	any->data = data;
	any->type = type;
	return any;
}

inline char *any_type(Any *this) {
	return this->type->typeName;
}

inline Any *any_clone(Any *this) {
	return this->type->clone(this);
}

inline int any_compare(Any *this, Any *other) {
	return this->type->compare(this, other);
}

inline void any_print(Any *this) {
	this->type->print(this);
}

void any_destroy(Any *this) {
	this->type->destroy(this);
	free(this);
}
