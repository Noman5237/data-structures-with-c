/**
 * @file: doubleLinkedList.c
 * @author: Anonyman637
 * @date: 5/27/2021; 2:29 PM
 */

#include <dscommon.h>

struct Node {
	int data;
	
	struct Node *prev;
	struct Node *next;
};

typedef struct Node Node;

struct List {
	Node *firstnode;
	Node *lastnode;
};

typedef struct List List;

List *list_create() {
	List *list = malloc(sizeof(List));
	list->firstnode = NULL;
	list->lastnode = NULL;
	return list;
}

Node *node_create(int data) {
	//Declare a pointer to hold the address of a node
	Node *node;
	
	//Allocate the memory and assign the value to the data and addresses
	node = malloc(sizeof(Node));
	node->data = data;
	node->prev = NULL;
	node->next = NULL;
	
	//return the address of the created node
	return node;
}


int list_isEmpty(List *list) {
	return list->firstnode == NULL;
}

//Traverse the list in forward direction and print the data
void list_forward(List *list) {
	printf("\n");
	
	if (list_isEmpty(list)) {
		printf("empty list\n");
		return;
	}
	
	Node *currentHead = list->firstnode;
	while (currentHead != NULL) {
		printf("%d ", currentHead->data);
		currentHead = currentHead->next;
	}
	
	printf("\n");
}

//Traverse the list in backward direction and print the data
void list_backword(List *list) {
	printf("\n");
	
	if (list_isEmpty(list)) {
		printf("empty list\n");
		return;
	}
	
	Node *currentTail = list->lastnode;
	while (currentTail != NULL) {
		printf("%d ", currentTail->data);
		currentTail = currentTail->prev;
	}
	
	printf("\n");
}

// Insert the "newnode" before the "node" in the provided "list"
void list_insertBefore(Node *newnode, Node *node, List *list) {
	newnode->prev = node->prev;
	newnode->next = node;
	
	if (node->prev == NULL) {
		list->firstnode = newnode;
	} else {
		node->prev->next = newnode;
	}
	
	node->prev = newnode;
	
}

//Insert the "newnode" after the "node" in th "list"
void list_insertAfter(Node *newnode, Node *node, List *list) {
	newnode->prev = node;
	newnode->next = node->next;
	
	if (node->next == NULL) {
		list->lastnode = newnode;
	} else {
		node->next->prev = newnode;
	}
	
	node->next = newnode;
	
}

// Insert the "newnode" at the beginning of the list
void list_insertAtFront(Node *newnode, List *list) {
	if (list->firstnode == NULL) {
		list->firstnode = newnode;
		list->lastnode = newnode;
	} else {
		list_insertBefore(newnode, list->firstnode, list);
	}
}

// Insert the "newnode" at the end of the "list"
void list_insertAtEnd(Node *newnode, List *list) {
	if (list->lastnode == NULL) {
		list->lastnode = newnode;
		list->firstnode = newnode;
	} else {
		list_insertAfter(newnode, list->lastnode, list);
	}
	
}

void list_removeNode(Node *node, List *list) {
	
	if (list_isEmpty(list)) {
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

void list_removeFromFront(List *list) {
	list_removeNode(list->firstnode, list);
}

void list_removeFromEnd(List *list) {
	list_removeNode(list->lastnode, list);
}

// Removes a node from a certain location of the list. (0 based indexing)
void list_removeAt(int index, List *list) {
	Node *current = list->firstnode;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	
	list_removeNode(current, list);
}

void list_free(List *list) {
	while (!list_isEmpty(list)) {
		list_removeFromFront(list);
	}
	free(list);
}
