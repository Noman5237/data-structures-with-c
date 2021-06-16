/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 6/3/2021; 2:53 PM
 */

#include "doubleLinkedList.c"

int main() {
	Node *newNode;
	List list;
	list.firstnode = NULL;
	list.lastnode = NULL;
	
	newNode = node_create(1);
	list_insertAtFront(newNode, &list);
	newNode = node_create(2);
	list_insertAtFront(newNode, &list);
	newNode = node_create(3);
	list_insertBefore(newNode, list.lastnode, &list);
	newNode = node_create(4);
	list_insertAfter(newNode, list.lastnode, &list);
	newNode = node_create(5);
	list_insertAfter(newNode, list.firstnode, &list);
	newNode = node_create(6);
	list_insertAtEnd(newNode, &list);
	
	list_forward(&list);
	list_backword(&list);
	
	list_removeAt(2, &list);
	list_forward(&list);
	
	list_removeAt(4, &list);
	list_forward(&list);
	
	list_removeAt(0, &list);
	list_forward(&list);
	
	list_removeAt(2, &list);
	list_forward(&list);
	
	list_removeFromEnd(&list);
	list_forward(&list);
	
	list_removeFromFront(&list);
	list_forward(&list);
	
	printf("done");
	return 0;
}
