// problem statement: https://www.naukri.com/code360/problems/ceiling-in-a-sorted-array_1825401
#include<bits\stdc++.h>
using namespace std;
/*

The floor of x is the largest element in the array which is smaller than or equal to x.
The ceiling of x is the smallest element in the array greater than or equal to x.

*/
class Solution{
    public:
    int FindFloor(vector<int> nums , int target ){
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low) /2;
            if(nums[mid]<=target){
                ans = mid;
                low = mid+1;
            }else{
                high = mid -1;
            }
        }
        return ans;
    }

    int FindCiel(vector<int> nums ,int target){
        int low = 0;
        int high = nums.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low) /2;
            if(nums[mid]>=target){
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
        int flr = sl.FindFloor(nums,target);
        int ciel = sl.FindCiel(nums,target);

        cout<< flr << ciel << endl;
        
    }
    return 0;
}

