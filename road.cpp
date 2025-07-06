#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>&adj, vector<int>&vis) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, adj, vis);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>adj(n + 1);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);   
    }
    vector<int>vis(n + 1, 0);
    int cnt = 0;
    vector<int>compo;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            cnt++;
            compo.push_back(i);
            dfs(i, adj, vis);
        }
    }
    cout<< cnt -1<< endl;
    for(int i=0;i<compo.size()-1;i++){
        cout<<compo[i]<<" "<<compo[i+1]<<endl;
    }
    return 0;
}