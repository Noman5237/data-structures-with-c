/**
 * @file: doubleLinkedList.c
 * @author: Anonyman637
 * @date: 5/27/2021; 2:29 PM
 */

#include <doublyLinkedList.h>

DLL_Node *dll_node_create(int data) {
	//Declare a pointer to hold the address of a node
	DLL_Node *node;
	
	//Allocate the memory and assign the value to the data and addresses
	node = malloc(sizeof(DLL_Node));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	
	//return the address of the created node
	return node;
}

DLL *dll_create() {
	DLL *list = malloc(sizeof(DLL));
	list->firstnode = NULL;
	list->lastnode = NULL;
	return list;
}

int dll_isEmpty(DLL *list) {
	return list->firstnode == NULL;
}

//Traverse the list in forward direction and print the data
void dll_forward(DLL *list) {
	printf("\n");
	
	if (dll_isEmpty(list)) {
		printf("empty list\n");
		return;
	}
	
	DLL_Node *currentHead = list->firstnode;
	while (currentHead != NULL) {
		currentHead->printer(currentHead->data);
		currentHead = currentHead->next;
	}
	
	printf("\n");
}

//Traverse the list in backward direction and print the data
void dll_backward(DLL *list) {
	printf("\n");
	
	if (dll_isEmpty(list)) {
		printf("empty list\n");
		return;
	}
	
	DLL_Node *currentTail = list->lastnode;
	while (currentTail != NULL) {
		currentTail->printer(currentTail->data);
		currentTail = currentTail->prev;
	}
	
	printf("\n");
}

// Insert the "newnode" before the "node" in the provided "list"
void dll_insertBefore(DLL_Node *newNode, DLL_Node *dll_Node, DLL *list) {
	newNode->prev = dll_Node->prev;
	newNode->next = dll_Node;
	
	if (dll_Node->prev == NULL) {
		list->firstnode = newNode;
	} else {
		dll_Node->prev->next = newNode;
	}
	
	dll_Node->prev = newNode;
	
}

//Insert the "newnode" after the "node" in th "list"
void dll_insertAfter(DLL_Node *newNode, DLL_Node *dll_Node, DLL *list) {
	newNode->prev = dll_Node;
	newNode->next = dll_Node->next;
	
	if (dll_Node->next == NULL) {
		list->lastnode = newNode;
	} else {
		dll_Node->next->prev = newNode;
	}
	
	dll_Node->next = newNode;
	
}

// Insert the "newnode" at the beginning of the list
void dll_insertAtFront(DLL_Node *newNode, DLL *list) {
	if (list->firstnode == NULL) {
		list->firstnode = newNode;
		list->lastnode = newNode;
	} else {
		dll_insertBefore(newNode, list->firstnode, list);
	}
}

// Insert the "newnode" at the end of the "list"
void dll_insertAtEnd(DLL_Node *newNode, DLL *list) {
	if (list->lastnode == NULL) {
		list->lastnode = newNode;
		list->firstnode = newNode;
	} else {
		dll_insertAfter(newNode, list->lastnode, list);
	}
	
}

void dll_removeNode(DLL_Node *node, DLL *list) {
	
	if (dll_isEmpty(list)) {
		printf("Cannot remove node from empty list\n");
		return;
	}
	
	if (node->prev != NULL) {
		node->prev->next = node->next;
	} else {
		list->firstnode = node->next;
	}
	
	if (node->next != NULL) {
		node->next->prev = node->prev;
	} else {
		list->lastnode = node->prev;
	}
	
	free(node);
}

void dll_removeFromFront(DLL *list) {
	dll_removeNode(list->firstnode, list);
}

void dll_removeFromEnd(DLL *list) {
	dll_removeNode(list->lastnode, list);
}

// Removes a node from a certain location of the list. (0 based indexing)
void dll_removeAt(int index, DLL *list) {
	DLL_Node *current = list->firstnode;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	
	dll_removeNode(current, list);
}

void dll_free(DLL *list) {
	while (!dll_isEmpty(list)) {
		dll_removeFromFront(list);
	}
	free(list);
}
