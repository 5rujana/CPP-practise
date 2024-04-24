#include<bits/stdc++.h>
using namespace std;

int tsp(vector<vector<int>>& graph, int s , vector<vector<int>>& dp , int mask){
    if(mask == (1<<graph.size())-1)//if all cities has been visited
        return graph[s][0]; //return starting city
    
    if(dp[s][mask]!= -1) //if result is already computes
        return dp[s][mask];
    
    int ans = INT_MAX;
    
    for(int v = 0; v<graph.size();v++){
        if(!mask & (1<<graph.size())){ //if v city is not visited
            int cost = graph[s][v]+tsp(graph,v,dp,mask|(1<<v));
            ans = min(ans,cost);
        }
    }
    return dp[s][mask]=ans;
}
int main() {

    vector<vector<int>> graph = {
        {0, 20, 42, 25},
        {20, 0, 30, 34},
        {42, 30, 0, 10},
        {25, 34, 10, 0}
    };
    int V = graph.size();

    // Initialize memoization table
    vector<vector<int>> dp(V, vector<int>(1 << V, -1));

    int source = 0; // Source vertex

    int minCost = tsp(graph, source, dp, 1 << source); // Start from source vertex

    cout << "Minimum cost for TSP: " << minCost << endl;

    return 0;
}