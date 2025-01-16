#include <stdio.h>
#include <stdlib.h>

#define SIZE 40

// Queue structure for BFS
// Image url reference https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/?ref=lbp
struct queue {
    int items[SIZE];
    int front;
    int rear;
};

// Node structure for adjacency list
struct node {
    int vertex;
    struct node* next;
};

// Graph structure
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

// Function to create a queue
struct queue* createQueue() {
    struct queue* q = malloc(sizeof(struct queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

// Function to check if the queue is empty
int isEmpty(struct queue* q) {
    return q->rear == -1;
}

// Function to enqueue an item to the queue
void enqueue(struct queue* q, int value) {
    if (q->rear == SIZE - 1) {
        printf("\nQueue is Full!!\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}

// Function to dequeue an item from the queue
int dequeue(struct queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}

// BFS algorithm using a queue
void bfs(struct Graph* graph, int startVertex) {
    struct queue* q = createQueue();

    // Mark the start vertex as visited and enqueue it
    graph->visited[startVertex] = 1;
    enqueue(q, startVertex);

    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("Visited %d\n", currentVertex);

        struct node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;

            // If the adjacent vertex hasn't been visited, mark it and enqueue
            if (graph->visited[adjVertex] == 0) {
                graph->visited[adjVertex] = 1;
                enqueue(q, adjVertex);
            }
            temp = temp->next;
        }
    }
}

// Driver function to test the BFS
int main() {

    system("cls");
    struct Graph* graph = createGraph(6);

    // Adding edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 4);

    // Print the graph's adjacency list before applying BFS
    printf("Graph with edges (Adjacency List):\n");
    printGraph(graph);

    // Start BFS from vertex 0
    printf("\nBFS starting from vertex 0:\n");
    //bfs(graph, 0);
    bfs(graph, 2);

    return 0;
}
