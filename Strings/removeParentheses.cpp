//problem statement:https://leetcode.com/problems/remove-outermost-parentheses/description/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    string removeOuterParentheses(string s){
        string ans = "";
        int balance = 0;
        for(auto ch : s){
            if(ch == '('){
                if(balance>0){
                    // not outer paranteses
                    ans += ch;
                }
                balance++;
            }else{
                balance--;
                if(balance>0){
                    // not outer parantheses
                    ans+=ch;
                }
            }
        }
        return ans;
    }
};

int main(){
    string s;
    cin>>s;
    Solution sl;
    string ans = sl.removeOuterParentheses(s);
    cout<< ans<<endl;
}