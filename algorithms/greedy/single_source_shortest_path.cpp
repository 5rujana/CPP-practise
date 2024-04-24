#include<bits/stdc++.h>
using namespace std;

int minDistance(vector<int> dist,vector<bool> sptSet){
    int min = INT_MAX;
    int min_index;
    for(int vertex = 0; vertex < dist.size();vertex++){
        if(!sptSet[vertex]&&dist[vertex]<=min){
            min = dist[vertex];
            min_index = vertex;
        }
    }
    return min_index;
}

void printSol(vector<int>& dist){
    cout<<"Vertex\tDistance from Source"<<endl;
    for(int i = 0; i < dist.size();i++){
        cout<<i<<"\t"<<dist[i]<<endl;
    }
}

void dijkstra(vector<vector<int>>& graph, int src){
    vector<int> dist(graph.size(),INT_MAX);
    vector<bool> sptSet(graph.size(),false);
    dist[src]=0;

    for(int count = 0; count < graph.size()-1;count++){
        int u = minDistance(dist,sptSet);
        sptSet[u]=true;

        for(int v = 0;v<graph.size();v++){
            if(!sptSet[v]&&graph[u][v]&&dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSol(dist);
}

int main() {
    
    cout<<"enter number of vertices : "<<endl;
    int V;
    cin>>V;
    vector<vector<int>> graph(V,vector<int> (V));
    cout << "Enter the adjacency matrix of the graph (" << V << "x" << V << "):\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    // Source vertex
    int src;
    cout << "Enter the source vertex: ";
    cin >> src;

    cout << "Shortest paths from source vertex " << src << ":\n";
    dijkstra(graph, src);

    return 0;
}