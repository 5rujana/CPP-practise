// bubble sort
#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[],int size){
     for(int i = 0;i<size-1;i++){
        bool swapped = false;
        for(int j = 0;j<size-i-1;j++){ //pushing max element to the end  
            if(arr[j+1]<arr[j]){
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=arr[j+1];
                swapped = true;
            }
        }
        if (!swapped) {// If no two elements were swapped by inner loop, then the array is sorted
            break;
        }
     }

     for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
     }
     cout<<endl;
}

int main(void){
    int test;
    cin>>test;
    while(test>0){
        int size;
        cin>>size;
        int arr[size];
        for(int i = 0;i<size;i++){
            cin>>arr[i];
        }
        bubbleSort(arr,size);
        test--;
    }
}