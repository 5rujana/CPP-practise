// problem statement: https://www.interviewbit.com/problems/subarray-with-given-xor/
#include<bits/stdc++.h>
using namespace std;

/*

*/
// time complexity : O(nlogn)
// space complexity O(n)
class Solution{
    public:
    int subarrayXorK(vector<int> nums,int k){
        int xr = 0;
        map<int,int> mpp;
        mpp[xr]++; // for storing xr in mpp;
        int cnt = 0;
        for(int i = 0; i<nums.size();i++){
            xr ^= nums[i];
            int m = xr^k;
            cnt += mpp[m];
            mpp[xr]++;
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
        vector<int> nums(n);
        for(int i = 0; i<n;i++){
        cin>> nums[i];
        }
        int k;
        cin>>k;
        Solution sl;
        int ans = sl.subarrayXorK(nums,k);
        cout<< ans<<endl;
    }
    return 0;
}

