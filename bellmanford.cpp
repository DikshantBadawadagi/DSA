#include<iostream>
#include<bits/stdc++.h>
using namespace std;


 int bellman(int n,int m, int src,int dest, vector<vector<int>> &edges){
  vector<int>dist(n+1,INT_MAX);
  dist[src]=0;

  for(int i=1;i<=n;i++){
    for(int j=0;j<m;j++){
       int u = edges[j][0];
       int v = edges[j][1];
       int w = edges[j][2];

       if(dist[u] != INT_MAX && (dist[u] + w) < dist[v]){
        dist[v] = dist[u] + w;
       }
    }
  }

  bool flag=0;
    for(int i=1;i<=n;i++){
    for(int j=0;j<m;j++){
       int u = edges[j][0];
       int v = edges[j][1];
       int w = edges[j][2];

       if(dist[u] != INT_MAX && (dist[u] + w) < dist[v]){
        flag=1;
       }
    }
  }

if(flag == 0){
    return dist[dest];
}
else{
    cout<<"negative cycle present";
}
 }

 int main(){
    int n,m,src,dest;
    cin>>n>>m>>src>>dest;
    vector<vector<int>>edges[n+1];
    for(int i=1;i<=m;i++){
     int u,v,w;
     cin>>u>>v>>w;
     edges[u].push_back({v, w});
}


    int result = bellman(n, m, src, dest, edges);

    if (result != -1) {
        cout << "Shortest distance from source to destination: " << result << endl;
    } else {
        cout << "Negative cycle present" << endl;
    }

    return 0;
 }