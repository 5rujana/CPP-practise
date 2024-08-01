
#include<bits\stdc++.h>
using namespace std;

string revstring(string s , int i){
    if(i>=s.size()/2){
        return s;
    }
    char temp = s[i];
    s[i] = s[s.size()-i-1];
    s[s.size()-i-1] = temp;
    return revstring(s,i+1);
}

bool isPalindrome(const string& s) {
    string reversed = revstring(s, 0);
    return reversed == s;
}

int main() {
    int test;
    cin >> test;
    cin.ignore(); // To ignore the newline character after the integer input

    while (test > 0) {
        string str;
        cout << "Enter a string: ";
        getline(cin, str);
        if(isPalindrome(str)){
            cout<<"Palindrome"<<endl;
        }else{
            cout<< "is not Palindrome"<<endl;
        }
        test--;
    }
 
    return 0;
}