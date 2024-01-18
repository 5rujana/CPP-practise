#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;
void printAllDivisors(int n){
    //euclid algorithm
    vector<int> ls;

    // O(sqrt(n))
    for(int i = 1; i*i<=n ; i++){
        if(n % i ==0){
            ls.push_back(i);
            if((n/i) != i){
                ls.push_back(n/i);
            }
        }

    }

    // O(n)
    sort(ls.begin() , ls.end());
    for(auto it : ls) cout << it << " ";
    cout<< endl;
}

int main(int argc , char * argv[]){
    if(argc != 2){
        cout<< " file name <n> " <<endl;
        return 1;
    }
    int num = atoi(argv[1]);
   printAllDivisors(num);
}