//find the largest element of the array

#include<bits\stdc++.h>
using namespace std;

int largestElement(int arr[],int size){
    int max = arr[0];
    for(int i = 0; i<size;i++){
        if(max<arr[i]){
            max=arr[i];        }
    }
    return max;
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
        int largeE = largestElement(arr,size);
        cout<< "Largest element : " << largeE <<endl;
        delete[] arr;
        test--;
    }
}