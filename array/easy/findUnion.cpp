// problem statement : https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=union-of-two-sorted-arrays
#include <bits/stdc++.h>
using namespace std;


// intution : Merge sort , using 2 pointer merging 2 arrays with extra check of making sure elements in array are unique
// time complexity : O(n+m) where n and m are sizes of arrays
// space complexity: O(q) where q ia no of unique elems in worst case its O(n+m)

class Solution{
    public:
    vector<int> findUnion(vector<int> arr1 , vector<int> arr2){
        vector<int> ans;

        int l1 = 0, l2 = 0;
        while(l1<arr1.size() && l2<arr2.size()){
                if(arr1[l1]<=arr2[l2]){
                    if(ans.empty() || ans.back() != arr1[l1]){
                        ans.push_back(arr1[l1]);
                    }
                    l1++;
                }else{
                    if(ans.empty()  || ans.back() != arr2[l2]){
                         ans.push_back(arr2[l2]);
                    }
                    l2++;
                
                }
        }

        while (l1 < arr1.size()) {
            if(ans.back() != arr1[l1]){
                ans.push_back(arr1[l1]);
            }
            l1++;
        }

        while(l2 < arr2.size()){
            if(ans.back() != arr2[l2]){
                ans.push_back(arr2[l2]);
            }
            l2++;
        }
        return ans;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        vector<int> arr1(n);
        vector<int> arr2(m);
        for(int i = 0; i<n;i++){
            cin>>arr1[i];
        }
        for(int i = 0; i<n;i++){
            cin>>arr2[i];
        }
        Solution sl;
        vector<int> ans = sl.findUnion(arr1,arr2);
        for(int i : ans){
            cout<< i << " ";
        }
         cout<<endl;
    }
    return 0;
}
