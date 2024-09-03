// problem statement: https://leetcode.com/problems/subarray-sum-equals-k/description/

#include<bits/stdc++.h>
using namespace std;

/*
*/
// Space Complexity: O(nlogn)
// Time Complexity: O(n)
class Solution{
    public:
    int subarraySum( vector<int> nums,int k){
    map<int,int> mpp;
    int sum = 0; int cnt = 0;
    for(int i = 0; i<nums.size();i++){
        sum = sum + nums[i];
        int rem = sum - k;
        if(mpp.find(rem)!= mpp.end()){
            cnt+=mpp[rem]; //if multiple sums of rem are available
        }
        mpp[sum]++;
    }
    return cnt;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums;
      
            for(int j = 0; j<n;j++){
                cin>> nums[j];
            }
        int k;
        cin>>k;
        Solution sl;
        int ans = sl.subarraySum(nums,k);
        cout << ans << endl;
    }
    return 0;
}