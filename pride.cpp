#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    int n;
    cin >> n;
    vector<ll> a(n);
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) cnt1++;
    }

    if (cnt1 > 0) {
        cout << n - cnt1 << endl;
        return 0;
    }

    // Find min segment with GCD 1
    int min_len = n + 1; // Larger than possible
    for (int L = 0; L < n; L++) {
        ll g = a[L];
        for (int R = L; R < n; R++) {
            if (R > L) g = gcd(g, a[R]);
            if (g == 1) {
                min_len = min(min_len, R - L + 1);
                break; // Found GCD 1, no need to extend further
            }
        }
    }

    if (min_len == n + 1) {
        cout << -1 << endl; // No segment with GCD 1
    } else {
        ll ans = (ll)(min_len - 1) + (n - 1);
        cout << ans << endl;
    }
    return 0;
}