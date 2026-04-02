#include <stdio.h>
#include <limits.h>

#define V 6   // Number of vertices
#define E 7   // Number of edges

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Function to run Bellman-Ford algorithm
void bellmanFord(struct Edge edges[], int source) {
    int distance[V];

    // Step 1: Initialize distances
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;

    distance[source] = 0;

    // Step 2: Relax all edges (V-1 times)
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Step 3: Check for negative weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            printf("Graph contains negative weight cycle\n");
            return;
        }
    }

    // Step 4: Print result
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++) {
        if (distance[i] == INT_MAX)
            printf("%d\tINF\n", i);
        else
            printf("%d\t%d\n", i, distance[i]);
    }
}

int main() {
    // Edge list representation
    struct Edge edges[E] = {
        {0, 1, 10},
        {0, 3, 15},
        {1, 3, 5},
        {1, 4, 10},
        {2, 5, 10},
        {3, 5, 5},
        {4, 5, 10}
    };

    bellmanFord(edges, 0);

    return 0;
}
