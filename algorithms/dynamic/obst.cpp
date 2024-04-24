#include<bits/stdc++.h>
using namespace std;
#define MAX 100

int obst(int n, float success[],float failure[]){
    float expectedCost [MAX][MAX]; //stores expected cost of searching a subtree that spans from node i to j
    float cumilativeProbab [MAX][MAX];// represents sum of probabilities of searching for each key in the subtree node i to j
    int Root[MAX][MAX];
    //each diagonal element  is set to probability of unsuccessful search for that corresponding node
    for(int i =1;i<=n;i++){ 
        expectedCost[i][i-1] = failure[i-1];
        cumilativeProbab[i][i-1] = failure[i-1];
    }
    for(int l = 1;l<=n;l++){//itrates over length of subtrees
        for(int i = 1; i<=n-l+1 ; i++){ //iterates over the starting indices of the subtrees
            int rootindex = i+l-1;// the index of the root of the current subtree. The root of the subtree starting at index i and having length l will be at index root
            expectedCost[i][rootindex]=9999;
            cumilativeProbab[i][rootindex] = cumilativeProbab[i][rootindex-1]+success[rootindex]+failure[rootindex];
            for(int r = i; r<= rootindex;r++){
                float t = expectedCost[i][r-1]+expectedCost[r+1][rootindex]+cumilativeProbab[i][rootindex];
                if(t<expectedCost[i][rootindex]){
                    expectedCost[i][rootindex]=t;
                    Root[i][rootindex ]=r;
                }
            }
        }
    }
    return expectedCost[1][n];

}

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    float p[n + 1], q[n + 1];
    cout << "Enter the probability of successful search: ";
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    cout << "Enter the probability of unsuccessful search: ";
    for (int i = 0; i <= n; i++) {
        cin >> q[i];
    }
    cout << "The cost of optimal binary search tree is: " << obst(n, p, q) << endl;
    return 0;
}
