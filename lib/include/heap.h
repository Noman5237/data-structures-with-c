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
	
	int (*comparer)(int a, int b);
} Heap;

Heap *heap_create(int capacity, int (*comparer)(int a, int b));

void heap_insert(int data, Heap *heap);

int heap_isEmpty(Heap *heap);

int heap_isFull(Heap *heap);

int heap_get(int index, Heap *heap);

int heap_top(Heap *heap);

int heap_search(int data, Heap *heap);

void heap_remove(int index, Heap *heap);

void heap_pop(Heap *heap);

void heap_sort(Heap *heap);

void heap_free(Heap *heap);

/* ============================== UTILITY ========================= */

int heap__leftChildIndex(int parentIndex);

int heap__rightChildIndex(int parentIndex);

int heap__parentIndex(int childIndex);

int heap__hasLeftChild(int parentIndex, int heapSize);

int heap__hasRightChild(int parentIndex, int heapSize);

int heap__hasParent(int childIndex);

int heap__leftChild(int parentIndex, Heap *heap);

int heap__rightChild(int parentIndex, Heap *heap);

int heap__parent(int childIndex, Heap *heap);

void heap__heapifyUp(Heap *heap);

void heap__heapifyDown(Heap *heap);

#endif //DATASTRUCTURESCOURSE_HEAP_H
