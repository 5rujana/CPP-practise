// problem statement: https://leetcode.com/problems/spiral-matrix/description/
#include<bits/stdc++.h>
using namespace std;

/*
*/
// time complexity : O(m*n)
// space complexity : O(m*n)

class Solution{
    public:
    vector<int> spiralOrder(vector<vector<int>> matrix){
        vector<int> ans;
        int top = 0,bottom = matrix[0].size()-1;
        int left = 0,right = matrix.size();
        while(left<=right && top <= bottom){
            for(int i = left ; i<= right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top ; i<= bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            for(int i = right ; i>= left;i--){
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            if(left<=right){
                for(int i = bottom; i>=top;i--){
                ans.push_back(matrix[i][left]);
                }
                left++;
            }

        }
        return ans;
    }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> nums;
        for(int i = 0; i<n;i++){
            for(int j = 0; i<m;j++){
                cin>> nums[i][j];
            }
        }
        Solution sl;
        vector<int> ans = sl.spiralOrder(nums);
        for(int i = 0; i<n;i++){
                cout<< ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}