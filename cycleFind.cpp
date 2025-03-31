#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2505;
const ll INF = 1e18;

vector<tuple<int, int, ll>> edges; // (u, v, weight)
vector<ll> dist(MAXN);
vector<int> pred(MAXN);

int main() {
    int n, m;
    cin >> n >> m;
    
    // Input edges
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    
    // Initialize
    fill(dist.begin(), dist.begin() + n + 1, INF);
    dist[0] = 0; // Virtual source
    fill(pred.begin(), pred.begin() + n + 1, -1);
    
    // Add edges from virtual source (0) to all nodes
    for (int i = 1; i <= n; i++) {
        edges.push_back({0, i, 0});
    }
    
    // Bellman-Ford: n relaxations
    for (int i = 0; i < n; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pred[v] = u;
            }
        }
    }
    
    // Check for negative cycle
    int start = -1;
    for (auto [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            start = v; // Node in cycle
            dist[v] = dist[u] + w;
            pred[v] = u;
            break;
        }
    }
    
    if (start == -1) {
        cout << "NO\n";
    } else {
        // Trace cycle
        vector<int> cycle;
        vector<bool> visited(n + 1, false);
        int curr = start;
        
        // Go back until we hit a repeat
        while (!visited[curr]) {
            visited[curr] = true;
            curr = pred[curr];
        }
        
        // Found the cycle start
        int cycle_start = curr;
        cycle.push_back(cycle_start);
        curr = pred[cycle_start];
        
        // Build cycle
        while (curr != cycle_start) {
            cycle.push_back(curr);
            curr = pred[curr];
        }
        cycle.push_back(cycle_start);
        
        // Remove virtual node 0 if present
        vector<int> cleaned_cycle;
        for (int x : cycle) {
            if (x != 0) cleaned_cycle.push_back(x);
        }
        reverse(cleaned_cycle.begin(), cleaned_cycle.end());
        
        cout << "YES\n";
        for (int x : cleaned_cycle) {
            cout << x << " ";
        }
        cout << "\n";
    }
    
    return 0;
}