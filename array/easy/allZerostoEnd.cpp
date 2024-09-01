// move all zeros to the end


#include<bits\stdc++.h>
using namespace std;

int allZeroBF(int arr[],int size){
    vector<int> temp;
    for(int i = 0; i<size;i++){
        if(arr[i]!= 0){
            temp.push_back(arr[i]);
        }
    }

    for(int i = 0; i<temp.size();i++){
        arr[i]=temp[i];
    }

    for(int i = temp.size(); i<size;i++){
        arr[i]=0;
    }

    for(int i = 0; i<size;i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

void allZerosOPT(int arr[],int size){


    int j = -1;
    for(int i = 0;i<size;i++){
        if(arr[i]==0){
            j = i;
            break;
        }
    }

    for(int i = j+1;i<size;i++){
        if(arr[i!=0]){
            swap(arr[i],arr[j]);
            j++;
        }
    }




    for(int i = 0; i<size;i++){
            cout<< arr[i]<<" ";
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
        allZerosOPT(arr,size);

        delete[] arr;
        test--;
    }
}