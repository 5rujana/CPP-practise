// problem statement: https://leetcode.com/problems/next-permutation/description/

#include<bits/stdc++.h>
using namespace std;

/*
intution: The key idea is to identify the first "dip" point from the end of the sequence, where the order is no longer ascending. 
This "dip" represents the last position where the sequence can be modified to create a new permutation. 
After identifying this point, we search for the smallest element to the right of the "dip" that is larger than the "dip" element itself. 
Swapping these two elements moves the sequence towards the next permutation. 
Finally, to ensure this new sequence is the next smallest permutation, we sort the elements to the right of the "dip" in ascending order,
effectively placing the smallest possible values in the lowest positions

nums = [1,2,8,7,6,5,4,3]

for first loop we'll find the position where we find the dip


    |
  /   \
/       \
          \
            \  
              \
1 2 8 7 6 5 4 3 
here dip is at ind = 1

now with the help of second loop we'll find the element just bigger than 2 => 3
so swap 2,3

now reverse from ind 2 to 7 => typically to sort them

*/

// time complexity: O(n+n)
// space complexity: O(1)
class Solution{
    public:
    void nextPermutation(vector<int> nums , int k){
        int ind = -1;
        for(int i = nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind = i;
                break;
            }
        }

        if(ind == -1){
            reverse(nums.begin(),nums.end());
        }else{
            for(int i = nums.size()-1;i>ind;i++){
                if(nums[i]>nums[ind]){
                    swap(nums[i],nums[ind]);
                    break;
                }
            }
            reverse(nums.begin()+ind+1,nums.end());
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
        int k;
        cin>>k;
        Solution sl;
        sl.nextPermutation(nums,k);
        for(int num:nums){
            cout<< num << " ";
        }
        cout<<endl;  
    }
    return 0;
}