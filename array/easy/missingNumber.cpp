// problem statement : https://leetcode.com/problems/missing-number/description/
#include<bits/stdc++.h>
using namespace std;

// intution: missing element = diff of (sum of num from 1-n and sum of all elems of arr)
// Time Complexity = O(N)
// Space Complexity = O(1)
class Solution{
    public:
    int missingNumber(vector<int> nums){
        int n = nums.size();
        int Sn = (n)*(n-1)/2;
        int Sarr = 0;
        for(int i = 0; i<n;i++){
            Sarr += nums[i];
        }
        return Sn-Sarr;
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
            int ans = sl.missingNumber(nums);
            cout << ans << endl;
        }
        return 0;
    }
