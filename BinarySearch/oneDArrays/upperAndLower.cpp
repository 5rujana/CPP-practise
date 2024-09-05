// problem statement: https://www.geeksforgeeks.org/problems/floor-in-a-sorted-array-1587115620/1?track=DSASP-Searching&amp%253BbatchId=154&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=floor-in-a-sorted-array

#include<bits/stdc++.h>
using namespace std;

/*
defination: 
    The lower bound algorithm finds the first or the smallest index in a sorted array,
     where the value at that index is greater than or equal to a given key i.e. x.

    The lower bound is the smallest index, ind, where nums[ind] >= x.
    But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.


    The upper bound algorithm finds the first or the smallest index in a sorted array,
     where the value at that index is greater than the given key i.e. x.

    The upper bound is the smallest index, ind, where arr[ind] > x.
*/ 
class Solution{
    public:
    int lowerBound(vector<int> nums , int target ){
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

    int upperBound(vector<int> nums ,int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = nums.size();
        while(low<=high){
            int mid = low + (high-low) /2;
            if(nums[mid]>target){
                ans = mid;
                high = mid-1;
            }else{
                low = mid +1;
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
        int target;
        cin>> target;
        Solution sl;
        int flr = sl.lowerBound(nums,target);
        int ciel = sl.upperBound(nums,target);

        cout<< flr << ciel << endl;
        
    }
    return 0;
}

