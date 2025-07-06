#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n,m;
    cin>>n>>m;
                       //to,cost
    vector<vector<pair<long long,long long>>>adj(n+1);

    for(long long i=0;i<m;i++){
        long long u,v,c;
        cin>>u>>v>>c;
        adj[u].push_back({v,c});
    }
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
    vector<long long>dist(n+1, 1e18);

    pq.push({0,1}); // {cost, node}
    dist[1] = 0;
    while(!pq.empty()){
        auto topo = pq.top();
        pq.pop();
        long long cost = topo.first;
        long long node = topo.second;
        if(cost > dist[node]) continue; // If the cost is greater than the recorded distance, skip

        for(auto it : adj[node]){
            long long neigh = it.first;
            long long c = it.second;
            if(cost + c < dist[neigh]){
                dist[neigh] = dist[node] + c;
                pq.push({dist[neigh], neigh});
            }
        }
    }
    for(long long i=1;i<=n;i++){
        if(dist[i] == 1e18){
            cout<<"-1 ";
        } else {
            cout<<dist[i]<<" ";
        }
    }
    
}