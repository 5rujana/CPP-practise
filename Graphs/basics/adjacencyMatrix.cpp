#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m; //nodes, edges
    cin>>n>>m;
    // adjacency matrix for undirected graph
    int adj[n+1][n+1];
    for(int i = 0; i < m;i++){
        int u,v;
        cin>>u>>v;
        adj[u][v]=1;
        adj[v][u]=1;
        /*
        
        for directed graph
            int u,v;
            cin>>u>>v;
            adj[u][v]=1;

        */
    }
    return 0;
}