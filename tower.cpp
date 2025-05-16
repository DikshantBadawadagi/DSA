#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    
    const int MAXN = 1e6 + 1;
    vector<long long> dp(MAXN, 0);
    dp[0] = 1;
    dp[1] = 2;
    
    for (int h = 2; h < MAXN; h++) {
        dp[h] = (3LL * dp[h-1] % MOD + 2LL * dp[h-2] % MOD) % MOD;
    }
    
    while (t--) {
        int n;
        cin >> n;
        cout << dp[n] << endl;
    }
    
    return 0;
}