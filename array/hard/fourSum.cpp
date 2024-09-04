// problem solving : https://leetcode.com/problems/4sum/description/

#include<bits/stdc++.h>
using namespace std;

/*
intution:
for brute Force: we will use four loopes for finnding 4 different indices => time complexity => O(n^4)

for better approach: we will try to reduce time complexity, so for that we will use only 3 loops
we'll use hashset for sorting the nums and set<vector<int>> for storing uniqueue quadraple sets
=> rem = sum - nums[i] - nums[j] - nums[k] ans well check if rem is present in set if it is present
==> hashset.insert(nums[k])  :=> Time complexity = O(n^3logn) , Space Complexity: O(n) + O(quadraple)*2


for Optimal approach we'll use 4 pointer approach
Let nums = [1,1,1,2,2,2,3,3,3,4,4,4,5,5], k = 8
indices    [0,1,2,3,4,5,6,7,8,9,10,11,12,13] 

for i = 0
    for j = 1
        k = 2, l = 13
        as k < l
            sum = nums[0]+nums[1]+nums[2]+nums[13] = 1+1+1+5 = 8 , k++ => k = 3  & l-- => l = 12 
            sum = target => ans = [[1,1,1,5]]
             l<k && nums[k] != nums[k-1] => k is unchanged
            while l<k &&  nums[l] == nums[l+1] => l-- this is for removing duplicate set of quadruples which can be generated
            => l = 11

        k = 3, l = 11
        as k < l
            sum = nums[0]+nums[1]+nums[3]+nums[11] = 1+1+2+4 = 8 , k++ => k = 4  & l-- => l = 10 
            sum = target => ans = [[1,1,1,5],[1,1,2,4]]
            while l<k && nums[k] == nums[k-1] => k++ this is for removing duplicate set of quadruples which can be generated
            => k =6
            while l<k &&  nums[l] == nums[l+1] => l-- this is for removing duplicate set of quadruples which can be generated
            => l = 8

        k = 6, l = 8
        as k < l
            sum = nums[0]+nums[1]+nums[6]+nums[8] = 1+1+3+3 = 8 , k++ => k = 7  & l-- => l = 7
            sum = target => ans = [[1,1,1,5],[1,1,2,4],[1,1,3,3]]
            while l<k && nums[k] == nums[k-1] => k++ this is for removing duplicate set of quadruples which can be generated
            => k =10
            while l<k &&  nums[l] == nums[l+1] => l-- this is for removing duplicate set of quadruples which can be generated
            => l = 5
            
        l<k so loop breaks => j++
    for j = 2,
        while nums[j] == nums[j-1] => j++ this is for removing duplicate set of quadruples which can be generated
        => j = 3
            k = 4, l = 13
            as k<l
                sum = nums[0]+nums[3]+nums[4]+nums[13] = 1+2+2+5 = 10 ,  l-- => l = 12
                sum = target => ans = [[1,1,1,5],[1,1,2,4],[1,1,3,3]] => remains same
                while l<k && nums[k] == nums[k-1] => k++ this is for removing duplicate set of quadruples which can be generated
                => k = 6
                while l<k &&  nums[l] == nums[l+1] => l-- this is for removing duplicate set of quadruples which can be generated
                => l = 11
            
            k = 6, l = 11
            as k<l
                sum = nums[0]+nums[3]+nums[6]+nums[11] = 1+2+3+4 = 10 ,  l-- => l = 10
                sum = target => ans = [[1,1,1,5],[1,1,2,4],[1,1,3,3]] => remains same
                while l<k && nums[k] == nums[k-1] => k++ this is for removing duplicate set of quadruples which can be generated
                => k = 9
                while l<k &&  nums[l] == nums[l+1] => l-- this is for removing duplicate set of quadruples which can be generated
                => l = 8
            
            l<k so loop ends

        loop goes on this way till the end..

*/

class Solution{
    public:
    vector<vector<int>> fourSum(vector<int>& nums, int target){
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i = 0 ; i < nums.size();i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1 ; j<nums.size();j++){
                if(j>0 && nums[j] == nums[j-1]) continue;
                int k = j+1;
                int l = nums.size()-1;

                while(k<l){
                     long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                    if(sum<target){
                        k++;
                    }else if(sum>target){
                        l--;
                    }else{
                         vector<int> quadruple = {nums[i], nums[j], nums[k], nums[l]};
                         ans.push_back(quadruple);
                         k++;
                         l--;
                    }
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
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
        vector<vector<int>> ans = sl.fourSum(nums,target);
        for(int i = 0;i<ans.size();i++){
            for(int j = 0 ; j < ans[0].size(); j++){
            cout << ans[i][j] <<" ";
            }
            cout<< endl;
        }
    }
    return 0;
}

