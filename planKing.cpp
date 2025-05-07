#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs1(int node,vector<vector<int>>&adj,vector<int>&vis,stack<int>&st){
    vis[node] =1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs1(it,adj,vis,st);
        }
    }
    st.push(node);
}

void dfs2(int node,vector<vector<int>>&adjT,vector<int>&vis,vector<int>&scc,int component){
    vis[node] =1;
    scc[node] = component;
    for(auto it : adjT[node]){
        if(!vis[it]){
            dfs2(it,adjT,vis,scc,component);
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;

    vector<vector<int>>adj(n+1);
    vector<vector<int>>adjT(n+1);

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adjT[b].push_back(a);
    }

    vector<int>vis(n+1,0);
    stack<int>st;

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs1(i,adj,vis,st);
        }
    }


    fill(vis.begin(),vis.end(),0);
    vector<int>scc(n+1,0);

    int component = 0;

    while(!st.empty()){
        auto node = st.top();
        st.pop();
        if(!vis[node]){
            component++;
            dfs2(node,adjT,vis,scc,component);
        }
    }

    cout<<component<<endl;
    for(int i=1;i<=n;i++){
        cout<<scc[i]<<" ";
    }
    cout<<endl;
}