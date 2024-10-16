#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

const int MOD = 1e9 + 7;

// Use a map of maps to store the DP table (which dynamically grows)
unordered_map<int, unordered_map<int, int>> dp;

// Recursive function to calculate C[n][k] using your custom formula
int calculate(int n, int k) {
    // Base cases
    if (k == 0 || k == n) {
        return 1;
    }

    // Check if already computed
    if (dp[n].find(k) != dp[n].end()) {
        return dp[n][k];
    }

    // Recursively calculate C[n][k] using the custom formula
    dp[n][k] = (calculate(n, k - 1) + calculate(n - 1, k - 1)) % MOD;

    return dp[n][k];
}

int main() {
    // Input number of test cases
    long long t;
    cin >> t;

    // Read all values of n and k
    vector<int> n(t), k(t);
    for (int i = 0; i < t; i++) {
        cin >> n[i];
    }
    for (int i = 0; i < t; i++) {
        cin >> k[i];
    }

    // Process each test case
    for (int i = 0; i < t; i++) {
        cout << calculate(n[i], k[i]) << endl;
    }

    return 0;
}
