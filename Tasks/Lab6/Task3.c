/**
 * @file: Task3.c
 * @author: Anonyman637
 * @date: 6/3/2021; 2:53 PM
 */

#include "doubleLinkedList.c"

typedef struct List Queue;

Queue *queue_create() {
	Queue *queue = malloc(sizeof(Queue));
	queue->firstnode = NULL;
	queue->lastnode = NULL;
	return queue;
}

void queue_enqueue(int data, Queue *queue) {
	list_insertAtEnd(node_create(data), queue);
}

void queue_dequeue(Queue *queue) {
	list_removeFromFront(queue);
}

void queue_display(Queue *stack) {
	list_forward(stack);
}

void queue_free(Queue *queue) {
	while (!list_isEmpty(queue)) {
		queue_dequeue(queue);
	}
	free(queue);
}

int main() {
	Queue *queue = queue_create();
	
	queue_enqueue(1, queue);
	queue_enqueue(2, queue);
	queue_enqueue(3, queue);
	queue_enqueue(4, queue);
	
	queue_display(queue);
	
	queue_dequeue(queue);
	queue_display(queue);
	
	queue_dequeue(queue);
	queue_display(queue);
	
	queue_enqueue(5, queue);
	queue_display(queue);
	
	queue_dequeue(queue);
	queue_display(queue);
	
	queue_dequeue(queue);
	queue_dequeue(queue);
	queue_display(queue);
	
	queue_dequeue(queue);
	
	queue_free(queue);
	
	return 0;
}

