// Left rotate the array by k places

#include<bits\stdc++.h>
using namespace std;

//brute force method
void leftRotateBF(vector<int> arr,int size, int k){
    k = k%size;
    int temp[k];
    for(int i = 0; i<k ;i++){
        temp[i]=arr[i];
    }
    for(int i = k;i<size;i++){
        arr[i-k] = arr[i];
    }
    int index=0;
    for(int i = size-k ; i<size;i++){
        arr[i] = temp[index];
        index++;
    }
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//optimal solution
vector<int> reverse(vector<int> arr,int f , int l){
    if( f>= l){
        return arr;
    }
    int temp = arr[l];
    arr[l]=arr[f];
    arr[f]=temp;
    return reverse(arr,f+1,l-1);
}

void leftRotateOPT(vector<int> arr,int size, int k){
    k = k%size;
    arr = reverse(arr,0,k-1);
    arr = reverse(arr,k,size-1);
    arr = reverse(arr,0,size-1);

    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(void){
    int test;
    cin>>test;
    while(test>0){
        int size;
        cin>>size;
        vector<int> arr(size);
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
        
        int k;
        cout << "k : ";
        cin >> k;
        leftRotateOPT(arr,size,k);

        test--;
    }
}