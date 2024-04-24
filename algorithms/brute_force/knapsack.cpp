#include<bits/stdc++.h>
using namespace std;

int max(int a, int b){
    return (a>b)? a:b;
}

int knapsack(int W, int wt[],int prof[],int n){
    if(n==0||W==0){
        return 0;
    }
    if(wt[n-1]>W){
        return knapsack(W,wt,prof,n-1);
    }else{
        return max(prof[n-1]+knapsack(W-wt[n-1],wt,prof,n-1), knapsack(W,wt,prof,n-1));
    }
}

int main(){
    int n;
    cout<<"Enter the number of items: ";
    cin >> n;

    int * profit = new int[n];
    int * weight = new int[n];

    cout<<"Enter the profit and weight of each item: "<<endl;
    for(int i = 0; i < n; i++) {
        cout<<"Item "<<i+1<<" : ";
        cin >> profit[i] >> weight[i];
    }

    int W;
    cout<<"Enter the knapsack capacity: ";
    cin >> W;
    cout<<"Maximum profit: "<<knapsack(W, weight, profit, n)<<endl;

    delete[] profit;
    delete[] weight;
    return 0;
}