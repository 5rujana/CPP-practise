// problem statement: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/

#include<bits/stdc++.h>
using namespace std;
/*
    intution:
    we'll maintain ans vector where whenever we find negative elements we will add at next odd position available
    and when we encounter positive we will add it to next even index which is available
*/

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution{
    public:
    vector<int> rearrangeArray(vector<int> nums){
        vector<int> ans;
        int posI = 0, negI = 1;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<0){
                ans[negI] = nums[i];
                negI = negI + 2;
            }else{
                ans[posI] = nums[i];
                posI = posI + 2;
            }
        }
        return ans;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i = 0; i<n;i++){
        cin>> nums[i];
        }
        Solution sl;
        vector<int> ans = sl.rearrangeArray(nums);
        for(int i = 0;i<nums.size();i++){
        cout << ans[i] <<" ";
        }
        cout<< endl;
    }
    return 0;
}