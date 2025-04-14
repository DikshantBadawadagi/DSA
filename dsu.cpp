#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class DSU {
    vector<int>parent,size;
    public:
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=1;i<=n;i++) {
            parent[i] = i;
        }
    }

    int findUparent(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findUparent(parent[node]);
    }

    void unionBySize(int u,int v){
        int up = findUparent(u);
        int vp = findUparent(v);
        if(up == vp) return;
        if(size[up] < size[vp]) {
            parent[up] = vp;
            size[vp] += size[up];
        } else {
            parent[vp] = up;
            size[up] += size[vp];
        }
    }
};
