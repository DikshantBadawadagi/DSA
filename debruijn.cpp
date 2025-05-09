#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> g; // {vertex, bit}
vector<bool> used; // Track used edges
vector<int> route; // Store the circuit vertices

// Hierholzer's algorithm to find Eulerian circuit
void find_circuit(int start, int m) {
    stack<int> st;
    st.push(start);
    while (!st.empty()) {
        int v = st.top();
        bool found = false;
        while (!g[v].empty()) {
            auto [u, bit] = g[v].back();
            int edge_id = v * 2 + bit; // Unique edge ID
            g[v].pop_back();
            if (!used[edge_id]) {
                used[edge_id] = true;
                st.push(u);
                found = true;
                route.push_back(bit); // Record the bit for this edge
                break;
            }
        }
        if (!found) {
            st.pop();
        }
    }
}

int main() {
    int n;
    cin >> n;

    if(n == 1){cout<<"01"<<endl;
    return 0;}
    
    

    // Step 1: Build De Bruijn graph
    int num_vertices = 1 << (n - 1); // 2^(n-1)
    int num_edges = 1 << n; // 2^n
    g.resize(num_vertices);
    used.resize(num_edges, false);

    // Vertices are labeled 0 to 2^(n-1) - 1 (as (n-1)-bit strings)
    // Edge from u to v: if u = a1 a2 ... a(n-1), v = a2 ... a(n-1) b
    for (int u = 0; u < num_vertices; u++) {
        int v0 = (u << 1) & (num_vertices - 1); // Append 0
        int v1 = v0 | 1; // Append 1
        g[u].push_back({v0, 0}); // Edge u -> v0, bit 0
        g[u].push_back({v1, 1}); // Edge u -> v1, bit 1
    }

    // Step 2: Find Eulerian circuit starting at vertex 0 (0^(n-1))
    route.clear();
    find_circuit(0, num_edges);

    // Step 3: Construct the bit string
    // Start with the first vertex (0^(n-1))
    string s = "";
    for (int i = 0; i < n - 1; i++) {
        s += "0";
    }
    // Append bits from the circuit
    for (int bit : route) {
        s += (char)('0' + bit);
    }

    // Step 4: Output the string
    cout << s << endl;
}