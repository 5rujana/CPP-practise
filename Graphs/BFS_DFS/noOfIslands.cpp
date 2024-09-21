// problem statement: https://leetcode.com/problems/number-of-islands/description/

#include<bits/stdc++.h>
using namespace std;
class Solution{
    private:
    void bfs(int startI, int startJ, vector<vector<int>>& visited, vector<vector<int>> adj){
        visited[startI][startJ] = 1;
        queue<pair<int,int>> q;
        q.push({startI,startJ});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            vector<pair<int,int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
            for(auto dir: directions){
                int neighbourRow = row + dir.first;
                int neighbourCol = col + dir.second;
                if(neighbourRow>= 0 && neighbourRow < adj.size()
                && neighbourCol>=0 && neighbourCol<adj[0].size()
                && !visited[neighbourRow][neighbourCol] && adj[neighbourRow][neighbourCol]){
                    visited[neighbourRow][neighbourCol] = 1;
                    q.push({neighbourRow,neighbourCol});
                }

            }
        }     
    }

    public:
    int noOfIslands(vector<vector<int>> adj){
        vector<vector<int>> visited(adj.size(), vector<int>(adj[0].size(),0));
        int cnt = 0;
        for(int i = 0; i< adj.size();i++){
            for(int j = 0; j < adj[0].size();j++){
                if(!visited[i][j] && adj[i][j]=='1'){
                    bfs(i,j,visited,adj);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

 int main(){
    Solution sl;
    int n,start;
    cin>>n>>start;
    vector<vector<int>> adj(n,vector<int>(n));
    for(int i = 0; i<n;i++){
        for(int j = 0; j<n;j++){
            adj[i][j];
        }
    }

    int provinces = sl.noOfIslands(adj);
    cout<<provinces<<endl;
    return 0;

}