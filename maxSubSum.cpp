#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> x(n);
    for (int i = 0; i < n; ++i) cin >> x[i];

    vector<long long> prefix(n + 1, 0);
    for (int i = 0; i < n; ++i)
        prefix[i + 1] = prefix[i] + x[i];

    multiset<long long> window;
    long long max_sum = LLONG_MIN;

    for (int r = a; r <= n; ++r) {
        // Insert prefix[r - a] into the window
        window.insert(prefix[r - a]);

        // Remove prefix[r - b - 1] if out of bounds
        if (r - b - 1 >= 0) {
            window.erase(window.find(prefix[r - b - 1]));
        }

        // Calculate max sum ending at r-1 (inclusive)
        max_sum = max(max_sum, prefix[r] - *window.begin());
    }

    cout << max_sum << endl;
    return 0;
}
