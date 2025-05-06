#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// DFS to compute finishing times
void dfs1(int v, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& finish) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs1(u, graph, visited, finish);
        }
    }
    finish.push(v);
}

// DFS to label SCCs
void dfs2(int v, vector<vector<int>>& graphT, vector<bool>& visited, vector<int>& scc, int component) {
    visited[v] = true;
    scc[v] = component;
    for (int u : graphT[v]) {
        if (!visited[u]) {
            dfs2(u, graphT, visited, scc, component);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Build the graph and its transpose
    vector<vector<int>> graph(n + 1), graphT(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graphT[b].push_back(a);
    }

    // Step 1: First DFS to get finishing times
    vector<bool> visited(n + 1, false);
    stack<int> finish;
    for (int v = 1; v <= n; v++) {
        if (!visited[v]) {
            dfs1(v, graph, visited, finish);
        }
    }

    // Step 2: Second DFS on transposed graph to find SCCs
    fill(visited.begin(), visited.end(), false);
    vector<int> scc(n + 1, 0);
    int component = 0;
    while (!finish.empty()) {
        int v = finish.top();
        finish.pop();
        if (!visited[v]) {
            component++;
            dfs2(v, graphT, visited, scc, component);
        }
    }

    // Step 3: Check if the graph is strongly connected
    if (component == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
        // Step 4: Find a pair (a, b) where there's no path from a to b
        // SCCs are labeled in reverse topological order
        // Pick a vertex from the highest SCC and a vertex from the lowest SCC
        int min_scc = 1, max_scc = component;
        int city_a = -1, city_b = -1;
        for (int v = 1; v <= n; v++) {
            if (scc[v] == max_scc) {
                city_a = v; // From the latest SCC
                break;
            }
        }
        for (int v = 1; v <= n; v++) {
            if (scc[v] == min_scc) {
                city_b = v; // From the earliest SCC
                break;
            }
        }
        cout << city_a << " " << city_b << endl;
    }

    return 0;
}