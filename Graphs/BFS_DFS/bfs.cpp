// breadth first search

#include<bits/stdc++.h>
using namespace std;


/*space complexity : O(N) as the while loop is gonna visit all the nodes 
    + O(2E) -> degree of all edges = 2E.. the inner for loop runs for degrees of each adn every node so it's 2E
*/
class Solution{
    public:
    vector<int> bfsOfGraph(int start ,int nodes , vector<int> adj[]){
        vector<int> visited(nodes+1,0);
        visited[start] = 1;
        queue<int> q;
        q.push(start);
        vector<int> bfs;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for( auto it : adj[node]){
                if(!visited[it]){
                    q.push(it);
                    visited[it] = 1;
                }
            }
        }
        return bfs;
    }
};

int main(){
    Solution sl;
    int n,m,start;
    cin>>n>>m>>start;
    vector<int> adj[n+1];
    for(int i = 0; i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> BFS = sl.bfsOfGraph(start,n,adj);
    for(int i = 0; i<BFS.size();i++){
        cout<<BFS[i]<<" ";
    }
    cout<<endl;
    return 0;

}