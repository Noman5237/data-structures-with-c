/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 5/20/2021; 2:50 PM
 */

#include <dscommon.h>

typedef int node_t;

// Creating the structure for declaring a Node
struct Node {
	//Declare the variable to store data
	node_t data;
	
	
	//Declare to variable to store the next node's address
	struct Node *next;
};

typedef struct Node Node;

//Creating a structure for managing a linked list
struct List {
	Node *head;
};

typedef struct List List;

Node *createNode() {
	//Declare a pointer type variable to hold the address of a node
	Node *node;
	//Allocate memory for a node and save the address to previously declared variable
	node = (Node *) malloc(sizeof(node));
	//Ask the user to enter the data for the node
	node_t data;
	printf("Data for new node: ");
	//Read and store the data in the node
	scanf("%d", &data);
	node->data = data;
	//Set the pointer (usually named "next") of the node as NULL
	node->next = NULL;
	//Return the address of newly created node
	return node;
}

void displayList(List *list) {
	printf("\n\n");
	Node *currentHead = list->head;
	while (currentHead != NULL) {
		printf("%d ", currentHead->data);
		currentHead = currentHead->next;
	}
	printf("\n\n");
}

void insertAtFront(List *list, Node *newHead) {
	newHead->next = list->head;
	list->head = newHead;
}

void insertAtEnd(List *list, Node *newNode) {
	//Add the newnode to the end of the list
	Node *currentHead = list->head;
	while (currentHead->next != NULL) {
		currentHead = currentHead->next;
	}
	
	currentHead->next = newNode;
}

void insertAt(List *list, Node *newNode, int index) {
	if (index == 0) {
		insertAtFront(list, newNode);
		return;
	}
	
	Node *currentHead = list->head;
	for (int i = 0; i < index - 1 && currentHead != NULL; i++) {
		currentHead = currentHead->next;
	}
	
	newNode->next = currentHead->next;
	currentHead->next = newNode;
}

int main() {
	int n, i;
	List list;
	list.head = NULL;
	
	printf("Enter the number of elements you want to store: ");
	scanf("%d", &n);
	
	//Run a loop n times, each time do the following:
	while (n--) {
		// Create a new node by calling our user defined function
		Node *node = createNode();
		// Add the newnode at the beginning of the list
		insertAtFront(&list, node);
	}
	
	
	//Display all the contents of the list
	displayList(&list);
	
	insertAt(&list, createNode(), 0);
	insertAt(&list, createNode(), 1);
	insertAt(&list, createNode(), 2);
	
	displayList(&list);
	
	insertAtEnd(&list, createNode());
	insertAtEnd(&list, createNode());
	insertAtEnd(&list, createNode());
	
	displayList(&list);
	
	printf("\nEnd\n");
	return 0;
}
