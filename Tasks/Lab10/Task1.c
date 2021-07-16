/**
 * @file: Task1.c
 * @author: Anonyman637
 * @date: 7/15/2021; 3:19 PM
 */

#include <heap.h>

int main() {
	
	printf("Min Heap Push Pop Demo\n");
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
	
	printf("Min Heap Sort\n");
	int *sorted = heap_sort(minHeap);
	for (int i = 0; i < minHeap->size; i++) {
		printf("%d ", sorted[i]);
	}
	printf("\n");
	free(sorted);
	
	heap_free(minHeap);
	
	printf("Max Heap Push Pop Demo\n");
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
	
	printf("Max Heap Sort\n");
	sorted = heap_sort(maxHeap);
	for (int i = 0; i < maxHeap->size; i++) {
		printf("%d ", sorted[i]);
	}
	printf("\n");
	free(sorted);
	
	heap_free(maxHeap);
	
	printf("Heapify data from random array\n");
	int datum[20] = {20, 4, 13, 11, 9, 16, 18, 19, 1, 10, 3, 2, 15, 6, 8, 12, 7, 5, 14, 17};
	
	printf("Min Heapify\n");
	Heap *minHeapify = heap_createFromArray(datum, 20, HEAP_MINIMUM_DEFAULT_VALUE, heap_defaultMinimumHeapComparer);
	heap_print(minHeapify);
	
	printf("Heap Resize Demo\n");
	heap_push(0, minHeapify);
	heap_push(0, minHeapify);
	heap_print(minHeapify);
	
	printf("Max Heapify\n");
	Heap *maxHeapify = heap_createFromArray(datum, 20, HEAP_MAXIMUM_DEFAULT_VALUE, heap_defaultMaximumHeapComparer);
	heap_print(maxHeapify);
	
	printf("Heap Resize Demo\n");
	heap_push(40, maxHeapify);
	heap_push(41, maxHeapify);
	heap_print(maxHeapify);
	
	heap_free(minHeapify);
	heap_free(maxHeapify);
	
	return 0;
}
