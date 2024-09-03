// problem statement: https://leetcode.com/problems/longest-consecutive-sequence/description/

#include<bits/stdc++.h>
using namespace std;

/*

intution:

 */

// time complexity: O(n)
// space Complexity: O(m) => m is unique elems worst case m = n
class Solution{
    public:
    int longestConseecutive(vector <int> nums){
        unordered_set<int> st;
        if (nums.size()==0) return 0;
        for(int i = 0;i<nums.size();i++){
            st.insert(nums[i]);
        }
    int maxlen = 1;
    for(auto it:st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int prev = it;
            while(st.find(prev+1)!=st.end()){
                    prev +=1;
                    cnt+=1;
            }
            maxlen = max(maxlen,cnt);
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
        int ans = sl.longestConseecutive(nums);
        cout << ans << endl;
    }
    return 0;
}