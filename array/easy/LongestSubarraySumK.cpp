// problem statement: https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=longest-sub-array-with-sum-k
#include<bits/stdc++.h>
using namespace std;
// intution: we will mantain a map tracking sum and at which index that sum is present , extra = sum-k we'll check if exttra is present in mpp and then len = i-mpp[extra] and like this will findmaxlen among all those len
/*

    Suppose [ 10 , 5 , 2 , 7 , 1 , 9] , k = 15
    now for i = 0,
        sum = 10 => extraSum = 10-15 = -5 which isn't present in mpp, as mpp is empty
        so mpp = [{10,1}]

    for i = 1,
        sum = 10+5 = 15 => sum == k 
        => maxlen = max(0,1+1) as i = 1
        maxlen = 2
        mpp = [{10,1},{15,2}]

    for i = 2,
        sum = 15+2 = 17 => extraSum = 17-15 = 2 which is not present in mpp
        so mpp = [{10,1},{15,2},{17,3}]
    
    for i = 3,
        sum = 17+7 = 24 => extraSum = 24-15 = 1 which is not present in mpp
        so mpp = = [{10,0},{15,1},{17,2},{24,3}]
    
    for i = 4,
        sum = 24 + 1 = 25 , extraSum = 25-15 = 10 which is present in mpp
        => mpp[extraSum] = 0
        => elemets from 1 to 4 contribute to give sum 15
        => len = 4-0 = 4
        maxlen = max(4,2) = 4
        mpp = [{10,0},{15,1},{17,2},{24,3},{25,4}]
    for i = 5,
        sum = 25+9 = 34 , extraSum = 34-15 = 19 which is not present in mpp
         mpp = [{10,0},{15,1},{17,2},{24,3},{25,4},{34,5}]

    end of loop , so returns maxlen = 4

 */

// Time complexity: O(nlogn)
// Space Complexity: O(logn)
class Solution{
    public:
    int lenOfSubarray(vector<int> nums,int k ){ // this is optimal for negatives and positives
        map<int,int> mpp;
        int maxlen = 0; int sum = 0;
        for(int i = 0;i<nums.size();i++){
            sum +=nums[i];
            if(sum == k){
                maxlen = max(maxlen,i+1);
            }
            int extraSum = sum-k;
            if(mpp.find(extraSum)!=mpp.end()){
                int len = i-mpp[extraSum];
                maxlen = max(maxlen,len);
            }
            if(mpp.find(sum)==mpp.end()){
                mpp[sum]=i;
            }
        }
        return maxlen;
    }

    // for positives we can use 2 pointer approach - sliding window
    // time complexity : O(n)
    // space complexity: O(1)
    int lenOfSubarray_SW(vector<int> nums,int k ){ // this is optimal for positives
        int left = 0;
        int right = 0;
        int sum = 0, maxlen = 0;
        while(right<nums.size()){
            while(sum>k &&  left<=right){
                sum-=nums[left];
                left++;
            }
            if(sum==k) maxlen = max(maxlen,right-left+1);
            right++;
            if(right<nums.size()) sum +=nums[right];
        }
        return maxlen;
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
        int k;
        cin>>k;
        Solution sl;
        int ans = sl.lenOfSubarray(nums,k);
        cout << ans << endl;
    }
    return 0;
}