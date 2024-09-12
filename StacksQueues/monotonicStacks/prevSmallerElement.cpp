#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> prevSmallerElement(vector<int> nums) {
        int n = nums.size();
        vector<int> pse(n, -1);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() >= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                pse[i] = st.top();
            }

            st.push(nums[i]);
        }
        return pse;
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
    vector<int> pse = sl.prevSmallerElement(nums);
    
    for (int i = 0; i < pse.size(); i++) {
        cout << nums[i] << " -> " << pse[i] << endl;
    }
}
