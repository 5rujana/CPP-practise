// find second last elemet of the array

#include<bits\stdc++.h>
using namespace std;

//better approach with O(2N) T.C
int bettersecondLargest(int arr[],int size){
    int max = arr[0];
    for(int i = 0; i<size;i++){
        if(max<arr[i]){
            max=arr[i];        }
    }
    int secmax = -1;
     for(int i = 0; i<size;i++){
        if(secmax<arr[i]&&arr[i]!=max){
            secmax=arr[i];        
        }else if(max>arr[i]&& arr[i]>secmax){
            secmax=arr[i];   
        }
    }
    return secmax;
}
//optimal approach
int optimalsecondLargest(int arr[],int size){
    int max = arr[0]; int secmax = -1;
    for(int i = 0; i<size;i++){
        if(max<arr[i]){
            secmax = max;
            max=arr[i];
        }
    }

    return secmax;
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
        int seclarge = optimalsecondLargest(arr,size);
        cout<<"second largest : " <<seclarge<<endl;

        delete[] arr;
        test--;
    }
}