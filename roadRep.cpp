#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

// Disjoint-Set Union (DSU) data structure
class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false; // Already in the same set
        if (rank[px] < rank[py]) {
            parent[px] = py;
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    // Edge list: {cost, city1, city2}
    vector<pair<ll, pair<int, int>>> edges(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges[i] = {c, {a, b}};
    }

    // Special case: If n = 1, no edges needed
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    // Step 1: Sort edges by cost
    sort(edges.begin(), edges.end());

    // Step 2: Run Kruskal's algorithm
    DSU dsu(n);
    ll total_cost = 0;
    int edges_used = 0;

    for (const auto& edge : edges) {
        ll cost = edge.first;
        int u = edge.second.first;
        int v = edge.second.second;
        if (dsu.unite(u, v)) {
            total_cost += cost;
            edges_used++;
        }
    }

    // Step 3: Check if the graph is connected
    if (edges_used == n - 1) {
        cout << total_cost << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}