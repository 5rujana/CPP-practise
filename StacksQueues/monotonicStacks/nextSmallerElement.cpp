#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElement(vector<int> nums) {
        int n = nums.size();
        vector<int> nse(n, -1);
        stack<int> st;
        
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() >= nums[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nse[i] = st.top();
            }

            st.push(nums[i]);
        }
        return nse;
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
    vector<int> nse = sl.nextSmallerElement(nums);
    
    for (int i = 0; i < nse.size(); i++) {
        cout << nums[i] << " -> " << nse[i] << endl;
    }
}
