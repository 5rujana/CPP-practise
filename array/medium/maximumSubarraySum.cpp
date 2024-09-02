// problem statement: https://leetcode.com/problems/maximum-subarray/description/
#include<bits/stdc++.h>
using namespace std;

/*
intution:
well have sum variable maintaining sum of subarray , if the sum < 0 then we'll update the sum = 0
so that we can start sum for next subarray starting from next element
=> we will first compare in every loop if sum = 0, if yes we'll consider it as start of new subarray 
if sum> maxi then well update ansStart = start and ansEnd as i


Let nums = [-2,1,-3,4,-1,2,1,-5,4]
for i = 0
    sum = 0 => start = i => start = 0
    sum = sum + nums[0] => sum = -2

for i = 1
    sum = -2 + 1 = -1
    sum<0 => sum = 0

for i = 2
    sum = 0 => start = 2
    sum = sum + nums[2] => sum = -3
    => sum < 0 => sum = 0

for i = 3
    sum = 0 + 4 => sum = 4
    sum > maxi (as maxi = 0)  & now maxi = 4 => ansStart = start => ansStart = 2
    & ansEnd = i => ansEnd = 3

for i = 4
    sum = 4 - 1 = 3
    continue..

for i = 5
    start = 5 
    sum =  3 + 2 = 5
    sum> maxi (as maxi is 4) & now maxi = 5
    => ansStart = 2 , ansEnd = 5

for i = 6 
    sum = 5+1 = 6
    sum> maxi (as maxi = 5) & now maxi = 6
    => ansStart = 2 , ansEnd = 6

for i = 7
    sum = 6-5 = 1
    continue..

for i = 8
    sum = 1+4 = 5

loop breaks

=> return maxi for maximum sum of subarray & {ansStart , ansEnd} for finding range of that maximum subarray


*/

// time complexity: O(n)
// space complexity : O(1)

class Solution{
    public:
    int maxSubarraySum(vector<int> nums){
        int maxi = INT_MIN;
        int sum = 0;
        int start = -1, ansStart = -1 , ansEnd = -1;
        for(int i = 0;i<nums.size();i++){
            if(sum == 0) start = i;
            sum = sum + nums[i];
            if(sum>maxi){
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum<0){
                sum = 0;
            }
        }
        return sum;
    }

    vector<int> maxSubarrayRange(vector<int> nums){
        int maxi = INT_MIN;
        int sum = 0;
        int start = -1, ansStart = -1 , ansEnd = -1;
        for(int i = 0;i<nums.size();i++){
            if(sum == 0) start = i;
            sum = sum + nums[i];
            if(sum>maxi){
                maxi = sum;
                ansStart = start;
                ansEnd = i;
            }
            if(sum<0){
                sum = 0;
            }
        }
        return {ansStart,ansEnd};
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
        int ans = sl.maxSubarraySum(nums);
        cout << ans << endl;
        vector<int> range = sl.maxSubarrayRange(nums);
        for(int i = range[0];i<=range[1];i++){
            cout<< nums[i] << " ";
        }
        cout<<endl;
    }
    return 0;
}