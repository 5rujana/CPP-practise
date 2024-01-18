#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int count(int n){
    int count= (int) (log10(n) + 1);
    
    return count;
}

int main(int argc , char * argv[]){
    if(argc != 2){
        cout<< " file name <n> " << endl;
        return 1;
    }

    int num = atoi(argv[1]);
    cout<< count(num) << endl;
}

