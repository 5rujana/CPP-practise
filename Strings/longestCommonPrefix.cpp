// problem statement: https://leetcode.com/problems/longest-common-prefix/description/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        string longestCommonPrefix(vector<string> strs){
            if(strs.empty()) return "";
            sort(strs.begin(),strs.end());
            string first = strs[0];
            string last =strs.back();
            int i = 0;
            while(i<first.size() && i<last.size() && first[i]==last[i]){
                i++;
            }
            return first.substr(0,i);
        }
};

int main(){
    int n;
    cin>>n;
    vector<string> strs;
    for(int i = 0; i<n;i++){
        cin>> strs[i];
    }
    Solution sl;
    string prefix = sl.longestCommonPrefix(strs);
    cout<<prefix<<endl;
}