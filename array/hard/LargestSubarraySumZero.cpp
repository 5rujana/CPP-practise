// problem statemet: https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1?category%5B%5D=Hash&company%5B%5D=Amazon&page=1&query=category%5B%5DHashcompany%5B%5DAmazonpage1company%5B%5DAmazoncategory%5B%5DHash&utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=largest-subarray-with-0-sum

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    int sumZero(vector<int>  nums){
        int sum = 0;
        unordered_map<int,int> mpp;
        if(nums.size()== 0) return 0;
        int maxlen = 0;
        for(int i = 0; i<nums.size();i++){
            sum += nums[i];
            if(sum==0){
                maxlen = i+1;
            }

            if(mpp.find(sum)!=mpp.end()){
                maxlen = max(maxlen, i-mpp[sum]);
            }else{
                 mpp[sum] = i; // we want to find first occrance... if we store all other occurances of subarray then we might get length of subarray minimum not maximum
            }
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
        Solution sl;
       int ans = sl.sumZero(nums);
       cout<<ans<<endl;
    }
    return 0;
}

