/**
 * @file: Task2.c
 * @author: Anonyman637
 * @date: 6/10/2021; 3:42 PM
 */

#include <doublyLinkedList.h>

int countNoOfElementsGreaterThan(int threshold, DLL *list) {
	int count = 0;
	int noOfOperations = 0;
	
	DLL_Node *currentHead = list->firstnode;
	++noOfOperations;
	
	while (currentHead != NULL) {
		++noOfOperations;
		
		if (currentHead->data > threshold) {
			++noOfOperations;
			
			++count;
			++noOfOperations;
		}
		
		currentHead = currentHead->next;
		++noOfOperations;
	}
	
	printf("Total no of operations required: %d\n", noOfOperations);
	
	return count;
}

int main() {
	DLL *list = dll_create();
	
	int tini;
	
	printf("Enter a number into the list (q to stop): ");
	while (scanf("%d", &tini)) {
		dll_insertAtFront(dll_node_create(tini), list);
		printf("Enter a number into the list (q to stop): ");
	}
	scanf("q");
	
	printf("Provided List: ");
	dll_backward(list);
	
	// counting the number of elements greater than n
	
	printf("Enter a number to filter list by values greater than: ");
	scanf("%d", &tini);
	
	int noOfItemsGreaterThanThreshold = countNoOfElementsGreaterThan(tini, list);
	printf("No of items in the list greater than %d is %d\n", tini, noOfItemsGreaterThanThreshold);
	
	dll_free(list);
	
	return 0;
}
