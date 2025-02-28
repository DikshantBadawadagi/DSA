#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        vector<int> dp(n+1, 0); // Extra space for boundary condition
        
        // Fill the dp array from end to start
        for (int i = n-1; i >= 0; i--) {
            // Skip case
            int skip = dp[i+1];
            
            // Take case
            int take = INT_MIN;
            if (i + nums[i] < n) {
                take = nums[i] + 1;
                if (i + nums[i] + 1 < n) {
                    take += dp[i + nums[i] + 1];
                }
            }
            
            // Store the max of taking or skipping
            dp[i] = max(take, skip);
        }
        
        // Answer is stored at dp[0] as we are calculating from start
        cout << (n - dp[0]) << endl;
    }
}
