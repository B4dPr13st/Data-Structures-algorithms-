#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct adjacency_list
{
	int item;
	struct adjacency_list *next;
}listAdj;

typedef struct graph
{
	struct adjacency_list *vertices[MAX_SIZE];
	short visited[MAX_SIZE];
}Graph;

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

//Breadth firest search function
void breath_first_search(Graph *Graph, int souce);

//Depth search function 
void depth_first_search(Graph *Graph, int source);

//Adding an edge to the graph
void add_edge(Graph *Graph, int vertex_1, int vertex_2);

//Creating the adj list
listAdj* create_adjacency_list(int item);

//Starting the graph
Graph* start_graph();

int main()
{
	Graph *undirected_graph = start_graph();
	add_edge(undirected_graph, 0, 0);
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

//Starting the graph
Graph* start_graph()
{
	Graph *Graph = (Graph*) malloc(sizeof(Graph));
	int i;
	for (i = 0; i < MAX_SIZE; i++)
	{
		Graph->vertices[i] = NULL;
		Graph->visited[i] = 0;
	}
	return Graph;
}

//Creating the adj list
listAdj* create_adjacency_list(int item)
{
	listAdj *new_list = (listAdj*) malloc(sizeof(listAdj));
	new_list->item = item;
	new_list->next = NULL;
	return new_list;
}

//Adding an edge to the graph
void add_edge(Graph *Graph, int vertex_1, int vertex_2)
{
	listAdj *vertex = create_adjacency_list(vertex_2);
	vertex->next = Graph->vertices[vertex_1];
	Graph->vertices[vertex_1] = vertex;

	//Undirected graph, Edge to another direction as well
	vertex = create_adjacency_list(vertex_1);
	vertex->next = Graph->vertices[vertex_2];
	Graph->vertices[vertex_2] = vertex; 
}

//Depth search function 
void depth_first_search(Graph *Graph, int source)
{
	Graph->visited[source] = 1;
	printf("%d\n", source);

	listAdj *list_access = Graph->vertices[source];

	while (list_access != NULL)
	{
		if (!Graph->visited[list_access->item])
		{
			depth_first_search(Graph, list_access->item);
		}
		list_access = list_access->next;
	}
}

//Breadth firest search function
void breadth_first_search(Graph *Graph, int souce)
{
	myQueue *queue = crete_queue();
	int dequeued;

	Graph->visited[source] = 1;
	enqueue(queue, source);

	while (!is_empty(queue))
	{
		dequeued = dequeue(queue);
		printf("Visited: %d", dequeued)

		listAdj *list_access = Graph->vertices[dequeued];
		while (list_access != NULL)
		{
			if (!Graph->visited[list_access->item])
			{
				printf("%d\n", list_access->item);
				Graph->visited[list_access->item] = 1;
				enqueue(queue, list_access->item);
			}
			list_access = list_access->next;
		}
	}
}