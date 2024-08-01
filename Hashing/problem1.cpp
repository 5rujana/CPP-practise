// count elements of array

#include<bits\stdc++.h>
using namespace std;
 
void countElements(int arr[],int size){
        //precompute
    int hash[13] = {0};
    for(int i = 0; i <size;i++){
        hash[arr[i]] +=1;
    }

    int qsize;
    cout<< "querysize : ";
    cin>>qsize;
    cout<<endl<<"elements : ";
    while(qsize--){
        int num;
        
        cin>>num;
        //fetch
        cout<<hash[num]<<endl;
    }
 }

int main(void){
    int test;
    cin>>test;
    while(test>0){
        int size;
        cout<<"size of array "; 
        cin>>size;
        int arr[size];
        for(int i = 0;i<size;i++){
            cin>>arr[i];
        }

        countElements(arr,size);

        test--;
    }
}