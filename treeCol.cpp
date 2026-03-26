#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n + 1, -1);
    vector<int> children_count(n + 1, 0);
    vector<int> level_count(n + 1, 0);
    
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    level_count[0] = 1;

    int max_level = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                children_count[u]++;
                level_count[dist[v]]++;
                max_level = max(max_level, dist[v]);
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, children_count[i] + 1);
    }

    for (int i = 0; i <= max_level; i++) {
        ans = max(ans, level_count[i]);
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}