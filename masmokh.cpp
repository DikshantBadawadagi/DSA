#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007;

long long f(int n,int curr,int k,int prev,vector<vector<long long>>& dp){
    if(curr==k) return 1;

    if(dp[curr][prev]!=0) return dp[curr][prev];

    long long ans = 0;
    for(int  i=1;prev*i<=n;i++){
        ans+=f(n,curr+1,k,prev*i,dp);
        ans%=mod;
    }

    return dp[curr][prev] = ans;
}

int main() {
    int n,k;
    cin>>n>>k;
    long long sum=0;

    vector<vector<long long>> dp(k+1, vector<long long>(n+1, 0));

    for(int i=1;i<=n;i++)
        sum = (sum + f(n, 1, k, i,dp)) % 1000000007;

    cout<<sum<<endl;
    return 0;
}