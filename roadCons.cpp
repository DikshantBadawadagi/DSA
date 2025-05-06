#include <iostream>
#include <vector>
using namespace std;

// DSU class as provided, with modifications
class DSU {
    vector<int> parent, rank, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1); // Initially, each set has size 1
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

    bool unite(int x, int y, int& max_size) {
        int px = find(x), py = find(y);
        if (px == py) return false; // Already in the same set
        if (rank[px] < rank[py]) {
            parent[px] = py;
            size[py] += size[px];
            max_size = max(max_size, size[py]);
        } else if (rank[px] > rank[py]) {
            parent[py] = px;
            size[px] += size[py];
            max_size = max(max_size, size[px]);
        } else {
            parent[py] = px;
            rank[px]++;
            size[px] += size[py];
            max_size = max(max_size, size[px]);
        }
        return true;
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    DSU dsu(n);
    int components = n; // Initially, each city is its own component
    int max_size = 1;   // Initially, largest component size is 1

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        // Add the road (union operation)
        if (dsu.unite(a, b, max_size)) {
            components--; // Decrease number of components if sets were merged
        }
        // Output: number of components and size of largest component
        cout << components << " " << max_size << endl;
    }

    return 0;
}