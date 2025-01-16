#include <stdio.h>
#include <stdlib.h>

struct node {
    int vertex;
    struct node* next;
};

struct Graph {
    int numVertices;
    struct node** adjLists;
    int* visited;
};

// Function to create a new node for adjacency list
struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with the specified number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct node*));
    graph->visited = malloc(vertices * sizeof(int));

    // Initialize all adjacency lists as NULL
    // and visited array to 0 (not visited)
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

// Function to add an edge to the graph (undirected graph)
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src (because it's undirected)
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// Function to print the graph's adjacency list representation
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct node* temp = graph->adjLists[i];
        printf("%d-->", i);  // Print the current vertex
        while (temp) {
            printf("%d-->", temp->vertex);  // Print the adjacent vertex
            temp = temp->next;
        }
        printf("NULL\n");  // End of the adjacency list for the current vertex
    }
}

// DFS algorithm using recursion
void dfs(struct Graph* graph, int vertex) {
    // Mark the current vertex as visited
    graph->visited[vertex] = 1;
    printf("Visited %d\n", vertex);

    // Recur for all the vertices adjacent to this vertex
    struct node* adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        int adjVertex = adjList->vertex;

        // If the adjacent vertex hasn't been visited, visit it
        if (graph->visited[adjVertex] == 0) {
            dfs(graph, adjVertex);
        }
        adjList = adjList->next;
    }
}

// Driver function to test the DFS
int main() {
    struct Graph* graph = createGraph(6);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Print the graph's adjacency list before applying DFS
    printf("Graph with edges (Adjacency List):\n");
    printGraph(graph);

    // Start DFS from vertex 0
    printf("\nDFS starting from vertex 0:\n");
    dfs(graph, 0);

    return 0;
}
