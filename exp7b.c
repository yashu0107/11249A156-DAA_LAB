#include <stdio.h>
#include <stdlib.h>

#define V 4   // Number of vertices
#define E 5   // Number of edges

// Comparator for sorting edges by weight
int comparator(const void *p1, const void *p2) {
    return ((int *)p1)[2] - ((int *)p2)[2];
}

// Initialize parent and rank
void makeSet(int parent[], int rank[]) {
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Find with path compression
int findParent(int parent[], int node) {
    if (parent[node] != node)
        parent[node] = findParent(parent, parent[node]);
    return parent[node];
}

// Union by rank
void unionSet(int u, int v, int parent[], int rank[]) {
    u = findParent(parent, u);
    v = findParent(parent, v);

    if (rank[u] < rank[v]) {
        parent[u] = v;
    } else if (rank[u] > rank[v]) {
        parent[v] = u;
    } else {
        parent[v] = u;
        rank[u]++;
    }
}

// Kruskal Algorithm
int kruskalAlgo(int edges[E][3]) {
    // Sort edges by weight
    qsort(edges, E, sizeof(edges[0]), comparator);

    int parent[V];
    int rank[V];

    makeSet(parent, rank);

    int minCost = 0;

    printf("Edges in MST:\n");

    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        if (findParent(parent, u) != findParent(parent, v)) {
            unionSet(u, v, parent, rank);
            printf("%d - %d : %d\n", u, v, wt);
            minCost += wt;
        }
    }

    return minCost;
}

// Driver code
int main() {
    int edges[E][3] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int cost = kruskalAlgo(edges);
    printf("Minimum Cost: %d\n", cost);

    return 0;
}
