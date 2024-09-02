// problem statement : https://leetcode.com/problems/sort-colors/description/

#include<bits/stdc++.h>
using namespace std;

/*
intution: well use 3 pointer l,m,h for tracking left most,right most and middle elements of unsorted array
 our objective is that all elemets befor middle ahould be 0's , middle elements should be 1's and elements right to middle should be 2's
 
 Let us have nums = [2,0,2,1,1,0]
    for m = 0 and h = 5
        nums[m] = nums[0] = 2
        nums[0] == 2 => swap(nums[m], nums[h])
        h-- => h = 4;
        => nums = [0,0,2,1,1,2]
    
    for m = 0 and h = 4
        nums[0] = 0 => swap(nums[m],nums[l])
        and l++ => l = 1, m++ => m = 1;
        => nums = [0,0,2,1,1,2]

    for m = 1 and h = 4
        nums[1] = 0 => swap(nums[m],nums[l])
        and l++ => l = 2, m++ => m = 2;
        => nums = [0,0,2,1,1,2]
    
    for m = 2 and h = 4
        nums[2] = 2 => swap(nums[m], nums[h])
        h-- => h = 3
        => nums = [0,0,1,1,2,2]
    
    for m = 3 and h = 3
        nums[3] = 1 
        => m++ => m = 4
    
    4 > 3 so while loop breaks
*/

// time complexity : O(n)
// space complexity : O(1)
class Solution{
    public:
    void sortColors(vector<int> nums){
        int m = 0 , l = 0 , h = nums.size()-1;
        while(m<=h){
            if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }else if(nums[m]==1){
                m++;
            }else{
                swap(nums[m],nums[h]);
                h--;
            }
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

        Solution sl;
        sl.sortColors(nums);
        for(int num:nums){
            cout<< num << " ";
        }
        cout<<endl;
    }
    return 0;
}