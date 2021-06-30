from collections import defaultdict

#Class that represents the graph
class Graph:
    def __init__(self, edges, directed=False):
        self.adj = defaultdict(set) # Dictionary that represents the adj. list
        self.directed = directed
        self.add_Edges(edges)       # Method to starts adj. list

    #Returns the vertices of graph as a list
    def get_Vertices(self):
        return list(self.adj.keys())

    #Returns the edges of graph in order
    def get_Edges(self):
        return [(k,v) for k in self.adj.keys() for v in self.adj[k]]

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
    #Defines the method that evaluates
    #the existence of an edge
    def edge_Exists(self, u, v):
        return u in self.adj and v in self.adj[u]

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

    #Defines the method that permits the use of len(graph)
    #instead of len(graph.adj)
    def __len__(self):
        return len(self.adj)

    #Defines the method that formats the string
    #of our graph
    def __str__(self):
        return '{}({})'.format(self.__class__.__name__, dict(self.adj))

    def __getitem__(self, v):
        return self.adj[v]

if __name__ == '__main__':
    edges = [(0, 1), (0, 2), (1, 2),
             (2, 0), (2, 3), (3, 3)]
    graph = Graph(edges, directed=True)
    print(graph.get_Vertices())
    print(graph.get_Edges())
    print(graph.edge_Exists(0, 1), graph.edge_Exists(3,2))
    print(len(graph))
    print("DFS: ")
    graph.DFS()
    print("\nBFS: ")
    graph.BFS(2)