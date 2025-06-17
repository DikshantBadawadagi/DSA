#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n + 2), pos(n + 2); // Padding for bounds
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        pos[arr[i]] = i;
    }

    auto is_break = [&](int x) {
        if (x < 1 || x >= n) return false;
        return pos[x] > pos[x + 1];
    };

    int rounds = 1; // Always at least 1 round
    for (int i = 1; i < n; ++i) {
        if (pos[i] > pos[i + 1]) rounds++;
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        int u = arr[a], v = arr[b];

        set<int> affected = {u - 1, u, v - 1, v};
        for (int x : affected) if (is_break(x)) rounds--;

        swap(arr[a], arr[b]);
        pos[u] = b;
        pos[v] = a;

        for (int x : affected) if (is_break(x)) rounds++;

        cout << rounds << "\n";
    }
}
