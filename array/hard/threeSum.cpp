// problem statement: https://leetcode.com/problems/3sum/

#include<bits\stdc++.h>
using namespace std;

/*

intution same as four Sum, please refer it

file loc : array\hard\fourSum.cpp

*/

// time complexity : O(n^2)
// space complexity :  O(n^2)

class Solution{
    public:
    vector<vector<int>> threeSum(vector<int> nums, int target){
        vector<vector<int>> triple;
        sort(nums.begin(),nums.end());
        for(int i = 0; i< nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
                int j = i+1,k = nums.size()-1;
                while(j<k){
                    long long sum = nums[i]+nums[j]+nums[k];
                    if(sum>target){
                        k--;
                    }else if(sum<target){
                        j++;
                    }else{
                        triple.push_back({nums[i],nums[j],nums[k]});
                        j++;
                        k--;
                    }

                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
        }
        return triple;
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
        vector<vector<int>> ans = sl.threeSum(nums,target);
        for(int i = 0;i<ans.size();i++){
            for(int j = 0 ; j < ans[0].size(); j++){
            cout << ans[i][j] <<" ";
            }
            cout<< endl;
        }
    }
    return 0;
}

