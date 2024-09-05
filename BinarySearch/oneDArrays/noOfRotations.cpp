// problem statement : https://www.geeksforgeeks.org/problems/rotation4723/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotation

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int noOfRotations( vector<int> nums){
            int low = 0;
            int high = nums.size()-1;
            int ans = INT_MAX;
            int ind = -1;
            while(low <= high){
                int mid = low + (high - low)/2;
                if(nums[high]>nums[mid]){
                    if(ans>nums[mid]){
                        ans = nums[mid];
                        ind = mid;
                    }
                    high = mid-1;
                }else{
                    if(ans>nums[low]){
                        ans = nums[low];
                        ind = low;
                    }
                    low = mid+1;
                }
            }
            return ind;
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
        int rotations = sl.noOfRotations(nums);
        cout<< rotations << endl;
        
    }
    return 0;
}



