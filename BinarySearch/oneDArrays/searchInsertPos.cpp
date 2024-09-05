// problem statement : https://leetcode.com/problems/search-insert-position/description/
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
    int searchInsert(vector<int> nums, int target){
        int Index = lowerBound(nums,target);
        return Index;
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
        int ans = sl.searchInsert(nums,target);
        cout<< ans << endl;
        
    }
    return 0;
}

