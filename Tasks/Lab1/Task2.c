/**
 * @file: task2.c
 * @author: Anonyman637
 * @date: 4/22/2021; 2:35 PM
 */
 
#include <stdio.h>

float square(float x);

float square(float x) {
	float p;
	p = x * x;
	return (p);
}

int main() {
	float m, n;
	printf("\nEnter some number for finding square \n");
	scanf("%f", &m);
	n = square(m);
	printf("\nSquare of the given number %f is %f", m, n);
}
