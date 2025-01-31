#include <iostream>
#include <limits.h>
#include<time.h>
using namespace std;
#define V 5 // Number of vertices in the graph
// Function to find the vertex with the minimum key value
int minKey(int key[], bool included[]) {
    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++) {
        if (!included[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to implement Prim's Algorithm
void primMST(int graph[V][V]) {
    int parent[V]; // Array to store the resulting MST
    int key[V];   
    bool included[V]; 

    // Initialize all keys as infinite and included as false
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        included[i] = false;
    }

    key[0] = 0; 
    parent[0] = -1; 

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, included);
        included[u] = true; 

        // Update key and parent index of the adjacent vertices
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !included[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Print the constructed MST
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    clock_t start,end;
    start=clock();
    int graph[V][V] = {
        {1, 2, 0, 5, 0},
        {1, 0, 4, 8, 6},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph); 
    end=clock();
    float clk= end-start;
    cout<<"Time taken: "<<clk/CLOCKS_PER_SEC<<endl;
    return 0;
}