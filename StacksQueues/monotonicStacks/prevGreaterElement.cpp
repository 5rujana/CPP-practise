#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prevGreaterElement(vector<int> nums) {
        int n = nums.size();
        vector<int> pge(n, -1);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                pge[i] = st.top();
            }

            st.push(nums[i]);
        }
        return pge;
    }
};

int main() {
    int size;
    cin >> size;
    vector<int> nums(size);
    for (int i = 0; i < size; i++) {
        cin >> nums[i];
    }
    
    Solution sl;
    vector<int> pge = sl.prevGreaterElement(nums);
    
    for (int i = 0; i < pge.size(); i++) {
        cout << nums[i] << " -> " << pge[i] << endl;
    }
}
