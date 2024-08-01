// factorial of n

#include<bits/stdc++.h>
using namespace std;

int factorial(int n){
    if (n==0) return 1;
    return n*factorial(n-1);
}

int main(){
    int test;
    cin>>test;
    while(test>0){ 
        int n;
        cin>>n;
        cout<<factorial(n)<<endl;
        test--;
    }
}
