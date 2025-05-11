#include<bits/stdc++.h>
using namespace std;

int f(int ind,int x,vector<int>&coins ,vector<vector<int>>&dp){
    if(x == 0){
        return 0;
    }
    if(ind == coins.size() - 1){
        if(x % coins[ind] == 0){
            return x / coins[ind];
        }
        else{
            return int(1e9);
        }
    }
    if(dp[ind][x] != -1){
        return dp[ind][x];
    }

    int take=int(1e9);
    if(coins[ind]<=x){
        take= 1+ f(ind,x-coins[ind],coins,dp);
    }
    int notTake=0 + f(ind+1,x,coins,dp);

    return min(take,notTake);
}

int main() {
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);

    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<vector<int>>dp(n,vector<int>(x+1,0));

    for(int i=0;i<n;i++){
        dp[i][0]=0;
    }

    for(int i=0;i<x+1;i++){
        if(i % coins[n-1] == 0){
            dp[n-1][i] =  i / coins[n-1];
        }
        else{
            dp[n-1][i] =  int(1e9);
        }
    }

    for(int ind = n-2;ind >= 0;ind--){
        for(int target = 1;target <= x;target++){
            int take=int(1e9);
            if(coins[ind] <= target){
                take= 1+ dp[ind][target-coins[ind]];
            }
            int notTake=0 + dp[ind+1][target];

            dp[ind][target] = min(take,notTake);
        }
    }

    int ans = dp[0][ x];
if (ans >= 1e9) cout << -1 << endl;
else cout << ans << endl; 
}