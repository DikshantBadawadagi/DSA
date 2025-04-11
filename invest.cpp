#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long mod = 1e9+7;

int main() {
    long long n,m;
    cin>>n>>m;

    vector<vector<pair<long long,long long>>>adj(n+1);

    for(long long i=0;i<m;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        // a->b with weight c
        adj[a].push_back({b,c});
    }
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>>pq;
    vector<long long>dist(n+1,INT_MAX);
    vector<long long>ways(n+1,0);
    vector<long long>min_flight(n+1,LONG_LONG_MAX);
    vector<long long>max_flight(n+1,LONG_LONG_MIN);
    dist[1]=0;
    ways[1]=1;
    min_flight[1]=0;
    max_flight[1]=0;
    pq.push({0,1}); // {distance, node}

    while(!pq.empty()){
        long long d = pq.top().first;
        long long node = pq.top().second;
        pq.pop();
        if(d > dist[node]) continue;

        for(auto it : adj[node]){
            long long c = it.second; // weight of edge
            long long v = it.first; // destination node
            if(dist[node] + c < dist[v]){
                dist[v] = dist[node] + c;
                ways[v] = ways[node];
                min_flight[v] = min_flight[node] + 1;
                max_flight[v] = max_flight[node] + 1;
                pq.push({dist[v],v});
            }
            else if(dist[node] + c == dist[v]){
                ways[v] = (ways[v] + ways[node]) % mod;
                min_flight[v] = min(min_flight[v],min_flight[node] + 1);
                max_flight[v] = max(max_flight[v],max_flight[node] + 1);
            }
        }
    }
    cout<<dist[n]<<" "<<ways[n]<<" "<<min_flight[n]<<" "<<max_flight[n]<<"\n";
    return 0;
}

