#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        
        ll max_s = 0;
        ll prev = a[0];
        for (int i = 1; i < n; i++) {
            if (a[i] < prev) {
                ll s = prev - a[i];
                max_s = max(max_s, s);
            } else {
                prev = a[i];
            }
        }
        
        if (max_s == 0) {
            cout << "0\n";
        } else {
            int T = 0;
            while ((1LL << T) - 1 < max_s) T++;
            cout << T << "\n";
        }
    }
    return 0;
}