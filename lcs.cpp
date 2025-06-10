#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
    }

    // Step 1: Build DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(a[i] == b[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    cout << dp[0][0] << endl;

    // Step 3: Recover and print the LCS
    int i = 0, j = 0;
    vector<int> lcs;
    while(i < n && j < m) {
        if(a[i] == b[j]) {
            lcs.push_back(a[i]);
            i++;
            j++;
        } else if(dp[i + 1][j] >= dp[i][j + 1]) {
            i++;
        } else {
            j++;
        }
    }

    for(int x : lcs) {
        cout << x << " ";
    }
    cout << endl;
}
