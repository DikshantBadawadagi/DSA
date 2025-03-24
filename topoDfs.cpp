#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&topo){
vis[node] = 1;


for(auto it : adj[node]){
    if(!vis[it]){
        dfs(it,adj,vis,topo);
    }
}

topo.push_back(node);
}

int main () {
    int n;
    cin>>n;

    vector<vector<int>>adj = {{},{},{3},{1},{0,1},{0,2}};
    vector<int>topo;
    vector<int>vis(n,0);
    for(int i=0;i<n;i++){
        if(!vis[i])
        dfs(i,adj,vis,topo);
    }
    reverse(topo.begin(),topo.end());
    for(int i=0;i<n;i++){
        cout<<topo[i]<<" ";
    }
}