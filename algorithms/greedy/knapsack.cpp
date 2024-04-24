#include<bits/stdc++.h>
using namespace std;

struct Item{
    int weight;
    int profit;
};

bool compareItems(const Item& a , const Item& b){
    double ratioA = (double) a.profit/a.weight;
    double ratioB = (double) b.profit/b.weight;
    return ratioA>ratioB;
}

int Fracknapsack(int capacity, Item items[], int n){
    sort(items,items+n,compareItems);
    int totalProfit = 0;
    int currentWeight = 0;
    for(int i = 0; i<n ;i++){
        if(currentWeight +items[i].weight<=capacity){
            currentWeight+=items[i].weight;
            totalProfit+=items[i].profit;
        }else{
            int remainingCapacity = capacity-currentWeight;
            totalProfit += (double)remainingCapacity/items[i].weight*items[i].profit;
            break;
        }
    }
    return totalProfit;
}

int main() {
    int capacity, n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter weight and profit of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << ":" << endl;
        cout << "Weight: ";
        cin >> items[i].weight;
        cout << "Profit: ";
        cin >> items[i].profit;
    }
    
    double maxProfit = Fracknapsack(capacity, items, n);
    cout << "Maximum profit using fractional knapsack approach: " << maxProfit << endl;

    return 0;
}