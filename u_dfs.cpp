#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfs(int node,int parent, vector<vector<int>>&adj, vector<int>&vis){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(dfs(it,node,adj,vis)){
                return true;
            }
        }
        else{
            if(it != parent){
                return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>>adj = {
        {1, 2},
        {0, 3, 4},
        {0, 5},
        {1},
        {1, 5},
        {2, 4}
    };
    vector<int>vis(adj.size(), 0);
    for(int i=0;i<adj.size();i++){
        if(!vis[i]){
            if(dfs(i,-1,adj,vis)){
                cout<<"Cycle detected in the graph"<<endl;
                return 0;
            }
        }
    }
    cout<<"No cycle detected in the graph"<<endl;

}