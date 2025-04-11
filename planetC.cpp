#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> next(n + 1); // 1-based indexing
    for (int i = 1; i <= n; i++) {
        cin >> next[i];
    }

    vector<int> jumps(n + 1, 0); // Store number of jumps for each starting planet

    for (int start = 1; start <= n; start++) {
        vector<bool> visited(n + 1, false); // Track visited planets
        int current = start;
        int jumpCount = 0;

        while (!visited[current]) {
            visited[current] = true;
            current = next[current];
            jumpCount++;
            if (visited[current]) {
                jumps[start] = jumpCount; // First revisit
                break;
            }
        }
    }

    // Output results
    for (int i = 1; i <= n; i++) {
        cout << jumps[i] << " ";
    }
    cout << endl;

    return 0;
}