/**
 * @file: heap.c
 * @author: Anonyman637
 * @date: 7/15/2021; 3:16 PM
 */

#include <heap.h>

Heap *heap_create(int capacity, int defaultValue, int (*comparer)(int a, int b)) {
	Heap *heap = malloc(sizeof(Heap));
	heap->capacity = capacity;
	heap->size = 0;
	heap->data = NULL;
	heap->defaultValue = defaultValue;
	heap->compare = comparer;
	
	heap_resize(capacity, heap);
	
	return heap;
}

Heap *heap_createFromArray(int *data, int size, int defaultValue, int (*comparer)(int a, int b)) {
	Heap *heap = heap_create(size, defaultValue, comparer);
	
	memcpy(heap->data, data, sizeof(int) * size / sizeof(char));
	heap->size = size;
	heap_heapify(heap);
	
	return heap;
}

void heap_push(int datum, Heap *heap) {
	if (heap_isFull(heap) && !heap_resize(heap->capacity * 2, heap)) {
		return;
	}
	
	heap->data[heap->size] = datum;
	++heap->size;
	
	heap__heapifyUp(heap);
}

int heap_resize(int newCapacity, Heap *heap) {
	int *newDatum = malloc(newCapacity * sizeof(int));
	if (!newDatum) {
		return false;
	}
	
	if (heap->data) {
		memcpy(newDatum, heap->data, sizeof(int) * heap->capacity / sizeof(char));
		free(heap->data);
	}
	
	heap->data = newDatum;
	heap->capacity = newCapacity;
	
	return true;
}

int heap_isEmpty(Heap *heap) {
	return heap->size == 0;
}

int heap_isFull(Heap *heap) {
	return heap->size == heap->capacity;
}

int heap_isValidIndex(int index, Heap *heap) {
	return index >= 0 && index < heap->size;
}

int heap_get(int index, Heap *heap) {
	return heap->data[index];
}

void heap_swapData(int indexA, int indexB, Heap *heap) {
	int temp = heap_get(indexA, heap);
	heap->data[indexA] = heap_get(indexB, heap);
	heap->data[indexB] = temp;
}

int heap_top(Heap *heap) {
	return heap_get(0, heap);
}

void heap_pop(Heap *heap) {
	if (heap_isEmpty(heap)) {
		return;
	}
	
	--heap->size;
	heap_swapData(0, heap->size, heap);
	
	heap__heapifyDown(0, heap);
}

int * heap_sort(Heap *heap) {
	int *actualHeapData = heap->data;
	int actualHeapSize = heap->size;
	
	int *sortedData = malloc(sizeof(int) * actualHeapSize);
	memcpy(sortedData, actualHeapData, sizeof(int) * actualHeapSize / sizeof(char));
	heap->data = sortedData;
	
	// Operating on sortedData
	for (int i = 0; i < actualHeapSize; i++) {
		heap_pop(heap);
	}
	
	// With popping the sorted order is reversed
	// So we need to reverse once again
	for (int start = 0, end = actualHeapSize - 1; start < end; start++, end--) {
		heap_swapData(start, end, heap);
	}
	
	heap->data = actualHeapData;
	heap->size = actualHeapSize;
	
	return sortedData;
}

void heap_heapify(Heap *heap) {
	for (int parentIndex = heap->size - 1; parentIndex >= 0; parentIndex--) {
		heap__heapifyDown(parentIndex, heap);
	}
}

void heap_free(Heap *heap) {
	free(heap->data);
	free(heap);
}

/* ============================== UTILITY ========================= */

void heap_print(Heap *heap) {
	for (int i = 0; i < heap->size; i++) {
		printf("%d ", heap_get(i, heap));
	}
	printf("\n");
}

void heap__heapifyUp(Heap *heap) {
	int childIndex = heap->size - 1;
	while (heap__hasParent(childIndex) &&
	       heap->compare(heap_get(childIndex, heap), heap__parent(childIndex, heap)) == 1) {
		heap_swapData(childIndex, heap__parentIndex(childIndex), heap);
		childIndex = heap__parentIndex(childIndex);
	}
}

void heap__heapifyDown(int parentIndex, Heap *heap) {
	
	while (heap__hasLeftChild(parentIndex, heap)) {
		int swappedIndex = heap__leftChildIndex(parentIndex);
		if (heap__hasRightChild(parentIndex, heap) &&
		    heap->compare(heap__rightChild(parentIndex, heap), heap_get(swappedIndex, heap)) == 1) {
			swappedIndex = heap__rightChildIndex(parentIndex);
		}
		
		if (heap->compare(heap_get(parentIndex, heap), heap_get(swappedIndex, heap)) == 1) {
			break;
		} else {
			heap_swapData(parentIndex, swappedIndex, heap);
		}
		
		parentIndex = swappedIndex;
	}
}

/* ============================== HELPER ========================= */

int heap__leftChildIndex(int parentIndex) {
	return 2 * parentIndex + 1;
}

int heap__rightChildIndex(int parentIndex) {
	return 2 * parentIndex + 2;
}

int heap__parentIndex(int childIndex) {
	if (childIndex == 0) {
		return -1;
	}
	return (childIndex - 1) / 2;
}

int heap__hasLeftChild(int parentIndex, Heap *heap) {
	return heap__leftChildIndex(parentIndex) < heap->size;
}

int heap__hasRightChild(int parentIndex, Heap *heap) {
	return heap__rightChildIndex(parentIndex) < heap->size;
}

int heap__hasParent(int childIndex) {
	return heap__parentIndex(childIndex) >= 0;
}

int heap__leftChild(int parentIndex, Heap *heap) {
	return heap->data[heap__leftChildIndex(parentIndex)];
}

int heap__rightChild(int parentIndex, Heap *heap) {
	return heap->data[heap__rightChildIndex(parentIndex)];
}

int heap__parent(int childIndex, Heap *heap) {
	return heap->data[heap__parentIndex(childIndex)];
}

/* ============================== DEFAULTS ========================= */

int heap_defaultMinimumHeapComparer(int a, int b) {
	return a < b;
}

int heap_defaultMaximumHeapComparer(int a, int b) {
	return a > b;
}
