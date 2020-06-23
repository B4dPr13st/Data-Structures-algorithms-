#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 1000

typedef struct _heap
{
	int size;
	int data[MAX_HEAP_SIZE];
}HEAP;

HEAP* create_heap();

int IS_EMPTY(HEAP *heap);

void enqueue(HEAP *heap, int item);

int dequeue(HEAP *heap);

int get_parent_index(HEAP *heap, int i);

int get_left_index(HEAP *heap, int i);

int get_right_index(HEAP *heap, int i);

void max_heapify(HEAP *heap, int i);

int item_of(HEAP *heap, int i);

void heapsort(HEAP *heap);

void swap(int *x, int *y);

int main()
{
	
	return 0;
}

HEAP* create_heap()
{
	HEAP *new_heap = (HEAP*)malloc(sizeof(HEAP));
	new_heap->size = 0;
	int i;
	for (i = 0; i < MAX_HEAP_SIZE; i++)
	{
		new_heap->data[i] = 0;
	}
	return new_heap;
}

int IS_EMPTY(HEAP *heap)
{
	if (heap->size <= 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void swap(int *x, int *y)
{
	int aux = *x;
	*x = *y;
	*y = aux;
}

void heapsort(HEAP *heap)
{
	int i;
	for (i = heap->size; i >= 2; i--)
	{
		swap(&heap->data[1], &heap->data[i]);
		heap->size--;
		max_heapify(heap, 1);
	}
}

void max_heapify(HEAP *heap, int i)
{
	int largest;
	int left_index = get_left_index(heap, i);
	int right_index = get_right_index(heap, i);

	if (left_index <= heap->size && heap->data[left_index] > heap->data[i])
	{
		largest = left_index;
	}
	else
	{
		largest = i;
	}

	if (right_index <= heap->size && heap->data[right_index] > heap->data[largest])
	{
		largest = right_index;
	}

	if (heap->data[i] != heap->data[largest])
	{
		swap(&heap->data[i], &heap->data[largest]);
		max_heapify(heap, largest);
	}
}

int dequeue(HEAP *heap)
{
	if (IS_EMPTY(heap))
	{
		return -1;
	}
	else
	{
		int item = heap->data[1];
		heap->data[1] = heap->data[heap->size];
		heap->size--;
		max_heapify(heap, 1);
		return 1;
	}
}

void enqueue(HEAP *heap, int item)
{
	if (heap->size >= MAX_HEAP_SIZE)
	{
		return;
	}
	else
	{
		heap->data[++heap->size] = item;

		int key_index = heap->size;
		int parent_index = get_parent_index(heap, heap->size);

		while (parent_index >= 1 && heap->data[key_index] > heap->data[parent_index])
		{
			swap(&heap->data[key_index], &heap->data[parent_index]);
			key_index = parent_index;
			parent_index = get_parent_index(heap, key_index);
		}
	}
}

int item_of(HEAP *heap, int i)
{
	return heap->data[i];
}

int get_right_index(HEAP *heap, int i)
{
	return 2 * i + 1;
}

int get_left_index(HEAP *heap, int i)
{
	return 2 * i;
}

int get_parent_index(HEAP *heap, int i)
{
	return i / 2;
}