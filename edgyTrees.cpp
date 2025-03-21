#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

// Power function with modular arithmetic
int pow(int a, int b, int m) {
    int ans = 1;
    while (b) {
        if (b & 1)
            ans = (ans * a) % m;
        b /= 2;
        a = (a * a) % m;
    }
    return ans;
}

int n, k, sz, ans = 0; // Variables for nodes, power value, size of component, and answer
bool vis[N];
vector<int> g[N]; // Graph adjacency list

// DFS function to calculate connected component size
void dfs(int u) {
    if (vis[u])
        return;
    sz++; // Increment component size
    vis[u] = 1; // Mark node as visited
    for (auto &it : g[u])
        dfs(it); // Continue DFS
}

int32_t main() {
    IOS;
    cin >> n >> k;

    // Start by calculating total combinations possible
    ans = pow(n, k, MOD);

    // Graph construction
    for (int i = 1; i <= n - 1; i++) {
        int u, v, x;
        cin >> u >> v >> x;
        if (x == 0) // Only add edges with x = 0
            g[u].push_back(v), g[v].push_back(u);
    }

    // Traverse all nodes for connected components
    for (int i = 1; i <= n; i++) {
        if (vis[i])
            continue;
        sz = 0; // Reset component size for each new component
        dfs(i);
        ans -= pow(sz, k, MOD); // Subtract invalid paths
        ans = (ans + MOD) % MOD; // Ensure no negative values
    }

    cout << ans << endl;
    return 0;
}
