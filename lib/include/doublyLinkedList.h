/**
 * @file: doubleLinkedList.h
 * @author: Anonyman637
 * @date: 6/16/2021; 11:35 PM
 */

#ifndef DATASTRUCTURESCOURSE_DOUBLYLINKEDLIST_H
#define DATASTRUCTURESCOURSE_DOUBLYLINKEDLIST_H

#include <dsCommon.h>

typedef struct DLL_Node {
	int data;
	
	struct DLL_Node *prev;
	struct DLL_Node *next;
} DLL_Node;

typedef struct DoublyLinkedList {
	DLL_Node *firstnode;
	DLL_Node *lastnode;
} DoublyLinkedList;

typedef struct DoublyLinkedList DLL;

DLL_Node *dll_node_create(int data);

DLL *dll_create();

int dll_isEmpty(DLL *list);

void dll_forward(DLL *list);

void dll_backward(DLL *list);

void dll_insertBefore(DLL_Node *newNode, DLL_Node *dll_Node, DLL *list);

void dll_insertAfter(DLL_Node *newNode, DLL_Node *dll_Node, DLL *list);

void dll_insertAtFront(DLL_Node *newNode, DLL *list);

void dll_insertAtEnd(DLL_Node *newNode, DLL *list);

void dll_removeNode(DLL_Node *node, DLL *list);

void dll_removeFromFront(DLL *list);

void dll_removeFromEnd(DLL *list);

void dll_removeAt(int index, DLL *list);

void dll_free(DLL *list);

// TODO: dll_search

#endif //DATASTRUCTURESCOURSE_DOUBLYLINKEDLIST_H
