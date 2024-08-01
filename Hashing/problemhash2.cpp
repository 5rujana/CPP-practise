// using hashmap count chars of string
#include<bits/stdc++.h>
using namespace std;

void countChar(string s){
    map<char,int> m;
    for(char c : s){
        m[c]+=1;
    }
    
    for(auto it: m){
        cout<<it.first<<" -> "<<it.second<<endl;
    }
}

int main(void){
    int test;
    cin>>test;
    while(test>0){
        string s;
        cin>>s;
        countChar(s);
        test--;
    }
}