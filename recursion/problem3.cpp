// print linearly from n to 1 (backtack manner)
#include<bits/stdc++.h>
using namespace std;

void printnum(int n){
   if(n==0){
    return;
   }
   cout<< n << endl;
   printnum(n-1);
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