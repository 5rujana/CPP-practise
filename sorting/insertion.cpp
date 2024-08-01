// insertion sort

#include<bits\stdc++.h>
using namespace std;

void insertionSort(int arr[],int size){
    for(int i = 0;i<size-1;i++){
        int j=i;
        while(j>0&&arr[j-1]>arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }

    for(int i = 0; i<size;i++){
        cout<< arr[i] << " ";
    }
    cout<<endl;
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
        insertionSort(arr,size);
        delete[] arr;
        test--;
    }
}