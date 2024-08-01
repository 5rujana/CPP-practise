// using hashmap count elements of array

#include<bits/stdc++.h>
using namespace std;

void countElem(int arr[],int size){
    map<int,int> m;
    for(int i = 0; i<size;i++){
        m[arr[i]] +=1;
    }
    for(auto it:m){
        cout<<it.first<<"->"<<it.second<<endl;
    }
    int q;
    cin>>q;
    while(q--){
        int num;
        cin>>num;
        cout<<m[num]<<" ";
    }
}

int main(void){
    int test;
    cin>>test;
    while(test>0){
        int size;
        cin>>size;
        int arr[size];
        for(int i = 0; i<size;i++){
            cin>>arr[i];
        }
        countElem(arr,size);
        test--;
    }
}