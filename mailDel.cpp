#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<long long, long long>>> g; // {neighbor, edge ID}
vector<long long> deg; // Degree of each vertex
vector<bool> vis; // For connectivity check
vector<bool> used; // Track used edges
vector<long long> route; // Store the route

// DFS to check connectivity
void dfs(long long v) {
    vis[v] = true;
    for (auto& [u, id] : g[v]) {
        if (!vis[u]) {
            dfs(u);
        }
    }
}

// Hierholzer's algorithm to find Eulerian circuit
void find_circuit(long long start) {
    stack<long long> st;
    st.push(start);
    while (!st.empty()) {
        long long v = st.top();
        bool found = false;
        // Look for an unused edge
        while (!g[v].empty()) {
            auto [u, id] = g[v].back();
            g[v].pop_back();
            if (!used[id]) {
                used[id] = true;
                st.push(u);
                found = true;
                break;
            }
        }
        if (!found) {
            route.push_back(v);
            st.pop();
        }
    }
}

int main() {
    long long n, m;
    cin >> n >> m;

    // Initialize data structures
    g.resize(n + 1);
    deg.resize(n + 1, 0);
    used.resize(m, false);
    vis.resize(n + 1, false);

    // Build the graph
    for (long long i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        g[a].push_back({b, i});
        g[b].push_back({a, i});
        deg[a]++;
        deg[b]++;
    }

    // Step 1: Check for even degrees
    for (long long v = 1; v <= n; v++) {
        if (deg[v] % 2 != 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    // Step 2: Check connectivity
    dfs(1); // Start DFS from vertex 1
    long long edge_count = 0;
    for (long long v = 1; v <= n; v++) {
        if (vis[v]) {
            edge_count += deg[v];
        }
        // If vertex has edges but isn't reachable, no solution
        if (deg[v] > 0 && !vis[v]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }
    edge_count /= 2; // Each edge counted twice
    if (edge_count != m) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // Step 3: Find Eulerian circuit starting at vertex 1
    find_circuit(1);

    // Step 4: Verify all edges were used
    for (long long i = 0; i < m; i++) {
        if (!used[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    // Step 5: Output the route
    for (long long v : route) {
        cout << v << " ";
    }
    cout << endl;
}