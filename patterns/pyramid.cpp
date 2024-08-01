#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    for(int i = 0; i<n ;i++){
        for(int j = n-i-1 ; j>0;j--){
            cout<<" ";
            
        }
        for(int k = n;k<2*i+1;k++){
                cout<<"x";
            }
        cout<<endl;
    }

}

// ouput:
// 5
//     x
//    xxx
//   xxxxx
//  xxxxxxx
// xxxxxxxxx