#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Kosaraju's algorithm to find SCCs
void dfs1(int v, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& finish) {
    visited[v] = true;
    for (int u : graph[v]) {
        if (!visited[u]) {
            dfs1(u, graph, visited, finish);
        }
    }
    finish.push(v);
}

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

    // Implication graph: 2m vertices (x and ¬x for each topping)
    // Vertex 2*i-2 represents x_i (true), 2*i-1 represents ¬x_i (false)
    vector<vector<int>> graph(2 * m), graphT(2 * m);

    // Read wishes and build the implication graph
    for (int i = 0; i < n; i++) {
        char sign1, sign2;
        int x, y;
        cin >> sign1 >> x >> sign2 >> y;
        x--; y--; // Convert to 0-based indexing

        // First wish
        int l1 = (sign1 == '+' ? 2 * x : 2 * x + 1);     // Literal for wish 1
        int not_l1 = (sign1 == '+' ? 2 * x + 1 : 2 * x);  // Negation of literal 1

        // Second wish
        int l2 = (sign2 == '+' ? 2 * y : 2 * y + 1);     // Literal for wish 2
        int not_l2 = (sign2 == '+' ? 2 * y + 1 : 2 * y);  // Negation of literal 2

        // Clause: (l1 ∨ l2) → (¬l1 → l2) and (¬l2 → l1)
        graph[not_l1].push_back(l2);
        graph[not_l2].push_back(l1);
        graphT[l2].push_back(not_l1);
        graphT[l1].push_back(not_l2);
    }

    // Step 1: Find SCCs using Kosaraju's algorithm
    vector<bool> visited(2 * m, false);
    stack<int> finish;
    for (int v = 0; v < 2 * m; v++) {
        if (!visited[v]) {
            dfs1(v, graph, visited, finish);
        }
    }

    fill(visited.begin(), visited.end(), false);
    vector<int> scc(2 * m, 0);
    int component = 0;
    while (!finish.empty()) {
        int v = finish.top();
        finish.pop();
        if (!visited[v]) {
            component++;
            dfs2(v, graphT, visited, scc, component);
        }
    }

    // Step 2: Check satisfiability
    bool possible = true;
    for (int i = 0; i < m; i++) {
        if (scc[2 * i] == scc[2 * i + 1]) { // x_i and ¬x_i in same SCC
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // Step 3: Assign values
    vector<char> result(m, '-');
    for (int i = 0; i < m; i++) {
        // If SCC of x_i has higher label than SCC of ¬x_i, set x_i = true
        if (scc[2 * i] > scc[2 * i + 1]) {
            result[i] = '+';
        }
    }

    // Output the result
    for (int i = 0; i < m; i++) {
        cout << result[i];
        if (i < m - 1) cout << " ";
    }
    cout << endl;

    return 0;
}