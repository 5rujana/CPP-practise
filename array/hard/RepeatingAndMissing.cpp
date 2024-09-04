// problem statement: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=find-missing-and-repeating
#include<bits/stdc++.h>
using namespace std;

/*

 intution:
 first we will calculate sum of positive numbers from 1 to n => n(n+1)/2 => S
            and sum of squares of positive numbers from 1 to n => (n)(2n+1)(n+1)/ 6 => Sq

 and then we'll calculate sum of all elements of array => arrSum
        and sum of squares of all elements of array => arrSqSum
        
        now x-y=  arrSum-S and x2-y2 = arrSqSum-Sq
        now x+y = x2-y2/x-y
        => x+y = arrSqSum-Sq / arrSum-S
        now x = x+y + x-y / 2
        now y = x+y - x

        return { x,y}

*/

// time complexity: O(n)
// space complexity : O(1)

class Solution {
public:
    vector<int> findTwoElement(vector<int> arr) {
        int n = arr.size();
        
        // Calculate S and Sq (Sum and Sum of squares for first n natural numbers)
        long long S = (long long)n * (n + 1) / 2;
        long long Sq = (long long)n * (n + 1) * (2 * n + 1) / 6;
        
        long long arrSum = 0, arrSqSum = 0;
        
        // Calculate sum and sum of squares of the array elements
        for (int i = 0; i < n; i++) {
            arrSum += arr[i];
            arrSqSum += (long long)arr[i] * arr[i];
        }
        
        // Calculate the differences
        long long diffSum = arrSum - S; // R - M
        long long diffSqSum = arrSqSum - Sq; // R^2 - M^2
        
        // From R^2 - M^2 = (R - M) * (R + M)
        long long sumRM = diffSqSum / diffSum; // R + M
        
        // Calculate the missing and repeating numbers
        int R = (sumRM + diffSum) / 2;
        int M = sumRM - R;
        
        return {R, M};
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i = 0; i<n;i++){
        cin>> nums[i];
        }
        Solution sl;
        vector<int> ans = sl.findTwoElement(nums);
        cout<< ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

