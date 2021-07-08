/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 6/3/2021; 2:53 PM
 */

#include <doublyLinkedList.h>

int main() {
	DLL_Node *newNode;
	DLL list;
	list.firstnode = NULL;
	list.lastnode = NULL;
	
	newNode = dll_node_create(1);
	dll_insertAtFront(newNode, &list);
	newNode = dll_node_create(2);
	dll_insertAtFront(newNode, &list);
	newNode = dll_node_create(3);
	dll_insertBefore(newNode, list.lastnode, &list);
	newNode = dll_node_create(4);
	dll_insertAfter(newNode, list.lastnode, &list);
	newNode = dll_node_create(5);
	dll_insertAfter(newNode, list.firstnode, &list);
	newNode = dll_node_create(6);
	dll_insertAtEnd(newNode, &list);
	
	dll_forward(&list);
	dll_backward(&list);
	
	dll_removeAt(2, &list);
	dll_forward(&list);
	
	dll_removeAt(4, &list);
	dll_forward(&list);
	
	dll_removeAt(0, &list);
	dll_forward(&list);
	
	dll_removeAt(2, &list);
	dll_forward(&list);
	
	dll_removeFromEnd(&list);
	dll_forward(&list);
	
	dll_removeFromFront(&list);
	dll_forward(&list);
	
	printf("done");
	return 0;
}
