#include<bits/stdc++.h>
using namespace std;

int mod = int(1e9 + 7);

long long f(long long sum, vector<long long>& dp) {
    if (sum == 0) return 1;
    if (sum < 0) return 0;
    if (dp[sum] != -1) return dp[sum];

    long long ways = 0;
    for (int i = 1; i <= 6; i++) {
        ways += f(sum - i, dp);
    }
    return dp[sum] = ways%mod;
}

int main() {
    long long n;
    cin >> n;
    vector<long long>dp(n+1,-1);
    cout << f(n,dp)%mod << endl;
}
