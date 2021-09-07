/**
 * @file: Test_Type.c
 * @author: Anonyman637
 * @date: 8/26/2021; 5:52 PM
 */

#include <type.h>
#include <criterion/criterion.h>

Type *t_custom;

typedef struct CustomTypeData {
	int a;
	char c;
} CustomTypeData;

Any *CustomType(int a, char c) {
	CustomTypeData *customTypeData = malloc(sizeof(CustomTypeData));
	customTypeData->a = a;
	customTypeData->c = c;
	return any_create(customTypeData, t_custom);
}

Any *t_custom_copy(Any *this) {
	CustomTypeData *customTypeData = this->data;
	return CustomType(customTypeData->a, customTypeData->c);
}

int t_custom_compare(Any *this, Any *other) {
	CustomTypeData *thisData = this->data;
	CustomTypeData *otherData = other->data;
	if (thisData->a == otherData->a) {
		if (thisData->c == otherData->c) {
			return 0;
		} else {
			return thisData->c > otherData->c ? 1 : -1;
		}
	} else {
		return thisData->a > otherData->a ? 1 : -1;
	}
}

void t_custom_print(Any *any) {
	CustomTypeData *data = any->data;
	cr_log_info("(%d, %c)", data->a, data->c);
}

void t_custom_free(Any *any) {
	free(any->data);
	any_free(any);
}

void t_custom_register() {
	t_custom = type_create("Custom");
	t_custom->print = t_custom_print;
	t_custom->free = t_custom_free;
	t_custom->copy = t_custom_copy;
	t_custom->compare = t_custom_compare;
}

void t_custom_unregister() {
	type_free(t_custom);
}

/* ============================== Testing ========================= */

void setup(void) {
	t_custom_register();
}

void teardown(void) {
	t_custom_unregister();
}

TestSuite(CustomType, .init = setup, .fini = teardown);

Test(CustomType, TypeNameIsCorrect) {
	cr_assert_str_eq("Custom", t_custom->typeName);
}

Test(CustomType, VarCreateDataFree) {
	let custom = CustomType(5, 'a');
	CustomTypeData *customData = (CustomTypeData *) custom->data;
	cr_assert_eq(5, customData->a);
	cr_assert_eq('a', customData->c);
	t_custom_free(custom);
}

Test(CustomType, Compare) {
	let custom1 = CustomType(5, 'a');
	let custom2 = CustomType(5, 'a');
	let custom3 = CustomType(10, 'a');
	let custom4 = CustomType(5, 'A');
	
	cr_expect(t_custom_compare(custom1, custom2) == 0);
	cr_expect(t_custom_compare(custom2, custom3) < 0);
	cr_expect(t_custom_compare(custom1, custom4) > 0);
}

Test(CustomType, Print) {
	let custom = CustomType(10, 'b');
	cr_log_info("Printing custom initialized with (10, 'b'): ");
	t_custom_print(custom);
	t_custom_free(custom);
}
