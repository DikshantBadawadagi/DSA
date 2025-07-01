#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

ll solve(ll a, ll b) {
    if (b == 0) return 1; // base case
    ll x = solve(a, b / 2);
    x = (x * x) % mod;
    if (b % 2 == 1)
        x = (x * a) % mod;
    return x;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) {
            cout << 1 << endl; // 0^0 is typically treated as 1 in contests
            continue;
        }
        if (a == 0) {
            cout << 0 << endl; // 0^b = 0 for b > 0
            continue;
        }
        ll ans = solve(a, b);
        cout << ans << endl;
    }
}
