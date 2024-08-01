
#include<bits/stdc++.h>
using namespace std;

int sumofN(int n){
    if(n==0){
        return 0;
    }
    return n + sumofN(n-1);
}

int main(){
    int test;
    cin>>test;
    while(test>0){ 
        int n;
        cin>>n;
        cout<<sumofN(n)<<endl;
        test--;
    }
}