#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);   
    }
    vector<int>vis(n+1, 0);
    vector<int>parent(n+1, -1);
            //node,level
    queue<pair<int,int>>q;
    q.push({1,1});
    vis[1] = 1;

    while(!q.empty()){
        auto topo = q.front();
        q.pop();
        int node = topo.first;
        int level = topo.second;
        if(node == n){
            cout<<level<<endl;
            vector<int>path;
            while(parent[node] != -1){
                path.push_back(node);
                node = parent[node];
            }
            reverse(path.begin(), path.end());
            cout<<1<<" ";
            for(auto it : path){
                cout<<it<<" ";
            }
            cout<<endl;
            return 0;
        }
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                parent[it] = node;
                q.push({it, level+1});
            }
        }
    
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;

}