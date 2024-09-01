// problem statement: https://leetcode.com/problems/single-number/description/
#include<bits/stdc++.h>
using namespace std;
// intution: using xor as xor of 2 same elements is 0 so xoring all elements will give us our unique elem
// Time Complexity : O(n)
// Space Complexity: O(1)
class Solution{
    public:
    int singleNumber(vector<int> nums){
        int xorRes = 0;
        for(int num: nums){
            xorRes ^=num;
        }
        return xorRes;
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
        int ans = sl.singleNumber(nums);
        cout << ans << endl;
    }
    return 0;
}