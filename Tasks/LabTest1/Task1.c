/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 5/6/2021; 1:37 PM
 */

#include<stdio.h>

#define MAXSIZE 6
#define true 1
#define false 0

int itemcount = 0;
int front = 0;
int rear = -1;

int isFull() {
	if (itemcount == MAXSIZE)
		return true;
	
	return false;
}

int isEmpty() {
	if (itemcount == 0)
		return true;
	return false;
}

int peek(int *que) {
	if (itemcount)
		return que[front];
}

void enque(int *que, int data) { // Do not forget to update the value of itemcount
	if (!isFull()) { //Check if queue is not full
		//Check for the critical case
		if (rear == MAXSIZE - 1) {
			rear = -1;
		}
		
		//increment the value of rear and insert the value
		rear++;
		que[rear] = data;
		
		// incrementing the itemcount
		itemcount++;
	} else
		printf("\nCan't push value, queue is full\n");
	
}

int deque(int *que) { //Do not forget to update the value of itemcount
	if (!isEmpty()) { //Check if the queue is not empty
		// Save the data from the front index
		int data = que[front];
		// increment the front and check for critical case
		front++;
		if (front == MAXSIZE) {
			front = 0;
		}
		// decrementing the itemcount
		itemcount--;
		
		// return the saved value
		return data;
	} else
		printf("\nCan't pop value, queue is empty\n");
}

void display(int *que) {
	int currentItemCount = 0;
	printf("\n");
	for (int i = front; currentItemCount < itemcount; i++) {
		if (i == MAXSIZE) {
			i = 0;
		}
		printf("%d ", que[i]);
		currentItemCount++;
	}
	printf("\n");
}

int main() {
	int x;
	int que[MAXSIZE];
	enque(que, 5);
	enque(que, 6);
	enque(que, 7);
	enque(que, 8);
	enque(que, 9);
	enque(que, 10);
	enque(que, 11);
	display(que);
	deque(que);
	enque(que, 12);
	display(que);
	
	return 0;
}
