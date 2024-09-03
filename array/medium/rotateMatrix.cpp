// problem statement: https://leetcode.com/problems/rotate-image/description/

#include<bits\stdc++.h>
using namespace std;


/*
intution: 

Let nums = [
            [1, 2, 3]
            [4, 5, 6]
            [7, 8, 9]
            ]
    step 1) we'll transpose the matrix

    for i = 0
        for j = 0
            next iteration
    for i = 1
        for j = 0
            swap(nums[1][0], nums[0][1])

            =>  [
                [1, 4, 3]
                [2, 5, 6]
                [7, 8, 9]
                ]
        
    for i = 2
        for j = 0
            swap(nums[2][0], nums[0][2])

            =>  [
                [1, 4, 7]
                [2, 5, 6]
                [3, 8, 9]
                ]

        for j = 1
            swap(nums[2][1], nums[1][2])

            =>  [
                [1, 4, 7]
                [2, 5, 8]
                [3, 6, 9]
                ]
        
        end loop

        now well reverse each row
        [
         [7, 4, 1]
         [8, 5, 2]
         [9, 6, 3]
        ]
*/


// time complexity: O(m*n) + O(m)
// space complexity : O(1)
class Solution{
    public:
    void rotateArray(vector<vector<int>> matrix){
        for(int i = 0;i<matrix.size();i++){
            for(int j = 0; j < i ; j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i = 0;i<matrix.size();i++){
             reverse(matrix[i].begin(), matrix[i].end());
        }
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
        sl.rotateArray(nums);
        for(int i = 0; i<n;i++){
            for(int j = 0; i<m;j++){
                cout<< nums[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}