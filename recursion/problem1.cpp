// print name n times using recursion

#include<bits/stdc++.h>
using namespace std;

void printname(int n){
    if(n==0){
        return;
    }
    n--;
    cout<<"Srujana Gayatri"<<endl;
    printname(n);
}

int main(){
    int test;
    cout<<" test counts:"<<endl;
    cin>>test;
    while(test>0){

        int n;
        cin>>n;
        printname(n);
        test--;
    }
    return 0;
}