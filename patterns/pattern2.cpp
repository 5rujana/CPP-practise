#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        for(int j = 0;j<=i;j++){
            // for first iteration  i = 0;j = 0 to 0 =>  x
            // for second iteration i = 1; j = 0 to 1 => x x
            // for third iteration  i = 2;j = 0 to 2  => x x x
            // for fourth iteration i = 3;j = 0 to 3  => x x x x

            cout<< " x";
        }
        cout<<endl;
    }
}




// output:
// 4
// x 
// x x 
// x x x
// x x x x