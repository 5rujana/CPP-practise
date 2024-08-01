#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    for(int i = 0; i<n ;i++){
        for(int j = n-i-1 ; j>0;j--){
            cout<<" ";
            
        }
        for(int k = 0;k<i;k++){
                cout<<"x";
            }
        cout<<endl;
    }

}

// ouput:
// 4
//       x 
//     x x
//   x x x
// x x x x