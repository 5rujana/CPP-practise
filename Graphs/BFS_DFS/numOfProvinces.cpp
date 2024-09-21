 //problem statement: https://leetcode.com/problems/number-of-provinces/description/
 #include<bits/stdc++.h>
 using namespace std;

/*

time complexity O(N) + O(V+2E)

*/
class Solution{
    private:
    void dfs(int start,vector<int>& visited, vector<int> adj[]){
        visited[start] = 1;
        for(auto it: adj[start]){
            if(!visited[it]){
                dfs(it,visited,adj); // we can even use bfs as well
            }
        }
    }
    public:
    int noOfProvinces(int start,int nodes, vector<int> adj[]){
        vector<int> visited(nodes+1,0);
        int cnt = 0;
        /*
        if adjacency matrix is givem
         vector<int> adjList[n+1];
         for(int i = 0 ; i< nodes;i++){
            for(int j = 0; j< nodes;j++){
                if(adjMatrix[i][j]){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
                }
            }
        }
        
        */
        for(int i = 1 ; i<=nodes;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,visited,adj);
            }
        }
        return cnt;
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

    int provinces = sl.noOfProvinces(start,n,adj);
    cout<<provinces<<endl;
    return 0;

}