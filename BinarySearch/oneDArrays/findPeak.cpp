// problem statement: https://leetcode.com/problems/find-peak-element/description/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int findPeak(vector<int> nums){
            int n = nums.size();
            if(n == 0) return 0;
            if(nums[0]>nums[1]) return nums[0];
            if(nums[n-1]>nums[n-2]) return nums[n-1];
            int low = 1 , high = n-2;
            while(low<=high){
                int mid = low + (high - low)/2;
                if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1]){
                    return nums[mid];
                }else if(nums[mid]>nums[mid-1] && nums[mid]<nums[mid+1]){
                    low = mid + 1;
                }else{
                    high = mid - 1;
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
        Solution sl;
        int peak = sl.findPeak(nums);
        cout<< peak << endl;
        
    }
    return 0;
}