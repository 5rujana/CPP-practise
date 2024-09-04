// problem statement: https://leetcode.com/problems/merge-intervals/description/
#include<bits/stdc++.h>
using namespace std;      

class Solution{
    public:
        vector<vector<int>> mergeIntervals(vector<vector<int>> intervals){
            vector<vector<int>> merged;
            sort(intervals.begin(),intervals.end());
            for(int i = 0;i<intervals.size();i++){
                if(merged.empty() || merged.back()[1]<intervals[i][0]){
                    merged.push_back(intervals[i]);
                }else{
                    merged.back()[1] = max(merged.back()[1], intervals[i][1]);
                }
            }
            return merged;
        }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> nums(n);
        for(int i = 0; i<n;i++){
            for(int j = 0; j<m;j++){
                cin>> nums[i][j];
            }
        }
        
        Solution sl;
        vector<vector<int>> ans = sl.mergeIntervals(nums);
        for(int i = 0;i<ans.size();i++){
            for(int j = 0 ; j < ans[0].size(); j++){
            cout << ans[i][j] <<" ";
            }
            cout<< endl;
        }
    }
    return 0;
}

