/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 5/27/2021; 2:29 PM
 */

#include <dsCommon.h>

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

Node *createNode(int data) {
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

//Traverse the list in forward direction and print the data
void forward(List *list) {
	printf("\n");
	
	Node *currentHead = list->firstnode;
	if (currentHead == NULL) {
		printf("empty list\n");
		return;
	}
	while (currentHead != NULL) {
		printf("%d ", currentHead->data);
		currentHead = currentHead->next;
	}
	
	printf("\n");
}

//Traverse the list in backward direction and print the data
void backward(List *list) {
	printf("\n");
	
	Node *currentTail = list->lastnode;
	if (currentTail == NULL) {
		printf("empty list\n");
		return;
	}
	
	while (currentTail != NULL) {
		printf("%d ", currentTail->data);
		currentTail = currentTail->prev;
	}
	
	printf("\n");
}

// Insert the "newnode" before the "node" in the provided "list"
void insertBefore(Node *newnode, Node *node, List *list) {
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
void insertAfter(Node *newnode, Node *node, List *list) {
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
void insertAtFront(Node *newnode, List *list) {
	if (list->firstnode == NULL) {
		list->firstnode = newnode;
		list->lastnode = newnode;
	} else {
		insertBefore(newnode, list->firstnode, list);
	}
}

// Insert the "newnode" at the end of the "list"
void insertAtEnd(Node *newnode, List *list) {
	if (list->lastnode == NULL) {
		list->lastnode = newnode;
		list->firstnode = newnode;
	} else {
		insertAfter(newnode, list->lastnode, list);
	}
	
}

// Removes a node from a certain location of the list. (0 based indexing)
void removeAt(int index, List *list) {
	Node *current = list->firstnode;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	
	if (current->prev != NULL) {
		current->prev->next = current->next;
	} else {
		list->firstnode = current->next;
	}
	
	if (current->next != NULL) {
		current->next->prev = current->prev;
	} else {
		list->lastnode = current->prev;
	}
	
	free(current);
}

int main() {
	Node *newNode;
	int n, i;
	List list;
	list.firstnode = NULL;
	list.lastnode = NULL;
	
	
	newNode = createNode(1);
	insertAtFront(newNode, &list);
	newNode = createNode(2);
	insertAtFront(newNode, &list);
	newNode = createNode(3);
	insertBefore(newNode, list.lastnode, &list);
	newNode = createNode(4);
	insertAfter(newNode, list.lastnode, &list);
	newNode = createNode(5);
	insertAfter(newNode, list.firstnode, &list);
	newNode = createNode(6);
	insertAtEnd(newNode, &list);
	
	forward(&list);
	backward(&list);
	
	removeAt(2, &list);
	forward(&list);
	
	removeAt(4, &list);
	forward(&list);
	
	removeAt(0, &list);
	forward(&list);
	
	removeAt(0, &list);
	removeAt(0, &list);
	forward(&list);
	
	removeAt(0, &list);
	forward(&list);
	
	printf("done");
	return 0;
}
