/**
 * @file: heap.c
 * @author: Anonyman637
 * @date: 7/15/2021; 3:16 PM
 */

#include <heap.h>

Heap *heap_create(int capacity, int (*comparer)(int a, int b)) {
	Heap *heap = malloc(sizeof(Heap));
	heap->capacity = capacity;
	heap->size = 0;
	heap->datum = malloc(sizeof(int) * capacity);
	heap->comparer = comparer;
	return heap;
}

void heap_insert(int data, Heap *heap) {
	if (heap->size == heap->capacity) {
		return;
	}
	
	heap->datum[heap->size] = data;
	++heap->size;
	
}

int heap_isEmpty(Heap *heap) {
	return heap->size == 0;
}

int heap_isFull(Heap *heap) {
	return heap->size == heap->capacity;
}

int heap_get(int index, Heap *heap) {
	return heap->datum[index];
}

int heap_top(Heap *heap) {
	return heap_get(0, heap);
}

int heap_search(int data, Heap *heap) {}

void heap_remove(int index, Heap *heap) {}

void heap_pop(Heap *heap) {
	heap_remove(0, heap);
}

void heap_sort(Heap *heap) {}

void heap_free(Heap *heap) {
	free(heap->datum);
	free(heap);
}

/* ============================== UTILITY ========================= */

int heap__leftChildIndex(int parentIndex) {
	return 2 * parentIndex + 1;
}

int heap__rightChildIndex(int parentIndex) {
	return 2 * parentIndex + 2;
}

int heap__parentIndex(int childIndex) {
	return (childIndex - 2) / 2;
}

int heap__hasLeftChild(int parentIndex, int heapSize) {
	return heap__leftChildIndex(parentIndex) < heapSize;
}

int heap__hasRightChild(int parentIndex, int heapSize) {
	return heap__rightChildIndex(parentIndex) < heapSize;
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
