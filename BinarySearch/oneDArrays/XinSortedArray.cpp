// problem statement: https://leetcode.com/problems/binary-search/description/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(target==nums[m]){
                return m;
            }else if(target<nums[m]){
                r = m-1;
            }else{
                l =m+1;
            }
        }
        return -1;
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
        int target;
        cin>> target;
        Solution sl;
        int ans = sl.search(nums,target);
        cout<< ans << endl;
        
    }
    return 0;
}



