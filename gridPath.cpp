#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mod = 1e9+7;

int f(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&dp){
    if(row == 0 && col == 0 && grid[0][0] != '*')return 1;

    if(row < 0 || col < 0 || grid[row][col] == '*')return 0;

    if(dp[row][col] != -1)return dp[row][col];

    int up = f(row-1,col,grid,dp);
    int left = f(row,col-1,grid,dp);
    return dp[row][col] = (up + left)%mod;
}
int main() {
    int n;
    cin>>n;

    vector<vector<char>>grid(n, vector<char>(n));

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<int>prev(n,0);
    if(grid[0][0] == '*'){
        cout<<0<<endl;
        return 0;
    }

    for(int row = 0; row < n; row++){
        vector<int>curr(n,0);
        for(int col = 0; col < n; col++){
            if(grid[row][col] == '*') continue;
            if(row == 0 && col == 0) {
                curr[col] = 1;
                continue;
            }
            else{
                int up =0, left = 0;
            if(row > 0) up = prev[col];
            if(col > 0)left = curr[col-1];
            curr[col] = (up + left) % mod;
            }
        }
        prev  = curr;
    }
    cout<<prev[n-1]%mod<<endl;
}