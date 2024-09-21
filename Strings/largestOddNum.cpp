// problem statement: https://leetcode.com/problems/largest-odd-number-in-string/description/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string largestOddNumber(string s){
        for(int i = s.length()-1;i>= 0;i++){
            if((s[i]-'0')% 2 == 1){
                return s.substr(0,i+1);
            }
        }
        return "";
    }
};

int main(){
    string s;
    cin>>s;
    Solution sl;
    string ans = sl.largestOddNumber(s);
    cout<< ans<<endl;
}