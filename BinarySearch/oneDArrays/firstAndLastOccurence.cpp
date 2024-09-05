// problem statement: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
    int lowerBound(vector<int> nums, int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = low + (high-low) /2;
            if(nums[mid]>=target){
                ans = mid;
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
    vector<int> firstAndLastOccurence(vector<int> nums, int target){
        int startIndex = lowerBound(nums,target);
        int endIndex = lowerBound(nums,target+1)-1;
        if(startIndex<nums.size() && nums[startIndex]==target){
            return {startIndex,endIndex};
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
        int target;
        cin>> target;
        Solution sl;
        vector<int> ans = sl.firstAndLastOccurence(nums,target);
        cout<< ans[0] << ans[1] << endl;
        
    }
    return 0;
}

