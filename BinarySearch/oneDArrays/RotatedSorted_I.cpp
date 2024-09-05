// probem statement: https://leetcode.com/problems/search-in-rotated-sorted-array/description/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int searchRotatedArray(vector<int> nums , int target){
            int high = nums.size()-1;
            int low = 0;
            int ans = -1;
            while(low<=high){
                int mid = low + (high-low)/2;
                if(nums[mid]>= nums[low]){
                    if(target<=nums[mid] && target >= nums[low]){
                        high = mid -1;
                    }else{
                        low = mid - 1;
                    }
                }else if(nums[mid]<=nums[high]) {
                    if( target<=nums[high] && target >= nums[mid]){
                        low = mid+1;
                    }else{
                        high = mid - 1;
                    }
                }else{
                    ans = mid;
                }

                return ans;
        }
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


