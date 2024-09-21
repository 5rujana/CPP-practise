 #include<bits/stdc++.h>
 using namespace std;

class Solution{
    private:
    void dfs(int node, vector<int> adj[],vector<int>& visited,vector<int>& ls){
        visited[node] = 1;
        ls.push_back(node);
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it,adj,visited,ls);
            }
        }
    }
    public:
    vector<int> dfsOfGraph(int start,int nodes,vector<int> adj[]){
        vector<int> visited(nodes,0);
        vector<int> ls;
        dfs(start,adj,visited,ls);
        return ls; 
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

    vector<int> DFS = sl.dfsOfGraph(start,n,adj);
    for(int i = 0; i<DFS.size();i++){
        cout<<DFS[i]<<" ";
    }
    cout<<endl;
    return 0;

}