#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
                       //to,cost
    vector<vector<pair<int,int>>>adj(n+1);

    for(int i=0;i<m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<int>dist(n+1, 1e9);

    pq.push({0,1}); // {cost, node}
    dist[1] = 0;

    while(!pq.empty()){
        auto topo = pq.top();
        pq.pop();
        int cost = topo.first;//cost from source till node
        int node = topo.second;
        if(dist[node] < cost)continue;

        for(auto it : adj[node]){
            int neigh = it.first;
            int c = it.second;//cost from node to neigh

            if(cost + c < dist[neigh]){
                dist[neigh] = cost + c;
                pq.push({dist[neigh],neigh});
            }
        }
    }
    for(auto it : dist){
        cout<<it<< " ";
    }
}