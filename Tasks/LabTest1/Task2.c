/**
 * @file: Task2.c
 * @author: Anonyman637
 * @date: 5/6/2021; 1:40 PM
 */

#include <stdio.h>

#define true 1
#define false 0
#define MAXSIZE 1010
int top = -1;

int isempty() {
	
	if (top == -1)
		return true;
	else
		return false;
}

int isfull() {
	
	if (top == MAXSIZE - 1)
		return true;
	else
		return false;
}

char peek(char *stack) {
	if (top != -1)
		return stack[top];
	return -1;
}

char pop(char *stack) {
	char data;
	
	if (!isempty()) {
		data = stack[top];
		top = top - 1;
		return data;
	} else {
		return -1;
	}
}

char push(char *stack, char data) {
	
	if (!isfull()) {
		top = top + 1;
		stack[top] = data;
		return 0;
	} else {
		return -1;
	}
}

void displayBottomTop(char *stack) {
	for (int i = 0; i <= top; i++) {
		printf("%c", stack[i]);
	}
}

int main() {
	char stack[MAXSIZE];
	char input[MAXSIZE];
	
	//Read the input from keyboard
	scanf("%s", input);
	
	//Your code goes here
	// Iterate through every elements of input
	for (int i = 0, c = input[i]; c != '\0'; i++, c = input[i]) {
		// if top value of stack is same as current element, pop it
		if (c == peek(stack)) {
			pop(stack);
		} else {
			// else push the current value
			push(stack, c);
		}
	}
	
	// After finishing the iteration
	// if nothing left in the stack, print "Empty String"
	if (isempty()) {
		printf("Empty String");
	} else {
		// else print the content of stack from bottom to top [ Not from top to bottom]
		displayBottomTop(stack);
	}
	
	return 0;
}
