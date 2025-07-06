#include<iostream>
#include<bits/stdc++.h>
using namespace std;

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
    queue<pair<int,int>>q;
    q.push({0,-1});

    while(!q.empty()){
        auto topo = q.front();
        q.pop();
        int node = topo.first;
        int parent =topo.second;
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]){
                q.push({it,node});
            }
            else{
                if(it != parent){
                    cout<<"Cycle detected in the graph"<<endl;
                    return 0;
                }
            }
        }
    }
    cout<<"No cycle detected in the graph"<<endl;
    return 0;

}