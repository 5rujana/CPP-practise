#include<bits/stdc++.h>
using namespace std;

int mincost = INT_MAX;
// int minAssignment[MAX];
void swap(int a , int b){
    int temp = a;
    a = b;
    b = temp;
}

void calculateCost(const vector<vector<int>>& cost,const vector<int>& assignment, int n, int current,vector<int>& minAssignment){
    if(current ==n){
        int CurrentCost = 0;
        for(int i = 0; i<n;i++){
            CurrentCost += cost[i][assignment[i]];
        }
        if(CurrentCost<mincost){
            mincost =CurrentCost;
            for(int i = 0; i<n;i++){
                minAssignment[i]= assignment[i];
            }
        }
        return;
    }
    for(int i = current; i < n; i++){
        swap(assignment[i], assignment[current]);
        calculateCost(cost, assignment, n, current+1,minAssignment);
        swap(assignment[i], assignment[current]);
    }
}


int main(){
    int n;
    printf("Enter the number of jobs: ");
    cin>>n;
    vector<vector<int>> cost(n,vector<int>(n));
    cout<<"Enter the cost matrix: ";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin>>cost[i][j];
        }
    }
    vector<int> assignment(n);
    for(int i = 0; i < n; i++){
        assignment[i] = i;
    }
    vector<int> minAssignment(n);
    calculateCost(cost, assignment, n, 0,minAssignment);
    cout<<"Minimum cost: "<< mincost<<endl;
    cout<<"Assignment: ";
    for(int i = 0; i < n; i++){
        cout<< minAssignment[i];
    }
    cout<<endl;
    return 0;
}
   