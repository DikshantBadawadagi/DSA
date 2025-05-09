#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> adj; // Original directed graph
vector<vector<int>> undirected; // For connectivity check
vector<bool> vis; // For DFS
vector<int> in_deg, out_deg; // In-degree and out-degree

// DFS to check connectivity
void dfs(int v) {
    vis[v] = true;
    for (int u : undirected[v]) {
        if (!vis[u]) {
            dfs(u);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    undirected.resize(n + 1);
    in_deg.resize(n + 1, 0);
    out_deg.resize(n + 1, 0);
    vis.resize(n + 1, false);

    // Build the graph and compute degrees
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        undirected[a].push_back(b);
        undirected[b].push_back(a); // For undirected connectivity check
        out_deg[a]++;
        in_deg[b]++;
    }

    // Step 1: Check degree conditions
    if (out_deg[1] - in_deg[1] != 1 || in_deg[n] - out_deg[n] != 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int v = 2; v <= n - 1; v++) {
        if (in_deg[v] != out_deg[v]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    // Step 2: Check weak connectivity
    dfs(1);
    int edge_count = 0;
    for (int v = 1; v <= n; v++) {
        if (vis[v]) {
            edge_count += undirected[v].size();
        }
        // If vertex has edges but isn't reachable, impossible
        if ((in_deg[v] > 0 || out_deg[v] > 0) && !vis[v]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    edge_count /= 2; // Each edge counted twice in undirected graph
    if (edge_count != m) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // Step 3: Run Hierholzer's algorithm to find Eulerian path
    stack<int> st;
    st.push(1);
    vector<int> path;

    while (!st.empty()) {
        int node = st.top();
        if (!adj[node].empty()) {
            st.push(adj[node].back());
            adj[node].pop_back();
        } else {
            path.push_back(node);
            st.pop();
        }
    }

    // Step 4: Validate the path
    if (path.size() != m + 1 || path[0] != n) { // Check length and end vertex
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // Step 5: Output the path (reverse since Hierholzer builds in reverse)
    reverse(path.begin(), path.end());
    for (int v : path) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}