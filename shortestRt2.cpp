#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 505;
const ll INF = 1e18; // Large enough for max path

ll dist[MAXN][MAXN];

void floydWarshall(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    // Initialize distance matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    
    // Build graph
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c); // Handle multiple roads
        dist[b][a] = min(dist[b][a], c); // Undirected
    }
    
    // Run Floyd-Warshall
    floydWarshall(n);
    
    // Process queries
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        if (dist[a][b] == INF) cout << "-1\n";
        else cout << dist[a][b] << "\n";
    }
    
    return 0;
}