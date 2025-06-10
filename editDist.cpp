#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int f(int ind1,int ind2, string s1, string s2, int n, int m, vector<vector<int>>& dp) {

    if(ind1 > n-1 && ind2 > m-1) {
        // If both indices are out of bounds, no more characters to process
        return 0;
    }
    if(ind1 > n-1) {
        // If s1 is exhausted, we need to insert all remaining characters of s2
        return m - ind2;
    }
    if(ind2 > m-1) {
        // If s2 is exhausted, we need to remove all remaining characters of s1
        return n - ind1;
    }

    // Check if the result is already computed
    if(dp[ind1][ind2] != -1) {
        return dp[ind1][ind2];
    }
    

    if(s1[ind1] != s2[ind2]) {
        // If characters don't match, we have three options:
        // 1. Insert a character into s1
        // 2. Remove a character from s1
        // 3. Replace a character in s1 with one from s2
        int insert = f(ind1, ind2 + 1, s1, s2, n, m,dp) + 1;
        int remove = f(ind1 + 1, ind2, s1, s2, n, m,dp) + 1;
        int replace = f(ind1 + 1, ind2 + 1, s1, s2, n, m,dp) + 1;

        return dp[ind1][ind2] = min({insert, remove, replace});
    } else {
        // If characters match, move to the next characters in both strings
        return dp[ind1][ind2] = f(ind1 + 1, ind2 + 1, s1, s2, n, m,dp);
    }
}

int main() {
    string s1,s2;
    cin >> s1 >> s2;
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for(int ind1 = 0;ind1 < n;ind1++){
        dp[ind1][m] = n - ind1; // If s2 is exhausted, we need to remove all remaining characters of s1
    }
    for(int ind2 = 0;ind2 < m;ind2++){
        dp[n][ind2] = m - ind2; // If s1 is exhausted, we need to insert all remaining characters of s2
    }
    for(int ind1 = n - 1; ind1 >= 0; ind1--) {
        for(int ind2 = m - 1; ind2 >= 0; ind2--) {
            if(s1[ind1] != s2[ind2]) {
                int insert = dp[ind1][ind2 + 1] + 1;
                int remove = dp[ind1 + 1][ind2] + 1;
                int replace = dp[ind1 + 1][ind2 + 1] + 1;

                dp[ind1][ind2] = min({insert, remove, replace});
            } else {
                dp[ind1][ind2] = dp[ind1 + 1][ind2 + 1];
            }
        }
    }

    cout<< dp[0][0]<<endl;
}