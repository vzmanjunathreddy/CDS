#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // Define maximum number of vertices

// Structure to represent the graph
typedef struct {
    int num_vertices;
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to initialize the graph
void initialize_graph(Graph *graph, int num_vertices) {
    graph->num_vertices = num_vertices;
    for (int i = 0; i < num_vertices; i++) {
        for (int j = 0; j < num_vertices; j++) {
            graph->adj_matrix[i][j] = 0; // Initialize all entries to 0 (no edges)
        }
    }
}

// Function to add an edge to the graph (undirected graph)
void add_edge(Graph *graph, int u, int v) {
    if (u >= 0 && u < graph->num_vertices && v >= 0 && v < graph->num_vertices) {
        graph->adj_matrix[u][v] = 1; // Set the corresponding entry to 1
        graph->adj_matrix[v][u] = 1; // For undirected graph, also set the reverse entry
    } else {
        printf("Invalid vertex indices.\n");
    }
}

// Function to add an edge to the graph (directed graph)
void add_directed_edge(Graph *graph, int u, int v) {
    if (u >= 0 && u < graph->num_vertices && v >= 0 && v < graph->num_vertices) {
        graph->adj_matrix[u][v] = 1; // Set the corresponding entry to 1
    } else {
        printf("Invalid vertex indices.\n");
    }
}


// Function to print the adjacency matrix
void print_adjacency_matrix(const Graph *graph) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        for (int j = 0; j < graph->num_vertices; j++) {
            printf("%d ", graph->adj_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    
system("cls");
int num_vertices;
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    if (num_vertices <= 0 || num_vertices > MAX_VERTICES) {
        printf("Invalid number of vertices.\n");
        return 1; // Indicate an error
    }

    Graph graph;
    initialize_graph(&graph, num_vertices);

    int num_edges=5;

    printf("Enter the edges (e.g., '0 1' for an edge between vertex 0 and 1):\n");
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&graph, u, v); // For undirected graph
        //add_directed_edge(&graph, u, v); // For directed graph uncomment this and comment above line
    }

    print_adjacency_matrix(&graph);

    return 0;
}