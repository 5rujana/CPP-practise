// reversing array

#include<bits/stdc++.h>
using namespace std;

vector<int> revarr(vector<int> arr,int left , int right){
    if(left >= right){
        return arr;
    }
    int temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
    return revarr(arr,left+1,right-1);
}

//rev(0,n)


int main(){
    int test;
    cin>>test;
    while(test>0){ 
        int n;
        cout<<"size of array : ";
        cin>>n;
        vector<int> arr(n);
        for(int &num : arr){
            cin>>num;
        }
        arr = revarr(arr, 0, arr.size() - 1);

        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
        test--;
    }
}