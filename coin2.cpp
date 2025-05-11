#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, t;
    cin >> n >> t;

    vector<int> val(n);
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    vector<int> dp(t + 1, 0);
    dp[0] = 1; // Only one way to make sum 0

    for (int i = 0; i < n; i++) {
        for (int x = val[i]; x <= t; x++) {
            dp[x] = (dp[x] + dp[x - val[i]]) % MOD;
        }
    }

    cout << dp[t] << endl;
}
