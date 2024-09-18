#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<int,int>,int>> prims(int n,int m,vector<pair<pair<int,int>,int>>&g){
    
    unordered_map<int,list<pair<int,int>>>adj;

    for(int i=0;i<g.size();i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    vector<int>key(n+1,INT_MAX);
    vector<bool>mst(n+1,false);
    vector<int>parent(n+1,-1);

    key[1] = 0;
    parent[1]=-1;

    for(int i=0;i<=n;i++){
        int mini = INT_MAX;
        int u;
        for(int j=1;j<=n;j++){
        if(key[j]<mini && mst[j]!=false){
           mini = key[j];
           u = j;
        }
        }
        mst[u] = true;

        for(auto it : adj[u]){
            int v = it.first;
            int w = it.second;
            if(mst[v]==false&&key[v]<mini){
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int,int>,int>> result;
    for(int i=2;i<=n;i++){
        result.push_back(make_pair(make_pair(parent[i],i),key[i]));
    }
    return result;

}
int main(){

}