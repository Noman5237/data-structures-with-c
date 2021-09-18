/**
 * @file: dllQueue.h
 * @author: Anonyman637
 * @date: 6/17/2021; 1:05 AM
 */

#ifndef DATASTRUCTURESCOURSE_QUEUE_H
#define DATASTRUCTURESCOURSE_QUEUE_H

#include <type.h>

/* ============================== Runtime Registry ========================= */

Type *t_queue;

void t_queue_register();

void t_queue_deregister();

/* ============================== Core Type Functions ========================= */

Any *Queue();

/* ============================== Advanced Type Functions ========================= */

int (*queue_size)(Any *this);

int (*queue_isEmpty)(Any *this);

Any *queue_front(Any *this);

Any *queue_rear(Any *this);

void queue_enqueue(Any *this, Any *newDatum);

void queue_dequeue(Any *this);

#endif //DATASTRUCTURESCOURSE_QUEUE_H
