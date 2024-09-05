// probem statement: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int searchRotatedArray(vector<int> nums , int target){
            int low = 0, high = nums.size() - 1;
            while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            
            // Handling duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                ++low;
                --high;
            }
            else if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
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
        int ans = sl.searchRotatedArray(nums,target);
        cout<< ans << endl;
        
    }
    return 0;
}


