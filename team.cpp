#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool bfs(int i, vector<vector<int>>&adj, vector<int>&color){
    queue<int>q;
    q.push(i);
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it: adj[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }
            else{
                if(color[it] == color[node]){
                    return false; // If the adjacent node has the same color, it's not bipartite
                }
            }
        }
    }
    return true;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);   
    } 
    vector<int>color(n+1, -1);
    
    
    for(int i=1;i<=n;i++){
        if(color[i] == -1){
            color[i] = 0;
            if(!bfs(i,adj,color)){
                cout<<"IMPOSSIBLE"<<endl;
                return 0;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<color[i] + 1<<" ";
    }

    
}