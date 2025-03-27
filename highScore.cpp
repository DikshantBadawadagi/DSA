#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2505;
const ll INF = 1e18; 

vector<tuple<int, int, ll>> edges; 
vector<ll> dist(MAXN);
vector<bool> reachable_from_1(MAXN);
vector<vector<int>> adj(MAXN); 

void dfs(int u, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v, visited);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        ll x;
        cin >> a >> b >> x;
        edges.push_back({a, b, x});
        adj[a].push_back(b); 
    }
    
    dfs(1, reachable_from_1);
    
    fill(dist.begin(), dist.begin() + n + 1, -INF);
    dist[1] = 0;
    
    for (int i = 1; i <= n - 1; i++) {
        for (auto [u, v, x] : edges) {
            if (dist[u] != -INF && dist[u] + x > dist[v]) {
                dist[v] = dist[u] + x;
            }
        }
    }
    
    vector<bool> can_increase(n + 1, false);
    for (auto [u, v, x] : edges) {
        if (dist[u] != -INF && dist[u] + x > dist[v]) {
            can_increase[v] = true;
        }
    }
    
    vector<bool> reaches_n(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (can_increase[i] && reachable_from_1[i]) {
            dfs(i, reaches_n);
            if (reaches_n[n]) {
                cout << "-1\n";
                return 0;
            }
        }
    }
    
    cout << dist[n] << "\n";
    
    return 0;
}