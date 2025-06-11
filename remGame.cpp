#include <bits/stdc++.h>
using namespace std;

vector<long long> a;
vector<vector<long long>> dp;

long long f(int l, int r) {
    if (l > r) return 0;
    if (l == r) return a[l];
    
    if (dp[l][r] != LLONG_MIN) return dp[l][r];

    long long take_left = a[l] + min(f(l + 2, r), (l + 1 <= r ? f(l + 1, r - 1) : 0));
    long long take_right = a[r] + min((l <= r - 1 ? f(l + 1, r - 1) : 0), f(l, r - 2));
    
    return dp[l][r] = max(take_left, take_right);
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp.assign(n, vector<long long>(n, LLONG_MIN));
    cout << f(0, n-1) << endl;
    return 0;
}