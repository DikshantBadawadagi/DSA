#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<int>& vis, vector<int>& parent, vector<vector<int>>& adj, int& cycle_start, int& cycle_end) {
    vis[node] = 1;  

    for (auto it : adj[node]) {
        if (!vis[it]) {
            parent[it] = node;
            if (dfs(it, vis, parent, adj, cycle_start, cycle_end))
                return true;
        } 
        else if (vis[it] == 1) {
            cycle_start = it;
            cycle_end = node;
            return true;
        }
    }

    vis[node] = 2; 
    return false;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); 
    }

    vector<int> vis(n + 1, 0), parent(n + 1, -1);
    int cycle_start = -1, cycle_end = -1;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (dfs(i, vis, parent, adj, cycle_start, cycle_end)) {
                break;
            }
        }
    }

    if (cycle_start == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> cycle;
        cycle.push_back(cycle_start);
        for (int i = cycle_end; i != cycle_start; i = parent[i]) {
            cycle.push_back(i);
        }
        cycle.push_back(cycle_start);
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << endl;
        for (auto it : cycle) {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
