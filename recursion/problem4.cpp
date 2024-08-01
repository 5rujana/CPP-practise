// sum of first n numbers (parameterized)

#include<bits/stdc++.h>
using namespace std;

void sumofN(int n,int sum){
    
    if(n<1){
        cout<< sum<<endl;
        return;
    }
    sumofN(n-1,sum+n);
    
}
int main(){
    int test;
    cin>>test;
    while(test>0) { 
        int n;
        cin>>n;
        sumofN(n,0);
        test--;
    }
}   