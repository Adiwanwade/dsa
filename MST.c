#include <stdio.h>
#include <stdlib.h>

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edges;
};

// Function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edges = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// Function to compare two edges based on their weights
int compareEdges(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// Function to find the parent of a vertex in the disjoint set
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Function to perform union of two subsets
void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
void KruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;  // An index variable, used for result[]

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(graph->edges, graph->E, sizeof(graph->edges[0]), compareEdges);

    // Allocate memory for creating V subsets
    int* parent = (int*)malloc(V * sizeof(int));

    // Initialize all subsets as single element sets
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && graph->E > 0) {
        // Step 2: Pick the smallest edge, and increment the index for next iteration
        struct Edge next_edge = graph->edges[graph->E - 1];
        graph->E--;

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        // If including this edge does not cause a cycle, add it to the result and
        // increment the index of result for the next edge
        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }

    // Print the edges of the MST
    printf("Edges in the minimum spanning tree:\n");
    for (int i = 0; i < e; i++) {
        printf("(%d, %d) -> %d\n", result[i].src, result[i].dest, result[i].weight);
    }

    free(parent);
}

int main() {
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges
    struct Graph* graph = createGraph(V, E);

    // Edge 0-1
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    // Edge 0-2
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    // Edge 0-3
    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    // Edge 1-3
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    // Edge 2-3
    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    KruskalMST(graph);

    // Free allocated memory
    free(graph->edges);
    free(graph);

    return 0;
}
