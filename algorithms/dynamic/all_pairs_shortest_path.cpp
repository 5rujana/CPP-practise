#include<bits/stdc++.h>
using namespace std;

#define INF 99999

void printSolution(vector<vector<int>>& dist){
    cout<< "The following matrix shows the shortest distances"
            "between every pair pf vertices"<<endl;
    for(int i = 0 ; i<dist.size();i++){
        for(int j = 0 ;j < dist.size();j++){
            if(dist[i][j]==INF){
                cout<<"INF\t";
            }else{
                cout<<dist[i][j]<<"\t";
            }
        }
        cout<<endl;
    }
}

void floydWarshall(const vector<vector<int>>& graph){
    int v = graph.size();
    vector<vector<int>> dist(v, vector<int> (v));
    for(int i = 0;i<v;i++){
        for(int j = 0; j<v;j++){
            dist[i][j]=graph[i][j];
        }
    }

    for(int k = 0; k<v;k++){
        for(int i = 0; i<v;i++){
            for(int j = 0 ; j<v;j++){
                if(dist[i][k]!=INF &&dist[k][j]!=INF){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    printSolution(dist);
}

int main(){
    int V;
    cout<<"enter number of vertices"<<endl;
    cin>>V;
    vector<vector<int>> graph(V, vector<int> (V));
    cout << "Enter the adjacency matrix (Enter INF for no direct edge): " << endl;
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            cin >> graph[i][j];
            if(graph[i][j] == -1) // Assuming -1 represents INF
                graph[i][j] = INF;
        }
    }
    floydWarshall(graph);
    return 0;
}