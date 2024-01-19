#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc , char * argv[]){
    if (argc !=2)
    {
        cout<< "Usage: "<< argv[0] << " <n> "<<endl;
        return 1;
    }

    int n = atoi(argv[1]);
    int count=0;
    
    for (int i = 1; i*i <= n ; i++)
    {
        if(n%i==0){
            count++;
            if (n/i !=i)
            {
                count++;
            }
            
        }
    }

    if (count==2)
    {
        cout<< "Prime number" << endl;
    }else{
        cout<< "Not Prime number" << endl;
    }
    
    
}