// print linearly from 1 to n (backtack manner)

#include<bits/stdc++.h>
using namespace std;

void printnum(int n){
    if(n==0){
        return;
    }
    printnum(n-1);
    cout<<n<<endl;
}

int main(){
    int test;
    cout<<" test counts:"<<endl;
    cin>>test;
    while(test>0){

        int n;
        cin>>n;
        printnum(n);
        test--;
    }
    return 0;
}