//problem statement: https://leetcode.com/problems/two-sum/description/
#include<bits/stdc++.h>
using namespace std;
/*
    intution: we'll use mpp to track all occured elements and their indices
    Let us suppose nums[2,7,11,15] , target = 9

    for i = 0
        rem = 9-2 = 7 which is not available in mpp
        so mpp = [{2,0}];
    for i = 1
        rem = 9-7 = 2 which is available in mpp at index 0
        so return {0,1}

    end loop
*/

// time complexity: O(nlogn)
// space complexity: O(n)

class Solution{
    public:
    vector<int> twoSum(vector<int> nums,int k){
        map<int,int> mpp;
        for(int i = 0; i< nums.size();i++){
            int rem = k - nums[i];
            if(mpp.find(rem)!=mpp.end()){
                return {mpp[rem],i};
            }
            mpp[nums[i]] = i;
        }
        return {-1,-1};
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
        int k;
        cin>>k;
        Solution sl;
        vector<int> ans = sl.twoSum(nums,k);
        cout << ans[0] << ans[1] << endl;
    }
    return 0;
}