#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>>adj = {
        {1, 2},
        {3, 4},
        {5},
        {1},
        {1, 5},
        {2, 4}
        
    };
    vector<int>vis(adj.size(), 0);
    vector<int>pathVis(adj.size(), 0);
}