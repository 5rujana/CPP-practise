// problem statement: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int minimum(vector<int> nums){
        int low = 0, high = nums.size()-1; int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high-low) / 2;
            if(nums[high]>nums[mid]){
                ans = min(ans,nums[mid]);
                high = mid- 1;
            }else{
                ans = min(ans,nums[low]);
                low = mid+1;
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
        int min = sl.minimum(nums);
        cout<< min << endl;
        
    }
    return 0;
}

