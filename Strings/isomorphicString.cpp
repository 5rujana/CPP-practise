//problem statement: https://leetcode.com/problems/isomorphic-strings/description/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool isIsomorphic(string s, string t){
            if(s.length() != t.length()) return false;
            unordered_map<char,char> mapST,mapTS;
            for(int i = 0; i< s.size();i++){
                char c1 = s[i];
                char c2 = t[i];
                if((mapST.count(c1) && mapST[c1] != c2) || (mapTS.count(c2) && mapTS[c2] != c1)){
                    return false;
                }
                mapST[c1] = c2;
                mapTS[c2] = c1;
            }
            return true;
        }
}; 
int main(){
    string s,t;
    cin>>s>>t;
    Solution sl;
    bool isomorphic = sl.isIsomorphic(s,t);
    if(isomorphic) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}