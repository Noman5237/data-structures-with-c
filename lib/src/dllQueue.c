/**
 * @file: dllQueue.c
 * @author: Anonyman637
 * @date: 6/17/2021; 1:06 AM
 */
 
#include <dllQueue.h>

DLL_Queue *dll_queue_create() {
	return dll_create();
}

void dll_queue_enqueue(int data, DLL_Queue *queue) {
	dll_insertAtEnd(dll_node_create(data), queue);
}

void dll_queue_dequeue(DLL_Queue *queue) {
	dll_removeFromFront(queue);
}

void dll_queue_display(DLL_Queue *stack) {
	dll_forward(stack);
}

void dll_queue_free(DLL_Queue *queue) {
	dll_free(queue);
}

