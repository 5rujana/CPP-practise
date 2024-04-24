#include<bits/stdc++.h>
using namespace std;

struct job{
    int profit;
    int deadlines;
    int id;
};

int maxdeadline(job jobs[],int n){
    int max = 0;
    for(int i = 0;i<n;i++){
        if(max< (jobs[i].deadlines)){
            max = jobs[i].deadlines;
        }
    }
    return max;
}

bool compareProfits(job& a , job& b){
    return a.profit>b.profit;
}

int Maxprof(job jobs[], int n) {
    int max = maxdeadline(jobs, n);
    sort(jobs, jobs + n, compareProfits);
    signed int assigned[max];
    for (int i = 0; i < max; i++) {
        assigned[i] = -1;
    }
    int maxprof = 0;
    for (int i = 0; i < n; i++) {
        for (int j = min(max, jobs[i].deadlines) - 1; j >= 0; --j) { // Corrected condition
            if (assigned[j] == -1) {
                assigned[j] = jobs[i].id;
                maxprof += jobs[i].profit;
                break;
            }
        }
    }

    cout << "Job sequence: ";
    for (int i = 0; i < max; ++i) {
        if (assigned[i] != -1) {
            cout << assigned[i] << " ";
        }
    }
    cout << endl;
    return maxprof;
}

int main(){
    int n;
    cout<<"Enter the number of jobs: ";
    cin>>n;

    job jobs[n];
    cout << "Enter the profit and deadline of each job:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Job " << i + 1 << ":" << endl;
        cout << "Profit: ";
        cin >> jobs[i].profit;
        cout << "Deadline: ";
        cin >> jobs[i].deadlines;
        jobs[i].id = i + 1; // Assigning job IDs
    }

    int maxProfit = Maxprof(jobs, n);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}