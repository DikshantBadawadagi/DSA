#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//this is kahn's algorithm using BFS for topo sort
int main() {
    int n;
    cin>>n;
    vector<vector<int>>adj = {{},{},{3},{1},{0,1},{0,2}};

    vector<int>indeg(n,0);

    for(int i=0;i<n;i++){
        for(auto j : adj[i]){
            indeg[j]++;
        }
    }

    queue<int>q;
    for(int i=0;i<n;i++){
        if(indeg[i] == 0)q.push(i);
    }

    vector<int>topo;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node]){
            indeg[it]--;
            if(indeg[it] == 0)q.push(it);
        }
    }

    for(auto i : topo)cout<<i<<" ";

    
}