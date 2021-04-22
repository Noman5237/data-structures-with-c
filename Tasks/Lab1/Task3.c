/**
 * @file: Task3.c
 * @author: Anonyman637
 * @date: 4/22/2021; 2:44 PM
 */

#include <stdio.h>

float solve(float x, float y) {
	float res;
	res = 5 * (x * x) + 7 * y + 10;
	return res;
}

int main() {
	float x, y, output;
	printf("\nEnter the value of x:\n");
	scanf("%f", &x);
	printf("\nEnter the value of y:\n");
	scanf("%f", &y);
	output = solve(x, y);
	printf("\nThe result is: %f", output);
}