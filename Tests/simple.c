/**
 * @file: sample.c
 * @author: Anonyman637
 * @date: 9/2/2021; 3:04 PM
 */

#include <criterion/criterion.h>

Test(misc, failing) {
	cr_assert(0);
}

Test(misc, passing) {
	cr_assert(1);
}
