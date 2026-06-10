#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> valid_targets;
    vector<int> cnt1;
    vector<long long> cnt2;

    // Process the first element
    long long x = a[0];
    set<long long> s;
    int c = 0;
    while (s.find(x) == s.end()) {
        valid_targets.push_back(x);
        cnt1.push_back(1);
        cnt2.push_back(c);
        s.insert(x); 
        if (x & 1) x += 1;
        else x >>= 1;
        c++;
    }

    for (int i = 1; i < n; i++) {
        x = a[i];
        s.clear();
        c = 0;
        while (s.find(x) == s.end()) {
  
            for (size_t j = 0; j < valid_targets.size(); j++) {
                if (valid_targets[j] == x) {
                    cnt1[j]++;
                    cnt2[j] += c;
                    break;
                }
            }
            s.insert(x);
            if (x & 1) x += 1;
            else x >>= 1;
            c++;
        }
    }

    long long ans = 1e18;
    for (size_t j = 0; j < valid_targets.size(); j++) {
        if (cnt1[j] == n) {
            ans = min(ans, cnt2[j]);
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