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
	heap->datum = NULL;
	heap->defaultValue = defaultValue;
	heap->compare = comparer;
	
	heap_resize(capacity, heap);
	
	return heap;
}

Heap *heap_createFromData(int capacity, int defaultValue, int (*comparer)(int a, int b), int *datum) {
	Heap *heap = heap_create(capacity, defaultValue, comparer);
	
	for (int i = 0; i < capacity; i++) {
		heap->datum[i] = datum[i];
	}
	
	heap_heapify(heap);
	
	return heap;
}

void heap_push(int data, Heap *heap) {
	if (heap_isFull(heap) && !heap_resize(heap->capacity * 2, heap)) {
		return;
	}
	
	++heap->size;
	heap_set(data, heap->size - 1, heap);
	
	heap__heapifyUp(heap);
}

int heap_resize(int newCapacity, Heap *heap) {
	int *newDatum = malloc(newCapacity * sizeof(int));
	if (!newDatum) {
		return false;
	}
	
	if (heap->datum) {
		memcpy(newDatum, heap->datum, sizeof(int) * heap->capacity / sizeof(char));
		free(heap->datum);
	}
	
	heap->datum = newDatum;
	heap->capacity = newCapacity;
	heap__initializeWithDefaultValue(heap->size, heap->capacity, heap);
	
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
	return heap->datum[index];
}

void heap_set(int data, int index, Heap *heap) {
	if (!heap_isValidIndex(index, heap)) {
		return;
	}
	
	heap->datum[index] = data;
}

void heap_swapData(int indexA, int indexB, Heap *heap) {
	int temp = heap_get(indexA, heap);
	heap_set(heap_get(indexB, heap), indexA, heap);
	heap_set(temp, indexB, heap);
}

int heap_top(Heap *heap) {
	return heap_get(0, heap);
}

void heap_pop(Heap *heap) {
	if (heap_isEmpty(heap)) {
		return;
	}
	
	heap_swapData(0, heap->size - 1, heap);
	--heap->size;
	
	heap__heapifyDown(0, heap);
}

void heap_sort(Heap *heap) {
	int heapSize = heap->size;
	for (int i = 0; i < heapSize; i++) {
		heap_pop(heap);
	}
	heap->size = heapSize;
}

void heap_heapify(Heap *heap) {
	for (int parentIndex = heap->size - 1; parentIndex >= 0; parentIndex--) {
		heap__heapifyDown(parentIndex, heap);
	}
}

void heap_free(Heap *heap) {
	free(heap->datum);
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

void heap__initializeWithDefaultValue(int start, int end, Heap *heap) {
	for (int i = start; i < end; i++) {
		heap->datum[i] = heap->defaultValue;
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
	return heap->datum[heap__leftChildIndex(parentIndex)];
}

int heap__rightChild(int parentIndex, Heap *heap) {
	return heap->datum[heap__rightChildIndex(parentIndex)];
}

int heap__parent(int childIndex, Heap *heap) {
	return heap->datum[heap__parentIndex(childIndex)];
}

/* ============================== DEFAULTS ========================= */

int heap_defaultMinimumHeapComparer(int a, int b) {
	return a < b;
}

int heap_defaultMaximumHeapComparer(int a, int b) {
	return a > b;
}
