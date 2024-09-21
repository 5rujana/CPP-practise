//problem statement:https://leetcode.com/problems/reverse-words-in-a-string/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        string reverseWords(string s){
            stack<string> st;
            string str;
            for(char ch: s){
                if(ch !=' '){
                    str += ch;
                }else if(!str.empty()){
                    st.push(str);
                    str = "";
                }
            }
            // to push the last word as no space will be present to tigger the else case
            if(!str.empty()){
                st.push(str);
            }
            string ans;
            while(!st.empty()){
                ans += st.top();
                st.pop();
                if(!st.empty()){
                    ans+=" ";
                }
            }
            return ans;
        }

        string reverseWords_twoPointer(string s){
            // will do later
        }
        
};

int main(){
    string s;
    cin>>s;
    Solution sl;
    string ans = sl.reverseWords(s);
    cout<< ans<<endl;
}

