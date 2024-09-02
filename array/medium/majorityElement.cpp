// problem statement: https://leetcode.com/problems/majority-element/description/
#include<bits/stdc++.h>
using namespace std;
/*
intution: we will use count to cnt the number of consecutive occurances of element
if nums[i]==elem then we'll increase count by 1 and if nums[i] != elem
then we'll decrease count by 1 here we are trying to find the frequency of an elem 
which is greater than freq of other elem occours more than n/2 times

let nums = [2,2,1,1,2,5,3,2,2,2,3,1,5,2,2,2]

for i = 0
    count = 0 => count = 1,element = 2

for i = 1
    nums[1] = element => count++ => count = 2

for i = 2
    nums[2] != element => count-- => count = 1

for i = 3
    nums[3] != element => count -- => count = 0
    => other elems (of indices 2,3) balamced out the freq of element

for i = 4
    count = 0 => count = 1, element = 2

for i = 5
    nums[5] != element => count-- => count = 0
    => other elems (of index 5) balamced out the freq of element

for i = 6
    count = 0 => count = 1 , element =3

for i = 7
    nums[7] != element => count-- => count = 0;
    => other elems (of index 7) balamced out the freq of element
for i = 8
    count = 0 => count = 1 , element =2

for i = 9
    nums[8] = element => count++ => count = 2

for i = 10
     nums[10] != element => count-- => count = 1;

for i = 11
    nums[11] != element => count-- => count = 0;
    => other elems (of indices 10,11) balamced out the freq of element

for i = 12
    count = 0 => count = 1 , element = 5

for i = 13
    nums[13] != element => count-- => count = 0;
     => other elems (of index 13) balamced out the freq of element

for i = 14
    count = 0 => count = 1 , element = 2

for i = 15
    nums[15] = elem => count++ => count = 2

for i = 16
    nums[16] = elem => count++ => count = 3

loop ends

now in for loop traversing all elemets well count the occurances of element
if the element has n/2 occurences then return elem
*/
    
// time complexity : O(n+n) = O(2n)
// space complexity: O(1)
class Solution{
    public:
     
     int majorityElement(vector<int> nums){
        // Moore's voting algorithm
        int element;
        int count= 0;
        for(int i = 0;i<nums.size();i++){
            if(count == 0){
                count = 1;
                element = nums[i];
            }else if(nums[i] == element){
                count++;
            }else{
                count--;
            }
        }
        int cnt = 0;
        for(int i = 0;i<nums.size();i++){
            if(element==nums[i]) cnt++;
            if(cnt>nums.size()/2){
                return element;
            }
        }
        return -1;
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
        int ans = sl.majorityElement(nums);
        cout << ans << endl;
    }
    return 0;
}