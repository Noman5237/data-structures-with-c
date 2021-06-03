/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 6/3/2021; 2:53 PM
 */

#include "./doubleLinkedList.c"

int main() {
	Node *newNode;
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
	
	removeAt(2, &list);
	forward(&list);
	
	removeFromEnd(&list);
	forward(&list);
	
	removeFromFront(&list);
	forward(&list);
	
	printf("done");
	return 0;
}
