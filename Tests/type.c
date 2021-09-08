/**
 * @file: Test_Type.c
 * @author: Anonyman637
 * @date: 8/26/2021; 5:52 PM
 */

#include <type.h>
#include <criterion/criterion.h>

Type *t_custom;

typedef struct CustomData {
	int a;
	char c;
} CustomData;

Any *CustomType(int a, char c) {
	CustomData *customTypeData = malloc(sizeof(CustomData));
	customTypeData->a = a;
	customTypeData->c = c;
	return any_new(customTypeData, t_custom);
}

CustomData *custom_data(Any *this) {
	return (CustomData *) this->data;
}

Any *custom_clone(Any *this) {
	CustomData *customTypeData = custom_data(this);
	return CustomType(customTypeData->a, customTypeData->c);
}

int custom_compare(Any *this, Any *other) {
	CustomData *thisData = custom_data(this);
	CustomData *otherData = custom_data(other);
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

void custom_print(Any *any) {
	CustomData *data = any->data;
	cr_log_info("(%d, %c)", data->a, data->c);
}

void custom_data_destroy(Any *any) {
	free(any->data);
}

void custom_register() {
	if (t_custom != NULL) {
		return;
	}
	
	t_custom = type_new("Custom");
	t_custom->print = custom_print;
	t_custom->destroyData = custom_data_destroy;
	t_custom->clone = custom_clone;
	t_custom->compare = custom_compare;
}

void custom_unregister() {
	if (t_custom == NULL) {
		return;
	}
	
	type_destroy(t_custom);
	t_custom = NULL;
}

/* ============================== Testing ========================= */

void setup(void) {
	custom_register();
}

void teardown(void) {
	custom_unregister();
}

TestSuite(TypeCustom, .init = setup, .fini = teardown);

Test(TypeCustom, TypeName) {
	let custom = CustomType(5, 'a');
	
	cr_assert_str_eq(any_type(custom), "Custom");
	
	any_destroy(custom);
}

Test(TypeCustom, VarCreateDataFree) {
	let custom = CustomType(5, 'a');
	CustomData *customData = (CustomData *) custom->data;
	
	cr_assert_eq(customData->a, 5);
	cr_assert_eq(customData->c, 'a');
	
	any_destroy(custom);
}

Test(TypeCustom, Compare) {
	let custom1 = CustomType(5, 'a');
	let custom2 = CustomType(5, 'a');
	let custom3 = CustomType(10, 'a');
	let custom4 = CustomType(5, 'A');
	
	cr_expect_eq(any_compare(custom1, custom2), 0);
	cr_expect_lt(any_compare(custom2, custom3), 0);
	cr_expect_gt(any_compare(custom1, custom4), 0);
	
	any_destroy(custom1);
	any_destroy(custom2);
	any_destroy(custom3);
	any_destroy(custom4);
}

Test(TypeCustom, Clone) {
	let custom = CustomType(5, 'a');
	let copyCustom = any_clone(custom);
	
	cr_expect_eq(any_compare(custom, copyCustom), 0);
	
	any_destroy(custom);
	any_destroy(copyCustom);
}
