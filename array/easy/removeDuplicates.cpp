// remove duplicates from the array

#include<bits\stdc++.h>
using namespace std;

// set data structure stores unique values
// brute-force approach
int removeDuplicatesBF(int arr[],int size){
    set<int> st;
    for(int i = 0;i<size;i++){
        st.insert(arr[i]);
    }

    for(auto it : st){
        cout<< it<<" ";
    }
    cout<<endl;
    int index = 0;
    for(auto it : st){
        arr[index] = it;
        index++;
    }
    return index;
}

int removeDuplicatesOPT(int arr[],int size){
    int i = 0;
    for(int j = 1; j<size;j++){
        if(arr[j]!=arr[i]){
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}

int main(void){
    int test;
    cin>>test;
    while(test>0){
        int size;
        cin>>size;
        int* arr = new int[size];
        for(int i = 0; i<size;i++){
            cin>>arr[i];
        }
        removeDuplicatesOPT(arr,size);

        delete[] arr;
        test--;
    }
}