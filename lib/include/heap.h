/**
 * @file: heap.h
 * @author: Anonyman637
 * @date: 7/15/2021; 3:16 PM
 */

#ifndef DATASTRUCTURESCOURSE_HEAP_H
#define DATASTRUCTURESCOURSE_HEAP_H

#include <dsCommon.h>

typedef struct Heap {
	int capacity;
	int size;
	int *datum;
	int defaultValue;
	
	int (*compare)(int a, int b);
} Heap;

Heap *heap_create(int capacity, int defaultValue, int (*comparer)(int a, int b));

Heap *heap_createFromData(int capacity, int defaultValue, int (*comparer)(int a, int b), int *datum);

void heap_push(int data, Heap *heap);

int heap_resize(int newCapacity, Heap *heap);

int heap_isEmpty(Heap *heap);

int heap_isFull(Heap *heap);

int heap_isValidIndex(int index, Heap *heap);

int heap_get(int index, Heap *heap);

void heap_set(int data, int index, Heap *heap);

void heap_swapData(int indexA, int indexB, Heap *heap);

int heap_top(Heap *heap);

void heap_pop(Heap *heap);

void heap_sort(Heap *heap);

void heap_heapify(Heap *heap);

void heap_free(Heap *heap);

/* ============================== UTILITY ========================= */

void heap_print(Heap *heap);

void heap__heapifyUp(Heap *heap);

void heap__heapifyDown(int parentIndex, Heap *heap);

void heap__initializeWithDefaultValue(int start, int end, Heap *heap);

/* ============================== HELPER ========================= */

int heap__leftChildIndex(int parentIndex);

int heap__rightChildIndex(int parentIndex);

int heap__parentIndex(int childIndex);

int heap__hasLeftChild(int parentIndex, Heap *heap);

int heap__hasRightChild(int parentIndex, Heap *heap);

int heap__hasParent(int childIndex);

int heap__leftChild(int parentIndex, Heap *heap);

int heap__rightChild(int parentIndex, Heap *heap);

int heap__parent(int childIndex, Heap *heap);

/* ============================== DEFAULTS ========================= */

#define HEAP_MINIMUM_DEFAULT_VALUE INT_MAX

#define HEAP_MAXIMUM_DEFAULT_VALUE INT_MIN

int heap_defaultMinimumHeapComparer(int a, int b);

int heap_defaultMaximumHeapComparer(int a, int b);

#endif //DATASTRUCTURESCOURSE_HEAP_H
