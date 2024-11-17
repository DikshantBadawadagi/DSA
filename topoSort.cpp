#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int v = 6;
    vector<int>adj[v];
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(1);

    

 vector<int>indegree(v,0);

    for(int i=0;i<v;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
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
            if(indegree[it] == 0)q.push(it);
        }
    }
for(auto it : topo){
    cout<<it<<" ";
}

}