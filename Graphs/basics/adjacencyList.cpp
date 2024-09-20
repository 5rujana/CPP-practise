/*

Let input be
1 2
1 3
2 4
3 4
3 5
4 5

then adjacency List is
0 -> {}
1 -> {2,3}
2 -> {1,4}
3 -> {1,4,5}
4 -> {2,3,5}
5 -> {3,4}

*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i = 0; i<m;i++){
        int u,v;
        cin>>u>>v;
        // for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
        // for directed graph
        // adj[u].push_back(v); as u -> v
    }
    return 0;
}