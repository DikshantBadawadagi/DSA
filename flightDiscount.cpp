#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;


int main() {
    ll n,m;
    cin>>n>>m;
    vector<vector<pair<ll,ll>>>adj(n+1);

    for(ll i=0;i<m;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        //from a to b with cost of c

        adj[a].push_back({b,c});
    }
    vector<vector<ll>>dist(n+1,vector<ll>(2,LONG_LONG_MAX));
    // dist[node][0] = min dist to node with unused coupon
    // dist[node][1] = min dist to node with used coupon

    dist[1][0] = 0;
    priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<tuple<ll,ll,ll>>>pq;
    pq.push({0,1,0}); // {cost,node,coupon_used}

    while(!pq.empty()){
        auto [cost, node,used] = pq.top();
        pq.pop();
        if(cost > dist[node][used])continue; //already have a better path
        
            for(auto it : adj[node]){
                ll nnode = it.first;
                ll c = it.second;
                if(!used){
                    if(cost + c < dist[nnode][0]){
                        dist[nnode][0] = cost + c;
                        pq.push({dist[nnode][0],nnode,0});
                    }
                    if(cost + c/2 < dist[nnode][1]){
                        dist[nnode][1] = cost + c/2;
                        pq.push({dist[nnode][1],nnode,1});
                    }
                }else{
                    if(cost + c < dist[nnode][1]){
                        dist[nnode][1] = cost + c;
                        pq.push({dist[nnode][1],nnode,1});
                    }
                }
            }
        }
        cout<<min(dist[n][0],dist[n][1])<<endl;
}