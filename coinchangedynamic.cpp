#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mini(int a ,int b){
    return a<b?a:b;
}
int coindp(int n,vector<int>&coins){
    vector<int>dp(n+1,n+1);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        for(int coin : coins){
            if(coin<=i){
                dp[i] = mini(dp[i],1+dp[i-coin]);
            }
        }
    }
    return dp[n]>n+1?-1:dp[n];
}

int main() {
 vector<int> coins = {1, 2, 5}; // Example coin denominations
    int amount = 11; // Example amount
    int minCoins = coindp(amount, coins);
    cout<<minCoins;

return 0;
}