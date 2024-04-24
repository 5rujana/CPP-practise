#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int low, int middle,int high){
    int leftArrsize = middle-low+1;
    int rightArrsize = high-middle;
    int leftArray[leftArrsize], rightArray[rightArrsize];
    for(int i = 0; i<leftArrsize;i++){
        leftArray[i]=arr[low+i];
    }
    for(int i = 0;i<rightArrsize;i++){
        rightArray[i]=arr[middle+i+1];
    }
    int i = 0, j = 0, k = low;
    //k is index of merged subarray
    while(i<leftArrsize&&j<rightArrsize){
        if(leftArray[i]<=rightArray[j]){
            arr[k]=leftArray[i];
            i++;
        }else{
            arr[k]=rightArray[j];
            j++;
        }
        k++;
    }
    while(i<leftArrsize){
        arr[k]=leftArray[i];
        i++;
        k++;
    }

    while(j<rightArrsize){
        arr[k]=rightArray[j];
        j++;
        k++;
    }
}
void mergesort(int arr[], int low, int high){
    if(low<high){
        int middle = low+(high-low)/2;
        mergesort(arr,low,middle);
        mergesort(arr,middle+1,high);
        merge(arr,low,middle,high);
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <space-separated list of numbers>\n";
        return 1;
    }

    int size = argc - 1;
    int arr[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = atoi(argv[i + 1]);
    }

    cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    mergesort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
