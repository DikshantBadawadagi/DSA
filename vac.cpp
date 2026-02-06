#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int f(int ind,int prev,vector<int>&a,int n, vector<vector<int>>& dp){

    if(ind == n){
        return 0;
    }

    if(dp[ind][prev] != -1){
        return dp[ind][prev];
    }

    int temp = 1e9;


    if(a[ind] == 0){
        temp =  1 + f(ind + 1,0,a,n,dp);
    }

    else if(a[ind] == 1){
        if(prev == 1){
            temp =  min(f(ind + 1,2,a,n,dp),1 + f(ind + 1,0,a,n,dp));
        }
        else if(prev == 2){
            temp = 1 + f(ind + 1,0,a,n,dp);
        }
        else{
            temp = min( f(ind + 1,2,a,n,dp), 1 + f(ind + 1,0,a,n,dp));
        }
    }

    else if(a[ind] == 2){
        if(prev == 0){
            temp = min(1 + f(ind + 1,0,a,n,dp),f(ind + 1,1,a,n,dp));
        }
        else if(prev == 1){
            temp = 1 + f(ind + 1,0,a,n,dp);
        }
        else{
            temp = min(1 + f(ind + 1,0,a,n,dp),f(ind + 1,1,a,n,dp));
        }
    }

    else{
            if(prev == 0){
                temp = min({1 + f(ind + 1,0,a,n,dp), f(ind + 1,1,a,n,dp), f(ind + 1,2,a,n,dp)});
            }
            else if(prev == 1){
                temp = min(1 + f(ind + 1,0,a,n,dp), f(ind + 1,2,a,n,dp));
            }
            else if(prev == 2){
                temp = min(1 + f(ind + 1,0,a,n,dp), f(ind + 1,1,a,n,dp));
            }
        
        }
    return dp[ind][prev] = temp;
}

int main () {

    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    vector<vector<int>>dp(n+1,vector<int>(3,-1));

    cout<<f(0,0,a,n,dp)<<endl;
    return 0;
}