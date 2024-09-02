// problem Statement : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include<bits/stdc++.h>
using namespace std;

/*

intution: while travelling we will track the min element encountered so far and calculated max profit so far
and return the final profit after ending the loop

Let prices = [7,1,5,3,6,4]

for i = 0, mini = 7
    cost = prices[0] - mini => cost = 7-7 = 0
    => mini = min(mini,prices[0]) => mini = 7
    => profit = max(profit,cost) = 0

for i = 1, mini = 7
    cost = prices[1]-mini = 1-7 = -6
    => mini = min(mini,prices[1]) => mini = 1
    => profit = max(profit,cost) => profit = 0

for i = 2, mini = 1
cost = prices[2]-mini = 5-1 = 4
=> mini = min(mini,prices[2]) = 1
=> profit = max(profit,cost) = 4

for i = 3, mini = 1
cost = prices[3]-mini = 3-1 = 2
=>mini = min(mini,prices[3]) = 1
=> profit = max(profit,cost) = 4

for i = 4, mini = 1
cost = prices[4]-mini = 6-1 = 5
=>mini = min(mini,prices[4]) = 1
=> profit = max(profit,cost) = 5

for i = 5, mini = 1
cost = prices[4]-mini = 4-1 = 3
=>mini = min(mini,prices[4]) = 1
=> profit = max(profit,cost) = 5

loop ends

return profit

*/

// time Complexity : O(n)
// space Complexity : O(1)

class Solution{
    public:
    int stock(vector<int> prices){
        int mini = prices[0];
        int profit = 0;
        for(int i = 0;i<prices.size();i++){
            int cost = prices[i]-mini;
            profit = max(profit,cost);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> prices(n);
        for(int i = 0; i<n;i++){
        cin>> prices[i];
        }
        Solution sl;
        int ans = sl.stock(prices);
        cout << ans << endl;
    }
    return 0;
}