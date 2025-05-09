#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAX_N = 505;
const ll INF = 1e18;

// Adjacency list representation: {to, capacity, edge_index}
vector<vector<tuple<int, ll, int>>> adj(MAX_N);
// Flow through each edge
vector<ll> flow;
// Visited array for BFS
vector<int> parent(MAX_N, -1);
vector<int> edge_idx(MAX_N, -1);

int n;

// BFS to find an augmenting path
bool bfs(int s, int t) {
    fill(parent.begin(), parent.end(), -1);
    fill(edge_idx.begin(), edge_idx.end(), -1);
    queue<int> q;
    q.push(s);
    parent[s] = s;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < adj[u].size(); i++) {
            auto& edge = adj[u][i];
            int v = get<0>(edge);
            ll cap = get<1>(edge);
            int idx = get<2>(edge);
            if (parent[v] == -1 && cap - flow[idx] > 0) {
                parent[v] = u;
                edge_idx[v] = idx;
                q.push(v);
                if (v == t) return true;
            }
        }
    }
    return false;
}

// Ford-Fulkerson with Edmonds-Karp (BFS)
ll max_flow(int s, int t) {
    ll total_flow = 0;
    while (bfs(s, t)) {
        // Find bottleneck capacity along the path
        ll bottleneck = INF;
        int v = t;
        while (v != s) {
            int u = parent[v];
            int idx = edge_idx[v];
            // Find the edge in adj[u] with this index
            for (int i = 0; i < adj[u].size(); i++) {
                if (get<2>(adj[u][i]) == idx) {
                    bottleneck = min(bottleneck, get<1>(adj[u][i]) - flow[idx]);
                    break;
                }
            }
            v = u;
        }

        // Update flows along the path
        v = t;
        while (v != s) {
            int u = parent[v];
            int idx = edge_idx[v];
            flow[idx] += bottleneck;
            // Find reverse edge
            for (int i = 0; i < adj[v].size(); i++) {
                int rv = get<0>(adj[v][i]);
                int ridx = get<2>(adj[v][i]);
                if (rv == u && ridx + (ridx % 2 == 0 ? 1 : -1) == idx) {
                    flow[ridx] -= bottleneck;
                    break;
                }
            }
            v = u;
        }
        total_flow += bottleneck;
    }
    return total_flow;
}

int main() {
    int m;
    cin >> n >> m;

    // Initialize adjacency list and flow array
    adj.clear();
    adj.resize(n + 1);
    flow.clear();

    // Read edges and build the graph
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        // Add forward edge
        adj[a].push_back({b, c, (int)flow.size()});
        flow.push_back(0);
        // Add reverse edge (for residual graph)
        adj[b].push_back({a, 0, (int)flow.size()});
        flow.push_back(0);
    }

    // Compute maximum flow from 1 to n
    ll ans = max_flow(1, n);
    cout << ans << endl;

    return 0;
}