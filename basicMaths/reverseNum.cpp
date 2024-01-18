#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int reverseNum(int n){
    int sum=0,rem=0;
    while(n != 0){
        rem=n%10;
        sum = rem+sum*10;
        n=n/10;

    }
    return sum;
}

int main(int argc , char * argv[]){
    if(argc != 2){
        cout<< " file name <n> " << endl;
        return 1;
    }
    int num = atoi(argv[1]);
    cout<< "Reverse of a number : " <<reverseNum(num)<<endl;
}