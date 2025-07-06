#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    //now bfs for directed graph is same as kahns algo
    vector<vector<int>>adj = {
        {1, 2},
        {3, 4},
        {5},
        {1},
        {1, 5},
        {2, 4}
        
    };
    vector<int>indegree(adj.size(), 0);
    

    for(int i=0;i<adj.size();i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<indegree.size();i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int>topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }
    for(auto it : topo){
        cout<<it<<" ";
    }
    cout<<endl;
    
    if(topo.size() != adj.size()){
        cout<<"Cycle detected in the graph"<<endl;
    } else {
        cout<<"No cycle detected in the graph"<<endl;
    }
}