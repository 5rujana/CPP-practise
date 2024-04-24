#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b){
    int temp =a;
    a =b;
    b=temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low-1; //index of smaller element
    for(int j = low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]); //put the pivot element in its correct position
    return i+1;
}

void quicksort(int arr[],int low, int high){
    if(low<high){
        int partitionindex= partition(arr,low,high);
        quicksort(arr,low,partitionindex-1);
        quicksort(arr,partitionindex+1,high);
    }
}


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <space-separated list of numbers>\n";
        return 1;
    }

    int size = argc - 1;
    int arr[size];

    for (int i = 0; i < size; ++i) {
        arr[i] = std::atoi(argv[i + 1]);
    }

    std::cout << "Original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    quicksort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
