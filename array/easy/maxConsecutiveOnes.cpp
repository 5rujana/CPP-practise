     // problem statement: https://leetcode.com/problems/max-consecutive-ones/description/
     
     #include<bits/stdc++.h>
     using namespace std;
     // intution: we'll cnt for number of conseq 1's and return max cnt
     // Time-complexity: O(n)
     // Space-complexity: O(1)

     class Solution{
        public:
        int maxConsecutiveOnes(vector<int> nums){
            int cnt = 0,maxcnt = 0;
            for(int i = 0 ; i<nums.size();i++){
                if(nums[i]==1){
                    cnt++;
                }else{
                    cnt = 0;
                }
                maxcnt = max(maxcnt,cnt);
            }
            return maxcnt;
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
            int ans = sl.maxConsecutiveOnes(nums);
            cout << ans << endl;
        }
        return 0;
    }

