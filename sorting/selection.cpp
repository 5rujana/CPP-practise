// selection sort

#include<bits\stdc++.h>
using namespace std;

void selectionSort(int arr[],int size){
    for(int i = 0; i<size-1;i++){
       int min = i;
       for(int j = i+1;j<size;j++){
            if(arr[min]>arr[j]){
                min = j;
            }
       } 
       int temp = arr[i];
       arr[i]= arr[min];
       arr[min]=temp;
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
        selectionSort(arr,size);
        delete[] arr;
        test--;
    }
}