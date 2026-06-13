#include <bits/stdc++.h>
using namespace std;

void solve() {
    long long y, x;
    cin >> y >> x;
    
    long long max_val = max(y, x);
    long long ans = (max_val - 1) * (max_val - 1);
    
    if (max_val % 2 == 0) {
        if (y > x) {
            ans += (2 * max_val - x);
        } else {
            ans += y;
        }
    } else {
        if (x > y) {
            ans += (2 * max_val - y);
        } else {
            ans += x;
        }
    }
    
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}