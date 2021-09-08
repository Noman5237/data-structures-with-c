/**
 * @file: dllQueue.c
 * @author: Anonyman637
 * @date: 6/17/2021; 1:06 AM
 */

#include <queue.h>
#include <dscommon.h>
#include <internals/list.h>

/* ============================== Runtime Registry ========================= */

Type *t_queue;

void t_queue_register() {
	if (t_queue != NULL) {
		return;
	}
	
	t_list_register();
	t_queue = type_new("Queue");
	t_queue->print = list_print;
	t_queue->destroyData = list_data_destroy;
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
	ListData *queue = list_data_new();
	let this = any_new(queue, t_queue);
	return this;
}

/* ============================== Advanced Type Functions ========================= */

int (*queue_size)(Any *this) = list_size;

int (*queue_isEmpty)(Any *this) = list_isEmpty;

Any *queue_front(Any *this) {
	return list_get(this, 0);
}

Any *queue_rear(Any *this) {
	return list_get(this, queue_size(this) - 1);
}

void queue_enqueue(Any *this, Any *newDatum) {
	list_append(this, newDatum);
}

void queue_dequeue(Any *this) {
	list_remove(this, 0);
}
