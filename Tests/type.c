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
	return any_new(customTypeData, t_custom);
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
	any_destroy(any);
}

void t_custom_register() {
	t_custom = type_new("Custom");
	t_custom->print = t_custom_print;
	t_custom->destroy = t_custom_free;
	t_custom->copy = t_custom_copy;
	t_custom->compare = t_custom_compare;
}

void t_custom_unregister() {
	type_destroy(t_custom);
}

/* ============================== Testing ========================= */

void setup(void) {
	t_custom_register();
}

void teardown(void) {
	t_custom_unregister();
}

TestSuite(TypeCustom, .init = setup, .fini = teardown);

Test(TypeCustom, TypeName) {
	let custom = CustomType(5, 'a');
	cr_assert_str_eq(type(custom), "Custom");
	destroy(custom);
}

Test(TypeCustom, VarCreateDataFree) {
	let custom = CustomType(5, 'a');
	CustomTypeData *customData = (CustomTypeData *) custom->data;
	cr_assert_eq(customData->a, 5);
	cr_assert_eq(customData->c, 'a');
	destroy(custom);
}

Test(TypeCustom, Compare) {
	let custom1 = CustomType(5, 'a');
	let custom2 = CustomType(5, 'a');
	let custom3 = CustomType(10, 'a');
	let custom4 = CustomType(5, 'A');
	
	cr_expect_eq(compare(custom1, custom2), 0);
	cr_expect_lt(compare(custom2, custom3), 0);
	cr_expect_gt(compare(custom1, custom4), 0);
	
	destroy(custom1);
	destroy(custom2);
	destroy(custom3);
	destroy(custom4);
}

Test(TypeCustom, Copy) {
	let custom = CustomType(5, 'a');
	let copyCustom = copy(custom);
	cr_expect_eq(compare(custom, copyCustom), 0);
	destroy(custom);
	destroy(copyCustom);
}
