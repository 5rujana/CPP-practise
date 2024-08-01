#include<bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin>>n;
    for(int i = 0; i<n ;i++){
        for(int j = n-i-1 ; j>0;j--){
            cout<<" ";
            // for first iteration i = 0 , j = 3 => j is iterating from 3 to >0  => '_ _ _'
            // for second iteration i = 1 , j = 2 => j is iterating from 2 to >0 => '_ _'
            // for third it  eration i = 2 , j = 1 => j is iterating from 1 to >0  => '_'
            // for fourth iteration i = 3 , j = 0 => so it comes out of loop
                    }
        for(int k = 0;k<2*i+1;k++){
            cout<<"x";
            // for first iteration i = 0, k < 2(0)+1 = 1 => k iterates from 0 to <1  =>      x
            // for second iteration i = 1, k < 2(1)+1 = 3 => k iterates from 0 to <3 =>    x x x
            // for third iteration i = 2, k < 2(2)+1 = 5 => k iterates from 0 to <5  =>  x x x x x
            // for fourth iteration i = 3, k < 2(3)+1 = 7 => k iterates from 0 to <7 =>x x x x x x x
            }
            
        cout<<endl;

    }

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < n - i; j++) {
            cout << " ";
            // for first iteration i = 3 , j < 0 => j is iterating from 0 to <1 => '_'
            // for second iteration i = 2, j < 1 => j is iterating from 0 to <2 => '_ _'
            // for third iteration i = 1, j < 2 => j is iterating from 0 to <3 =>  '_ _ _'
        }
        for (int k = 0; k < 2 * i - 1; k++) {
            cout << "x";
            // for first iteration i = 3 , k < 2(3)-1 = 5 => k is iterating from 0 to 5  => x x x x x
            // for second iteration i = 2 , k < 2(2)-1 = 3 => k is iterating from 0 to 3 =>   x x x
            // for third iteration i = 1 , k < 2(1)-1 = 1 =>k is iterating from 0 to 1   =>     x
            
        }
        cout << endl;
    }
}

// ouput:  
// 4
//        x
//      x x x
//    x x x x x
//  x x x x x x x 
//    x x x x x
//      x x x
//        x  