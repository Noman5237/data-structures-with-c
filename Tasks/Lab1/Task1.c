/**
 * @file: task1.c
 * @author: Anonyman637
 * @date: 4/22/2021; 1:52 PM
 */

#include <dscommon.h>

/**
 * Echoes the provided CGPA and Age
 */
void echoCGPANAge() {
	char temp[LEN_MAX];
	printf("Please enter your CGPA: ");
	fflush(stdin);
	scanf("%"STRINGIFY(LEN_MAX)"s", temp);
	printf("Your CGPA is %s\n", temp);
	printf("Please enter your age: ");
	fflush(stdin);
	scanf("%"STRINGIFY(LEN_MAX)"s", temp);
	printf("You are %s years old\n", temp);
}

int main() {
	echoCGPANAge();
}
