// problem statement: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-occurrence
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
    int countOccurence(vector<int> nums, int target){
        int startIndex = lowerBound(nums,target);
        int endIndex = lowerBound(nums,target+1)-1;
        if(startIndex<nums.size() && nums[startIndex]==target){
            return endIndex-startIndex;
        }
        return 0;
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
        int ans = sl.countOccurence(nums,target);
        cout<< ans << endl;
        
    }
    return 0;
}


