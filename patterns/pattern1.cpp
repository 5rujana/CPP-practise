#include<bits/stdc++.h>
using namespace std;

void pattern_method_one(int n){
    for(int i = 0;i<n;i++){
        for(int j = i; j<n;j++){
            //first iteration i = 0 j = 0 => so 0 to 4  => x x x x
            //second iteration i = 1 j = 1 => so 1 to 4 => x x x 
            //third iteration i = 2 j = 2 => so 2 to 4  => x x 
            //fourth iteration i = 3 j = 3 => so 3 to 4 => x 

            cout<<" x";
        }
        cout<<endl;
    }
}

void pattern_method_two(int n){
    for(int i = 0; i<n; i++){
        for(int j = n-i;j>0;j--){
            // first iteration i = 0 ; j = 4 => so 4 to 0 => x x x x
            // second iteration i = 1; j = 3 => so 3 to 0 => x x x
            // third iteration i = 2; j = 2  => so 2 to 0 => x x
            // fourth iteration i = 3; j = 1 => so 1 to 0 => x
            cout<< " x";
        }
        cout<<endl;
    }
}

void pattern_method_three(int n){
    for(int i = 0; i<n; i++){
        for(int j = n;j>i;j--){

            cout<< " x";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    pattern_method_one(n);
    cout<<"----------------------------------------------------------"<<endl;
    pattern_method_two(n);
    cout<<"----------------------------------------------------------"<<endl;
    pattern_method_three(n);
    return 0;
}

// output:
// 4
// x x x x
// x x x
// x x
// x

