#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct queue
{
	int current_size;
	int head;
	int tail;
	int items[MAX_SIZE];
}myQueue;

//Function to check if the queue is empty
int is_empty(myQueue *queue);

//Function to remove of queue
int dequeue(myQueue *queue);

//Function to add to queue
void enqueue(myQueue *queue, int item);

//Function to start the queue
myQueue* start_queue();

int main()
{
	myQueue *queue = start_queue();
	return 0;
}

//Function to start the queue
myQueue* start_queue()
{
	myQueue *new_queue = (myQueue*)malloc(sizeof(myQueue));
	new_queue->current_size = 0;
	new_queue->head = 0;
	new_queue->tail = MAX_SIZE - 1;
	return new_queue;
}

//Function to add to queue
void enqueue(myQueue *queue, int item)
{
	if (queue->current_size >= MAX_SIZE)
	{
		printf("QUEUE OVERFLOW!\n");
	}
	else
	{
		queue->tail = (queue->tail + 1) % MAX_SIZE;
		queue->items[queue->tail] = item;
		queue->current_size++;
	}
}

//Function to remove of queue
int dequeue(myQueue *queue)
{
	if (is_empty(queue))
	{
		printf("QUEUE UNDERFLOW!\n");
		return -1;
	}
	else
	{
		int dequeued = queue->items[queue->head];
		queue->head = (queue->head + 1) % MAX_SIZE;
		queue->current_size--;
		return dequeued;
	}
}

//Function to check if the queue is empty
int is_empty(myQueue *queue)
{
	if (queue->current_size == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}