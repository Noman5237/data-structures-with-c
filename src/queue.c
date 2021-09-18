/**
 * @file: dllQueue.c
 * @author: Anonyman637
 * @date: 6/17/2021; 1:06 AM
 */

#include <queue.h>
#include <dscommon.h>
#include <internals/ll.h>

/* ============================== Runtime Registry ========================= */

Type *t_queue;

void t_queue_register() {
	if (t_queue != NULL) {
		return;
	}
	
	t_ll_register();
	t_queue = type_new("Queue");
	t_queue->print = ll_print;
	t_queue->destroyData = ll_data_destroy;
}

void t_queue_deregister() {
	if (t_queue == NULL) {
		return;
	}
	
	type_destroy(t_queue);
	t_queue = NULL;
}

/* ============================== Core Type Functions ========================= */

Any *Queue() {
	LLData *queue = ll_data_new();
	let this = any_new(queue, t_queue);
	return this;
}

/* ============================== Advanced Type Functions ========================= */

int (*queue_size)(Any *this) = ll_size;

int (*queue_isEmpty)(Any *this) = ll_isEmpty;

Any *queue_front(Any *this) {
	return ll_get(this, 0);
}

Any *queue_rear(Any *this) {
	return ll_get(this, queue_size(this) - 1);
}

void queue_enqueue(Any *this, Any *newDatum) {
	ll_append(this, newDatum);
}

void queue_dequeue(Any *this) {
	ll_remove(this, 0);
}
