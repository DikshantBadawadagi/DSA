#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({a, b, -c}); // Negate for max path
    }

    vector<long long> dist(n + 1, 1e18);
    dist[1] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto &[u, v, w] : edges) {
            if (dist[u] != 1e18 && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Cycle detection
    vector<int> affected(n + 1, 0);
    for (int i = 0; i < n; i++) { // n times to fully propagate
        for (auto &[u, v, w] : edges) {
            if (dist[u] != 1e18 && dist[u] + w < dist[v]) {
                dist[v] = -1e18; // Mark node affected by positive cycle
                affected[v] = 1; // Optionally, track affected nodes
            }
        }
    }

    if (dist[n] == -1e18) {
        cout << -1 << endl; // Positive cycle can lead to infinite score
    } else {
        cout << -dist[n] << endl; // Negate back to get the max score
    }

    return 0;
}
