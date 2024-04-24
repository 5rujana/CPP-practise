#include<bits/stdc++.h>
using namespace std;

int mincostvertex(const vector<int>& cost,int v,const vector<bool>& mstSet){
    int min = INT_MAX;
    int min_vertex;
    for(int i = 0 ; i<v ;i++){
        if(!mstSet[i]&&cost[i]<min){
            min=cost[i];
            min_vertex = i;
        }
    }
    return min_vertex;
}

void primsalgorithm(const vector<vector<int>>& graph, int v){
    vector<int> parent(v);
    vector<int> cost(v,INT_MAX);
    vector<bool> mstSet(v,false);

    //intializing cost and mstSet
    // for(int i = 0;i<v;i++){
    //     cost[i]=INT_MAX;
    //     mstSet[i] =false;
    // }

    //first node is root for mst
    cost[0]=0;
    parent[0]=-1;
    for(int edge = 0;edge<v-1;edge++){
        int min_vertex = mincostvertex(cost,v,mstSet);
        mstSet[min_vertex]=true;
        for(int vertex = 0;vertex<v;vertex++){
            if(graph[min_vertex][vertex]&&mstSet[vertex]==false&&graph[min_vertex][vertex]<cost[vertex]){
                parent[vertex] = min_vertex;
                cost[vertex]=graph[min_vertex][vertex];
            }
        }
    }
    cout<<"Edge\t Weight"<<endl;
    int totalCost = 0;
    for(int i = 1;i<v;i++){
        cout<<parent[i]<<" - "<<i<<"\t"<<graph[i][parent[i]]<<endl;
        totalCost+=graph[i][parent[i]];
    }
    cout<<"Total Cost of MST: "<<totalCost<<endl;
}

int main(){
    int v;
    cout<<"enter number of vertices"<<endl;
    cin>>v;
    vector<vector<int>> graph(v,vector<int> (v));
    /*
    No, you can't directly give v as the second argument when initializing a 2D vector 
    using vector<vector<int>> graph(v, v).

    The reason is that the second argument of the constructor for a 2D vector 
    (vector<vector<int>>) is expected to be a vector of integers, specifying the 
    initial values for each row. In your case, v is an integer representing the 
    number of rows you want in the 2D vector, not the values for each row.

    To initialize a 2D vector with v rows and v columns, you need to provide a vector 
    of size v as the second argument, where each element of the vector is another vector 
    of integers representing the columns.
    
    */
    cout<<"enter the adjacent matrix"<<endl;
    for(int i = 0 ; i < v ; i++){
        for(int j = 0 ; j < v ; j++){
        cin>>graph[i][j];
        }
    }
    
    primsalgorithm(graph,v);
    return 0;

}