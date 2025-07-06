#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class dsu{
    vector<int>parent;
    vector<int>size;
    public:
    dsu(int n){
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }

    void unionSize(int u,int v){
        int pu = findUPar(u);
        int pv = findUPar(v);

        if(size[pv] > size[pu]){
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int findUPar(int u){
        if(parent[u] == u)return u;

        return parent[u] = findUPar(parent[u]);
    }
};

int main() {
    dsu* DSU = new dsu(5);
        DSU->unionSize(1, 2);
        DSU->unionSize(2, 3);
        DSU->unionSize(4, 5);
        cout<<DSU->findUPar(1)<<" "<<DSU->findUPar(2)<<" "<<DSU->findUPar(3)<<endl; // Should print the same parent for 1, 2, and 3
        cout<<DSU->findUPar(4)<<" "<<DSU->findUPar(5)<<endl; // Should print the same parent for 4 and 5
}