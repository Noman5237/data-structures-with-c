/**
 * @file: dllQueue.h
 * @author: Anonyman637
 * @date: 6/17/2021; 1:05 AM
 */

#ifndef DATASTRUCTURESCOURSE_DLLQUEUE_H
#define DATASTRUCTURESCOURSE_DLLQUEUE_H

#include <doublyLinkedList.h>

typedef DLL DLL_Queue;

DLL_Queue *dll_queue_create();

void dll_queue_enqueue(int data, DLL_Queue *queue);

void dll_queue_dequeue(DLL_Queue *queue);

void dll_queue_display(DLL_Queue *stack);

void dll_queue_free(DLL_Queue *queue);

#endif //DATASTRUCTURESCOURSE_DLLQUEUE_H
