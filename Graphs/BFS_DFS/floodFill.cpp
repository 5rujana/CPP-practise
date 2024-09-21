//problem statement: https://leetcode.com/problems/flood-fill/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int startI, int startJ, vector<vector<int>>& visited, vector<vector<int>>& adj, int color, int originalColor) {
        visited[startI][startJ] = 1;
        adj[startI][startJ] = color;
        queue<pair<int, int>> q;
        q.push({startI, startJ});

        // Directions: Up, Down, Left, Right
        vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (auto dir : directions) {
                int neighbourRow = row + dir.first;
                int neighbourCol = col + dir.second;

                if (neighbourRow >= 0 && neighbourRow < adj.size() &&
                    neighbourCol >= 0 && neighbourCol < adj[0].size() &&
                    !visited[neighbourRow][neighbourCol] && adj[neighbourRow][neighbourCol] == originalColor) {

                    visited[neighbourRow][neighbourCol] = 1;
                    q.push({neighbourRow, neighbourCol});
                    adj[neighbourRow][neighbourCol] = color;
                }
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor == color) {
            return image; 
        }
        
        vector<vector<int>> visited(image.size(), vector<int>(image[0].size(), 0));
        bfs(sr, sc, visited, image, color, originalColor);
        return image;
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
    int sr,sc,color;
    cin>> sr>>sc>> color;
    vector<vector<int>> flood = sl.floodFill(adj,sr,sc,color);
    for(int i = 0; i< flood.size();i++){
        for(int j = 0; j < flood[i].size();j++){
            cout<<flood[i][j]<< " ";
        }
        cout<<endl;
    }

    return 0;

}