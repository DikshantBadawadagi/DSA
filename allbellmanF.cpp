#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<tuple<int, int, int>> edges = {
    //from , to , cost
    {0, 2, 2},
    {0, 4, 1},
    {1, 3, 4},
    {1, 5, 5},
    {2, 4, 3},
    {2, 5, 1},
    {3, 4, 3}
};

vector<int>dist(6,1e9);
dist[0] = 0;

for(int i =0;i<6;i++){
    for(auto &[u,v,cost] : edges){
        if(dist[u] + cost < dist[v]){
            dist[v] = dist[u] + cost;
        }
    }
}
for(auto &[u,v,cost] : edges){
        if(dist[u] + cost < dist[v]){
            cout<<"Negative cycle detected"<<endl;
            return 0;
        }
    }
    for(int i=0;i<6;i++){
        cout<<dist[i]<<" ";
    }
}