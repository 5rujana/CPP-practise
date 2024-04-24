#include<bits/stdc++.h>
using namespace std;
/*The transitive closure of a graph tells us which vertices are
reachable from each vertex in the graph, considering all possible paths*/
void warshall(int n, const vector<vector<int>>& graph){
    vector<vector<int>> reach(n,vector<int>(n));
    for(int i =1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            reach[i][j] = graph[i][j];
        }
    }

    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<=n;j++){
                reach[i][j] = reach[i][j] || (reach[i][k]&&reach[k][j]);
            }
        }
    }
    cout << "The transitive closure of the graph is: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << reach[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    vector<vector<int>> graph(n,vector<int>(n));
    cout << "Enter the adjacency matrix of the graph: " << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }
    warshall(n, graph);
    return 0;
}