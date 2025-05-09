#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;
    
    // Adjacency matrix: adj[v][u] = number of edges from v+1 to u+1
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a-1][b-1]++; // Increment edge count
    }

    // DP: dp[mask][v] = number of paths from 1 to v using vertices in mask
    vector<vector<long long>> dp(1 << n, vector<long long>(n, 0));
    
    // Base case: Start at vertex 1
    dp[1][0] = 1; // Mask 1 (vertex 1), ending at vertex 0 (1)

    // For each mask (subset of vertices visited)
    for (int mask = 1; mask < (1 << n); mask++) {
        // For each vertex v as the current end
        for (int v = 0; v < n; v++) {
            if (dp[mask][v] == 0) continue; // No paths to v with this mask
            if (!(mask & (1 << v))) continue; // v must be in mask
            // Try to go to each unvisited vertex u
            for (int u = 0; u < n; u++) {
                if (mask & (1 << u)) continue; // u already visited
                if (adj[v][u] == 0) continue; // No edges from v to u
                int new_mask = mask | (1 << u);
                // Add dp[mask][v] * (number of edges from v to u)
                dp[new_mask][u] = (dp[new_mask][u] + dp[mask][v] * adj[v][u] % MOD) % MOD;
            }
        }
    }

    // Answer: Number of paths visiting all vertices, ending at n
    long long ans = dp[(1 << n) - 1][n-1];
    cout << ans << endl;

    return 0;
}