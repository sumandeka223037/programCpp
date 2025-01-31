#include <iostream>
#include <vector>
#include <climits>  
#include <queue>
#include<time.h>    
using namespace std;
struct Edge {
    int destination;
    int weight;
};
class Graph {
public:
    int V;  
    vector<vector<Edge>> adjList; 

    Graph(int vertices) {
        V = vertices;
        adjList.resize(vertices);
    }
    void add(int u, int v, int w) {
        adjList[u].push_back(Edge{v, w});
        adjList[v].push_back(Edge{u, w});  
    }
    void dijkstra_Main(int source) {
        vector<int> dist(V, INT_MAX);
        dist[source] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, source}); 
        while (!pq.empty()) {
            int u = pq.top().second;  // Get the vertex with the smallest distance
            int distance = pq.top().first;
            pq.pop();

            if (distance > dist[u]) {
                continue;
            }
            for (const Edge &e : adjList[u]) {
                int v = e.destination;
                int weight = e.weight;

                // Relaxation: if a shorter path is found, update the distance
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v}); 
                }
            }
        }
        cout << "Shortest distances from node " << source << ":\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX) {
                cout << "Node " << i << " is unreachable\n";
            } else {
                cout << "Node " << i << ": " << dist[i] << "\n";
            }
        }
    }
};

int main() {
    clock_t start,end;
    start=clock();
    int vertices, edges;
    cout << "Enter number of vertices: ";
    cin >> vertices;
    cout << "Enter number of edges: ";
    cin >> edges;
    Graph g(vertices);
    cout << "Enter each edge in the format (u v w), where u and v are vertices and w is the weight:\n";
    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.add(u, v, w);
    }
    int source;
    cout << "Enter the source node: ";
    cin >> source;
    // Perform Dijkstra's algorithm to find shortest paths
    g.dijkstra_Main(source);
    end=clock();
    float clk=end-start;
    cout<<"THE TIME TAKEN IS: "<<clk/CLOCKS_PER_SEC<<endl;

    return 0;
}

 

 
