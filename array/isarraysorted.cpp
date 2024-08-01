//check if array is sorted


#include<bits\stdc++.h>
using namespace std;

bool issorted(int arr[],int size){
    for(int i = 1;i<size;i++){
        if(arr[i-1]>arr[i]){
            return false;}   
    }
    return true;
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
        if(issorted(arr,size)){
            cout<<"Array is sorted";
        }else{
            cout<<"Array is not sorted";
        }

        delete[] arr;
        test--;
    }
}   