/**
 * @file: Quiz1.c
 * @author: Anonyman637
 * @date: 6/12/2021; 8:00 PM
 */

#include <stdio.h>

typedef struct Node {
	int data;
	struct Node *next;
} Node;

void questionNo1() {
	int integer;
	printf("size of integer type variable: %zu\n", sizeof(integer));
	void *pointer;
	printf("size of pointer type variable: %zu\n", sizeof(pointer));
	Node node;
	printf("size of one node: %zu\n", sizeof(Node));
	
	int array[13] = {0};
	printf("size of array with 13 integers: %zu\n", sizeof(array));
	printf("size of linked list with 13 integers: %zu\n", sizeof(node) * 13);
	
	printf("Single pros of using linked list over array is that we can dynamically add values to the list anywhere we want any time we want as long as there is space without much overhead\n");
}


int main() {
	printf("Answer to the question no. 1\n");
	questionNo1();
}
