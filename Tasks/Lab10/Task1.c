/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 7/15/2021; 3:19 PM
 */

#include <heap.h>

int main() {
	
	printf("Min Heap Demo\n");
	Heap *minHeap = heap_create(10, HEAP_MINIMUM_DEFAULT_VALUE, heap_defaultMinimumHeapComparer);
	
	heap_push(5, minHeap);
	heap_push(2, minHeap);
	heap_push(4, minHeap);
	heap_push(4, minHeap);
	heap_push(1, minHeap);
	heap_push(6, minHeap);
	heap_push(7, minHeap);
	
	heap_print(minHeap);
	
	heap_pop(minHeap);
	heap_print(minHeap);
	heap_pop(minHeap);
	heap_print(minHeap);
	heap_pop(minHeap);
	heap_print(minHeap);
	
	heap_push(3, minHeap);
	heap_print(minHeap);
	heap_push(9, minHeap);
	heap_print(minHeap);
	
	heap_free(minHeap);
	
	printf("Max Heap Demo\n");
	Heap *maxHeap = heap_create(10, HEAP_MAXIMUM_DEFAULT_VALUE, heap_defaultMaximumHeapComparer);
	
	heap_push(5, maxHeap);
	heap_push(2, maxHeap);
	heap_push(4, maxHeap);
	heap_push(4, maxHeap);
	heap_push(1, maxHeap);
	heap_push(6, maxHeap);
	heap_push(7, maxHeap);
	
	heap_print(maxHeap);
	
	heap_pop(maxHeap);
	heap_print(maxHeap);
	heap_pop(maxHeap);
	heap_print(maxHeap);
	heap_pop(maxHeap);
	heap_print(maxHeap);
	
	heap_push(3, maxHeap);
	heap_print(maxHeap);
	heap_push(9, maxHeap);
	heap_print(maxHeap);
	
	heap_free(maxHeap);
	
	return 0;
}
