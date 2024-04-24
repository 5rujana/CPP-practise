#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int source, destination, weight;
};

class Graph {
public:
    int V, E;
    vector<Edge> edges; // Vector to store edges

    // Constructor to initialize the graph with V vertices and E edges
    Graph(int v, int e) : V(v), E(e) {
        edges.resize(E); // Resize the edges vector to accommodate E edges
    }
};

// Disjoint Set Union (DSU) data structure
class UnionFind {
public:
    vector<int> parent, rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;  // Each element is initially its own root
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);  // Path compression for optimization
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            // Union by rank for optimization
            if (rank[rootX] < rank[rootY])
                parent[rootX] = rootY; // Make root of smaller rank tree point to root of larger rank tree
            else if (rank[rootX] > rank[rootY])
                parent[rootY] = rootX; // Make root of smaller rank tree point to root of larger rank tree
            else {
                parent[rootY] = rootX; // Make one root point to the other root
                rank[rootX]++;
            }
        }
    }
};

// Comparator function to sort edges by weight
bool compEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

void kruskalMST(Graph& graph) {
    sort(graph.edges.begin(), graph.edges.end(), compEdges);
    UnionFind uf(graph.V);
    cout << "Following are the edges in the constructed MST: " << endl;
    for (const Edge& edge : graph.edges) {
        int rootSource = uf.find(edge.source);
        int rootDestination = uf.find(edge.destination);
        if (rootSource != rootDestination) {
            cout << edge.source << " -- " << edge.destination << " == " << edge.weight << endl;
            uf.unite(rootSource, rootDestination);
        }
    }
}

int main() {
    int V, E;
    cout << "Enter the number of vertices in the graph: ";
    cin >> V;
    cout << "Enter the number of edges in the graph: ";
    cin >> E;

    Graph graph(V, E); // Create a graph with V vertices and E edges

    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < E; ++i) {
        cin >> graph.edges[i].source >> graph.edges[i].destination >> graph.edges[i].weight;
    }

    kruskalMST(graph);

    return 0;
}
