# Graphs 

![](https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/figs/Sedgewick-Wayne/TinyNetworkOnly.png)

A **Graph** is an abstract data type used to functionally implement the mathematical concepts of
**Undirected Graphs** and **Directed Graphs**.

## Definition

A **Graph** is a finite pair of sets, formed by **Vertices** and **Edges**, 
we can write a **Graph** as: 
```
G = (V, E)
```

**Graphs** are important because of their applications to modeling 
problems in mathematics, engineering, computing, biology, etc.

As a **Data Structure**, a **Graph** can be:

- Directed Graph
- Undirected Graph
- Weighted Graph
- Binary Search Trees

A **Directed Graph** is a representation of this model where 
**navigation/search** can only be done in one direction.

In a **Undirected Graph** the **navigation/search** 
can be done in both directions.

In a **Weighted Graph** the **Edges** have a value assigned to them, called **Weight**, which, depending on
the application/implementation, will be treated differently,
but **browsing and searching** can be done in both or in only one direction,
as **Weighted Graphs** can also be **Directed Graphs** or not.

Some examples of applications of **Graphs** for modeling problems and implementing features are:

- **Air transport** (Object: cities, Relationship: commercial flight between two cities)
- **Web** (Object: web pages, Relationship: link from one page to another)
- **Couples in a relationship** (Object: boys and girls, Relationship: mutual interest in going out)
- **Robustez da malha elétrica** (Objeto: torres de transmissão, Relacionamento: linhas entre torres)
- **Social Networks** (Object: profiles, Relationship: people connected directly or indirectly)
- **Network Topology** (Object: connected hosts, Relationship: routers and/or switches that connect them, 
  as well as mobile network servers and/or towers)

## Abstract Data Type

The use of **Graphs** as data structures makes us have to store additional information, in addition to the
data itself, and this information is the 
relationship between two **Vertices**, the **Edge** that connects them .

We can store this relationship information in two ways:

- Adjacency List: A list that stores the **Edges** of a given **Vertex** and which others they are linked.
  
For example: 
```python
a[2] = [3,4,5] 
```

In this example, the **Vertex** 2 is linked to **Vertices** 3, 4 and 5.

- Adjacency Matrix: In an adjacency matrix, the relations are stored in a binary way, where the **row** and
  **column** of the matrix, **i** and **j**,
  represent the **Vertices** and the position accessed in this way 
  stores a binary value, 0 or 1, indicating whether certain **Vertices** 
  are connected by an **Edge** or not.
  
For example:

```c
a[2][3] = 1
```

In this example, the adjacency matrix is ​​representing an existing connection
between **Vertices** 2 and 3.

We have to take this into account when implementing our structure.

The implementation in **C** has the use of adjacency list, while the implementation in **Python** has
the use of a dictionary to store the **Edges**.

**C ADT** Example:
```C
//Struct of Adj. List
struct adjacence_list
{
	int item;
	struct adjacence_list *next;
};

//Struct of our Graph
struct graph
{
	struct adjacency_list *vertices[MAX_SIZE];
	short visited[MAX_SIZE];
}
```

**Python ADT** Example:
```Python
#Class that represents the graph
class Graph:
    def __init__(self, edges, directed=False):
        self.adj = defaultdict(set) # Dictionary that represents the adj. list
        self.directed = directed
        self.add_Edges(edges)       # Method to starts adj. list
```

## Implementation of Graphs

**Graphs** can perform **Insert**, **Remove** and **Search** operations, as well as the other structures.

However, navigation in **Graphs** works differently from other structures, to perform the **Search** in graphs we
will use algorithms designed for this, which may
change depending on the arrangement of the **Vertices** in the **Graph**

The main algorithms shown here will be **Depth First Search(DFS)** and **Breadth First Search(BFS)**

#### Insertion

When we are **Inserting** in a **Graph** we must specify the **Vertices** and the **Edges**.

**C** Example:
```C
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
```

**Python** Example:
```Python
#Method to call the new link insertion
def add_Edges(self, edges):
    for u, v in edges:
        self.add_Link(u,v)

#Method that inserts a new edge
#between two vertices
def add_Link(self, u, v):
    self.adj[u].add(v)
    if not self.directed:  # If the graph is not directed
        self.adj[v].add(u) # then we have to add edges on
                           # both directions
```

#### Remove

Removal in **Graphs** will generally be logical, but you always have to take into account the case of removing a **Vertex** that
mediates the indirect link between 2 other **Vertices**.

#### Search

As mentioned before, the search will be done using one of the two algorithms **BFS** or **DFS**.

#### BFS

The **Breadth** search starts at a **Vertex**, say s, specified by the user. The algorithm visits s, then visits all 
neighbors of s, then all **neighbors** of **neighbors**, and so on.

The algorithm numbers the **Vertices**, in sequence, in the order in which they are discovered (that is, visited 
for the first time). To do this, the algorithm uses a 
**Queue** of **Vertices**. At the beginning of each iteration, the queue contains
**Vertices** that have already been numbered but have unnumbered **neighbors**.

The following pseudocode represents an idea of ​​how the algorithm should work:
```
while queue is not empty
  remove a vertex v from the queue
  for each neighbor w of v
    if w is not numbered
      so number w
        put w in the queue
```

**C** Example:
```C
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
```

**Python** Example:
```Python
#Method that runs Breadth First Search
#algorithm
def BFS(self, v):
    visited = [False] * (max(self.adj) + 1)

    queue = []

    queue.append(v)
    visited[v] = True

    while queue:
        v = queue.pop(0)
        print(v, end=' ')

        for i in self.adj[v]:
            if visited[i] == False:
                queue.append(i)
                visited[i] = True
```

#### DFS

The **DFS** search algorithm visits all the **Vertices** 
and all the arcs of the **Graph** in a certain order and
assigns a number to each **Vertex**: the **K**th 
discovered **Vertex** receives the number **K** .

The only catch here is, unlike trees, **Graphs**
may contain cycles, a **node** may be visited twice. 

The following pseudocode represents an idea of ​​how the algorithm should work:
```
DFS(G,v)   ( v is the vertex where the search starts )
         Stack S := {};   ( start with an empty stack )
         for each vertex u, set visited[u] := false;
         push S, v;
         while (S is not empty) do
            u := pop S;
            if (not visited[u]) then
               visited[u] := true;
               for each unvisited neighbour w of u
                  push S, w;
            end if
         end while
      END DFS()
```

**C** Example:
```C
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
```

**Python** Example:
```Python
#Auxiliar DFS method
def DFSUtil(self, v, visited):
    visited.add(v)
    print(v, end=' ')

    for neighbour in self.adj[v]:
        if neighbour not in visited:
            self.DFSUtil(neighbour,visited)

#Method that runs the Depth First Search
#algorithm
def DFS(self):
    visited = set()

    for vertex in list(self.adj):
        if vertex not in visited:
            self.DFSUtil(vertex, visited)
```

## Complexity analysis and comparisons

Time to make comparisons and final considerations.

The complexity analysis is given in big O notation.

### Adjacency list

In **Graphs** with the use of adjacency lists, 
**Insertion** of **Vertices** and **Edges** has O(1) complexity.

The removal of **Vertices** and **Edges** has a complexity
of O(|V| * |E|) when removing a **Vertex** and O(|E|) when removing a **Edge**.

Storage in **Graphs** of this type also has O(|V| * |E|).

### Adjacency Matrix

In **Graphs** with the use of adjacency matrices, 
**Insertion** of **Vertices** has O(|V| ^ 2) complexity and O(1) when removing a **Edge**.

The removal of **Vertices** and **Edges** has a complexity
of O(|V| ^ 2) when removing a **Vertex** and O(1) when removing a **Edge**.

Storage in **Graphs** of this type also has O(|V| ^ 2).

### Depth First Search

- **Time complexity**: O(V + E), where V is the number of **Vertices** and E is the number of **Edges** in the **Graph**.
- **Space Complexity**: O(V). 
Since an extra visited array is needed of size V.
  
### Breadth First Search

- **Time Complexity**: O(V+E) where V is number of **Vertices** in the **Graph** and E is number of **Edges** in the **Graph**.

## Finishing

This was a short summary and demonstration of implementing Graphs, I hope you enjoyed it! :D

Good luck with your studies!

![](https://media.giphy.com/media/2UeFarpIBcDlu/giphy.gif)

## References

[Graphs in Python](https://algoritmosempython.com.br/cursos/algoritmos-python/algoritmos-grafos/representacao-grafos/) <br>
[Breadth First Search and Big O - Python](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/) <br>
[Depth First Search and Big O - Python](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/) <br>
[Breadth First Search - C](https://www.programiz.com/dsa/graph-bfs) <br>
[Depth First Search - C](https://www.programiz.com/dsa/graph-dfs) <br>
[BFS - Theory](https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/bfs.html) <br>
[DFS - Theory](https://www.ime.usp.br/~pf/algoritmos_para_grafos/aulas/dfs.html) <br>
[DFS Pseudocode](http://www.cs.toronto.edu/~heap/270F02/node36.html) <br>
[Big O Graph Operations](https://www.hackerearth.com/practice/notes/big-o-cheatsheet-series-data-structures-and-algorithms-with-thier-complexities-1/) <br>
[Graph Applications](Graph Applications)