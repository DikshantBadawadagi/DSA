#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool f(int ind,int t,vector<int>&nums,int n, vector<vector<bool>>&dp) {
    if(t == 0)return true;
    if(ind == n-1)return nums[n-1] == t;
    
    if(dp[ind][t] != -1) return bool(dp[ind][t]);
    int notPick = f(ind+1, t, nums, n,dp);
    int pick = false;
    if(nums[ind] <= t) {
        pick = f(ind+1, t-nums[ind], nums, n,dp);
    }
    return dp[ind][t] = notPick || pick;
}

int main() {
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0; i<n; i++) {
        cin>>nums[i];
    }
    int mini = INT_MAX;
    int sum = 0;
    for(int i=0; i<n; i++) {
        mini = min(mini, nums[i]); 
        sum += nums[i];
    }
    vector<int>ans;
    int cnt = 0;

    vector<vector<bool>>dp(n+1, vector<bool>(sum+1, false));

    for(int i=0;i<n;i++){
        dp[i][0] = true; 
        if(nums[i] <= sum) {
            dp[i][nums[i]] = true; 
        }
    }

    if(nums[n-1] <= sum)
        dp[n-1][nums[n-1]] = true;

    for(int ind = n-2;ind>=0;ind--) {
        for(int t = 1;t<=sum;t++) {
            bool notPick = dp[ind+1][t];
            bool pick = false;
            if(nums[ind] <= t) {
                pick = dp[ind+1][t-nums[ind]];
            }
            dp[ind][t] = notPick || pick;
        }
    }


    for(int i = mini;i<=sum;i++){
        if(dp[0][i]){
            cnt++;
            ans.push_back(i);
        }
    }

    cout<<cnt<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

}