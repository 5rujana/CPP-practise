// problem Statement: https://leetcode.com/problems/next-greater-element-i/description/
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> nextGreaterElement(vector<int> nums){
                int n = nums.size();
                vector<int> nge(n,-1);
                stack<int> st;
                for(int i = n-1;i>=0;i++){
                    while(!st.empty() && st.top() <= nums[i]){
                        st.pop();
                    }

                    if(!st.empty()){
                        nge[i] = st.top();
                    }

                    st.push(nums[i]);
                }
            return nge;
        }
};

int main(){
    int size;
    cin>> size;
    vector<int> nums(size);
    for(int i = 0;i<size;i++){
         cin>> nums[i];
    }
    Solution sl;
    vector<int> nge = sl.nextGreaterElement(nums);
    for(int i = 0; i< nge.size();i++){
        cout<<nums[i] << " -> " << nge[i]<< endl;
    }
}
