// problem statement: https://leetcode.com/problems/majority-element-ii/
#include<bits/stdc++.h>
using namespace std;

/*


*/

// Time Complexity: O(n+n) 
// Space Complexity: O(1) => only 2 elems can be found as when we take mode [n/3] => we'll get x ass ans and elem can occure > xtimes -> like these only 2 can bbe found

class Solution{
    public:
        vector<int> majorityElement(vector<int> nums){
            int cnt1 = 0, cnt2 = 0;
            int elem1 = 0, elem2 = 0;
            for(int i = 0;i<nums.size();i++){
                if(cnt1 == 0 && nums[i] != elem2){
                    cnt1=1;
                    elem1 = nums[i];
                }else if(cnt2 == 0 && nums[i] != elem1){
                    cnt2=1;
                    elem2 = nums[i];
                }else if(elem1 == nums[i]){
                    cnt1++;
                }else if(elem2 == nums[i]){
                    cnt2++;
                }else{
                    cnt1 --;
                    cnt2--;
                }
            }
            vector<int> result;
            int mini = nums.size() / 3;
            cnt1 = 0, cnt2 = 0; 
            for(int i = 0;i<nums.size();i++){
                if(elem1 == nums[i]){
                    cnt1++;
                }else if(elem2 == nums[i]){
                    cnt2++;
                }
            }

            if(cnt1>mini){
                result.push_back(elem1);
            }
            if(cnt2>mini){
                result.push_back(elem2);
            }
            return result;
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
       vector<int> ans = sl.majorityElement(nums);

        for(int j = 0 ; j < ans.size(); j++){
            cout << ans[j] <<" ";
        }
        cout<< endl;
    }
    return 0;
}

