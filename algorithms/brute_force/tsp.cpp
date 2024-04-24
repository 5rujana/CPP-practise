#include<bits/stdc++.h>
using namespace std;

int min(int a,int b){
    return (a<b)? a:b;
}

int tsp(const vector<vector<int>>& graph, int n, int start , int position,int count,int cost, int &mincost, vector<bool> &visited){
    if(count==n&&graph[position][start]>0){
        mincost = min(mincost,cost+graph[position][start]);
    }

    for(int i = 0; i< n ;i++){
        if(!visited[i]&& graph[position][i]>0){
            visited[i]=true;
            tsp(graph, n, start, i, count + 1, cost + graph[position][i], mincost, visited);
            visited[i]=false; //to backtrack and explore other paths
        }
    }
    return mincost;
}


int main()
{
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    cout << "Enter the cost matrix: ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
    int mincost = INT_MAX;
    vector<bool> visited(n, false);
    visited[0] = true;
    cout << "The minimum cost is: " << tsp(graph, n, 0, 0, 1, 0, mincost, visited);
    return 0;
}
