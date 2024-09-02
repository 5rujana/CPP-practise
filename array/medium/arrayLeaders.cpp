
#include<bits\stdc++.h>
using namespace std;


/*

intution: 

let  nums = [16,17,4,3,5,2]

for i = 0
    
 */

// time complexity: O(n)
// space complexity: O(q) -> q is elements of ans
class Solution {
  public:
    vector<int> leaders(vector<int> nums) {
        int max = INT_MIN;
        vector<int> ans;
        for(int i = nums.size()-1;i>=0;i--){
            if(nums[i]>=max){
                max=nums[i];
                ans.push_back(nums[i]);
            }
        }
        reverse(ans.begin(),ans.end());
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
        Solution sl;
        vector<int> ans = sl.leaders(nums);
        for(int a : ans){
        cout << a;
        }
        cout << endl;
    }
    return 0;
}