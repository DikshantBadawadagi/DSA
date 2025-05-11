#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main() {
    int n;
    cin>>n;

    vector<int>dp(n+1,INT_MAX);

    dp[0] = 0;

    for(int i=1;i<=n;i++){
        int ans = INT_MAX;

        for (char c : to_string(i)) {
            int digit = c - '0';
            if (digit != 0) {
                ans = min(ans, 1 + dp[i - digit]);
            }
        }
        dp[i] = ans;
    }

    cout<<dp[n]<<endl;
}