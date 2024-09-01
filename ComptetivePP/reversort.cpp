//sorting the array by reversing subarrays

#include<bits\stdc++.h>
using namespace std;

void reverse(vector<int>& arr,int l,int r){
    while(l<r){
        swap(arr[l],arr[r]);
        l++;
        r--;
    }
}

int reversort(vector<int> arr,int size){
     int totalcost = 0;
    for(int i=0;i<size-1;i++){
        int min = i;
        for(int j = i+1;j<size;j++){
            if(arr[min]>arr[j]){
                min = j;
            }
        }
        reverse(arr,i,min);
        totalcost = totalcost+(min-i+1);
    }
    return totalcost;
}

int reversortstl(vector<int>arr){
    int cost = 0;
    for(int i = 0;i<arr.size()-1;i++){
        //int n = min_element(i,arr.end());
    }
}
int main(void){
    int test;
    cin>>test;
    while(test>0){
        int size;
        cin>>size;
        vector<int> arr(size);
        for(int i = 0; i<size;i++){
            cin>>arr[i];
        }
        int totalcost = reversort(arr,size);
        cout<< "Total Cost :" << totalcost<<endl;
        test--;
    }
}