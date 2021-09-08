/**
 * @file: Task2.c
 * @author: Anonyman637
 * @date: 6/10/2021; 3:42 PM
 */

#include "doubleLinkedList.c"

int countNoOfElementsGreaterThan(int threshold, List *list) {
	int count = 0;
	int noOfOperations = 0;
	
	Node *currentHead = list->firstnode;
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
	List *list = list_create();
	
	int tini;
	
	printf("Enter a number into the list (q to stop): ");
	while (scanf("%d", &tini)) {
		list_insertAtFront(node_create(tini), list);
		printf("Enter a number into the list (q to stop): ");
	}
	scanf("q");
	
	printf("Provided List: ");
	list_backword(list);
	
	// counting the number of elements greater than n
	
	printf("Enter a number to filter list by values greater than: ");
	scanf("%d", &tini);
	
	int noOfItemsGreaterThanThreshold = countNoOfElementsGreaterThan(tini, list);
	printf("No of items in the list greater than %d is %d\n", tini, noOfItemsGreaterThanThreshold);
	
	list_free(list);
	
	return 0;
}
