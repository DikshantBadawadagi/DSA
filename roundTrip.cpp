#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<vector<int>> adj(MAXN);
vector<int> vis(MAXN, 0); // 0 = unvisited, 1 = visiting, 2 = visited
vector<int> parent(MAXN, -1);
vector<int> cycle;
bool found = false;

void dfs(int v, int p) {
    vis[v] = 1; 
    parent[v] = p;
    
    for (int u : adj[v]) {
        if (u == p) continue; 
        if (vis[u] == 0) { 
            dfs(u, v);
            if (found) return;
        } else if (vis[u] == 1) { 
            cycle.push_back(u);
            int cur = v;
            while (cur != u) {
                cycle.push_back(cur);
                cur = parent[cur];
            }
            cycle.push_back(u);
            found = true;
            return;
        }
    }
    vis[v] = 2; 
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    for (int i = 1; i <= n && !found; i++) {
        if (vis[i] == 0) {
            dfs(i, -1);
        }
    }
    
    if (!found || cycle.size() < 4) {
        cout << "IMPOSSIBLE\n";
    } else {
        cout << cycle.size() << "\n";
        for (int v : cycle) {
            cout << v << " ";
        }
        cout << "\n";
    }
    
    return 0;
}