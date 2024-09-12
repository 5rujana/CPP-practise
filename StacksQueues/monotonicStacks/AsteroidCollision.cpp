// problem statement: https://leetcode.com/problems/asteroid-collision/
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> asteroidCollision(vector<int> asteroids){
        stack<int> st;
        for(int i = 0; i< asteroids.size();i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            } else{
                while(!st.empty() && st.top() > 0 && st.top() < abs(asteroids[i])){
                    st.pop();
                }
                if(!st.empty() && st.top() == abs(asteroids[i])){
                    st.pop();
                } else if(st.empty() || st.top() < 0){
                    st.push(asteroids[i]);
                }
            }
        }

        vector<int> results;
        while(!st.empty()){
            results.push_back(st.top());
            st.pop();
        }
        reverse(results.begin(),results.end());
        return results;
    }
};

int main(){
    int n;
    cin>> n;
    vector<int> asteroids(n);
    for(int i = 0; i< asteroids.size();i++){
        cin>> asteroids[i];
    }
    Solution sl;
    vector<int> ans = sl.asteroidCollision(asteroids);
    for(int i = 0; i< ans.size();i++){
        cout<< ans[i] << " ";
    }
}