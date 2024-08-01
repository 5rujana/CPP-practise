// reversing array using single pointer
#include<bits\stdc++.h>
using namespace std;

vector<int> revarr(vector<int> arr, int i){
    if(i>=arr.size()/2){
        return arr;
    }
    int temp = arr[i];
    arr[i] = arr[arr.size()-i-1];
    arr[arr.size()-i-1] = temp;
    return revarr(arr,i+1);

}

int main(){
    int test;
    cin>>test;
    while(test>0){ 
        int n;
        cout<<"size of array : ";
        cin>>n;
        vector<int> arr(n);
        for(int &num : arr){
            cin>>num;
        }
        arr = revarr(arr, 0);

        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;
        test--;
    }
}