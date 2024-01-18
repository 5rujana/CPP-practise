#include<iostream>
#include<bits/stdc++.h>

using namespace std;

string reverseNum(int n){
    int n1 =n;
    int sum=0,rem=0;
    while(n != 0){
        rem=n%10;
        sum = rem*rem*rem+sum;
        n=n/10;

    }
    if(n1==sum){
        return "true";
    
    }
    return "false";
}

int main(int argc , char * argv[]){
    if(argc != 2){
        cout<< " file name <n> " << endl;
        return 1;
    }
    int num = atoi(argv[1]);
    cout<<reverseNum(num)<<endl;
}