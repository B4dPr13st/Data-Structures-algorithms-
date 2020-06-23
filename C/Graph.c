#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 1000

typedef struct adjacence_list
{
	int item;
	struct adjacence_list *next;
}listAdj;

typedef struct graph
{
	struct adjacence_list *vertices[MAX_SIZE];
	short visited[MAX_SIZE];
}graphous;

/*void breath_first_search(graphous *Graph, int souce)
{
	queue *queue = crete_queue();
	int dequeued;
	listAdj *list_access = Graph->vertices[source];
	Graph->visited[source] = 1;
	enqueue(queue, source);

	while (!is_empty(queue))
	{
		dequeued = dequeue(queue);
		list_access = Graph->vertices[dequeued];
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
}*/

//Depth search function 
void depth_first_search(graphous *Graph, int source)
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

//Creating the adj list
listAdj* create_adjacence_list(int item)
{
	listAdj *new_list = (listAdj*) malloc(sizeof(listAdj));
	new_list->item = item;
	new_list->next = NULL;
	return new_list;
}

//Adding an edge to the graph
void add_edge(graphous *Graph, int vertex_1, int vertex_2)
{
	listAdj *vertex = create_adjacence_list(vertex_2);
	vertex->next = Graph->vertices[vertex_1];
	Graph->vertices[vertex_1] = vertex;

	//Undirected graph, Edge to another direction as well
	vertex = create_adjacence_list(vertex_1);
	vertex->next = Graph->vertices[vertex_2];
	Graph->vertices[vertex_2] = vertex; 
}

//Starting the graph
graphous* start_graph()
{
	graphous *Graph = (graphous*) malloc(sizeof(graphous));
	int i;
	for (i = 0; i < MAX_SIZE; i++)
	{
		Graph->vertices[i] = NULL;
		Graph->visited[i] = 0;
	}
	return Graph;
}

int main()
{
	graphous *undirected_graph = start_graph();
	add_edge(undirected_graph, 0, 0);
	return 0;
}