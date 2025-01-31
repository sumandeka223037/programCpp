#include <iostream>
#include <algorithm>
#include<time.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

// Function to find the parent of a node in the disjoint set
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// Function to perform union of two subsets
void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    if (xset != yset) {
        parent[xset] = yset;
    }
}

// Comparator function to sort edges by their weight
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to implement Kruskal's Algorithm
void kruskalMST(Edge edges[], int V, int E) {
    // Sort edges based on their weight
    sort(edges, edges + E, compare);

    int parent[V];
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    cout << "Edge \tWeight\n";

    for (int i = 0; i < E; i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;
        int weight = edges[i].weight;

        // Find the sets of the source and destination vertices
        int x = find(parent, src);
        int y = find(parent, dest);

        // If they are in different sets, include this edge in the MST
        if (x != y) {
            cout << src << " - " << dest << "\t" << weight << endl;
            unionSets(parent, x, y);
        }
    }
}

int main() {
    clock_t start,end;
    start=-clock();
    int V = 4; // Number of vertices in the graph
    int E = 5; // Number of edges in the graph
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskalMST(edges, V, E); 
    end=clock();
    float clk=end-start;
    cout<<"Time taken: "<<clk/CLOCKS_PER_SEC<<endl;
    return 0;
}
