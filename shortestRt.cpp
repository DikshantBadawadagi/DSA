#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n,m; cin>>n>>m;
    vector<vector<pair<long long,long long>>> adj(n+1);
    vector<long long>dist(n+1,LONG_LONG_MAX);

    for(long long i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        // from a to b with wieght c
        adj[a].push_back({b,c});
    }
    //weight first then node
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
    //weight first then node
    pq.push({0,1});
    dist[1] = 0;

    while(!pq.empty()){
        long long wt = pq.top().first;
        long long node = pq.top().second;
        pq.pop();
        
        if (wt > dist[node]) continue;

        for(auto it : adj[node]){
            long long nnode = it.first;
            long long w = it.second;
            if(wt + w < dist[nnode]){
                dist[nnode] = wt + w;
                pq.push({dist[nnode],nnode});
            }
        }
    }
    for(long long i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    return 0;
}
