// count char of string

#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

void countChar(string s) {
    int hash[26] = {0}; 

    for (char c : s) {
        if (c >= 'a' && c <= 'z') { 
            hash[c - 'a'] += 1;
        }
    }

    int qsize;
    cout << "querysize: ";
    cin >> qsize;

    cout << endl << "char: ";
    while (qsize--) {
        char c;
        cin >> c;

        if (c >= 'a' && c <= 'z') {
            cout << hash[c - 'a'] << " ";
        } else {
            cout << 0 << endl; 
        }
    }
}

int main() {
    int test;
    cin >> test;
    while (test > 0) {
        string s;
        cin >> s;
        countChar(s); 
        test--;  
    }
    return 0;
}
