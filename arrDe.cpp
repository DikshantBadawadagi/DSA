#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    // dp[i][j] = ways to fill upto index i where arr[i] = j
    vector<vector<int>> dp(n, vector<int>(m + 2, 0)); // add padding to avoid bound checks

    // Initialization for index 0
    if (arr[0] == 0) {
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 1;
        }
    } else {
        dp[0][arr[0]] = 1;
    }

    // Fill the table
    for (int i = 1; i < n; i++) {
        if (arr[i] == 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = ((long long)dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
            }
        } else {
            int j = arr[i];
            dp[i][j] = ((long long)dp[i - 1][j - 1] + dp[i - 1][j] + dp[i - 1][j + 1]) % MOD;
        }
    }

    // Final answer
    int result = 0;
    for (int j = 1; j <= m; j++) {
        result = (result + dp[n - 1][j]) % MOD;
    }

    cout << result << endl;
}
