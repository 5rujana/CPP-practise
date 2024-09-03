// problem statement: https://leetcode.com/problems/set-matrix-zeroes/description/

#include<bits/stdc++.h>
using namespace std;

/*
intution:

bruteforce: we'll mark rows and elems as -1 where the element is found 0
and then changing -1 to 0's
time complexity: O(n*m)*(n+m)+(n*m)


better approach: we'll maintain col[] and row[] we'll store 1 in that row and col when we find element 0
space Complexity: O(m+n)

optimal approach:
col[m] -> matrix[0][i] && row[n] -> col[j][0]

Let nums = [
            [ 1 , 1 , 1 , 1]
            [ 1 , 0 , 0 , 1]
            [ 1 , 1 , 0 , 1]
            [ 1 , 1 , 1 , 1]
            ]

            nums = [
            ______________________
            colO                 |
            _______              | -> row [] in better approach
            [| 1 |, |1 , 1 , 1]  |
                    |___________|
            [| 1 |, 0 , 0 , 1]
            [| 1 |, 1 , 0 , 1]
            [| 1 |, 1 , 1 , 1]
            ] col

            in first loop well mark col[] => nums[i][0], where ever we find the zero
            and while marking row[] => nums[0][j] we'll maark all nums[0][j] whenevr we find zero except nums[0][0] instead of that wew'll change ColO as 0


            now in second for loop traversing from second row and second col, for non zero elems => nums[i][j] !=0
            we need to check if the corresponding col[]=> nums[i][0] and row[]=> nums[0][j] is zero
            if any of them are zero then arr[i][j] = 0

            now we'll update row[] if nums[0][0] = 0
            and we'll update col[] if colO = 0


*/

// time complexity: O(n*m)
// space complexity: O(1)
class Solution{
    public:
    void setMatrixZeros(vector<vector<int>> nums){
        int colO = 1;
        for(int i = 0;i<nums.size();i++){
            for(int j = 0 ; j < nums[0].size();j++){
               nums[i][0] = 0; // marking row []
               if( j!= 0){
                nums[0][j]=0;
               }else{
                colO = 0;
               }
            }
        }

        for(int i = 1; i<nums.size();i++){
            for (int j = 1; j < nums[0].size(); j++) {
            if (nums[i][j] != 0) {

                if (nums[i][0] == 0 || nums[0][j] == 0) {
                    nums[i][j] = 0;
                }
            }
        }

        if (nums[0][0] == 0) {
            for (int j = 0; j < nums[0].size(); j++) {
            nums[0][j] = 0;
            }
        }

        if (colO == 0) {
            for (int i = 0; i < nums.size(); i++) {
                nums[i][0] = 0;
            }
        }
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
        sl.setMatrixZeros(nums);
        for(int i = 0; i<n;i++){
            for(int j = 0; i<m;j++){
                cout<< nums[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}