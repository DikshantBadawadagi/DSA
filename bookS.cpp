#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int f(int ind,int w,vector<int>&book,vector<int>&pg,vector<vector<int>>&dp){
    if(ind  == 0){
        if(book[0] <= w)return pg[0];
        else return 0;
    }
    if(w == 0)return 0;
    
    if(dp[ind][w] != -1)return dp[ind][w];

    int notPick = 0 + f(ind -1,w,book,pg,dp);
    int pick = INT_MIN;

    if(book[ind] <= w){
        pick = pg[ind] + f(ind -1,w-book[ind],book,pg,dp);
    }
    return dp[ind][w] = max(pick,notPick);
}

int main () {
    int n,x;
    cin>>n>>x;
    vector<int>book(n);
    vector<int>pg(n);
    for(int i=0;i<n;i++){
        cin>>book[i];
    }
    for(int i=0;i<n;i++){
        cin>>pg[i];
    }

    vector<int>prev(x+1,0),curr(x+1,0);

    for(int w=0;w<=x;w++){
        if(book[0] <= w)prev[w] = pg[0];
        else prev[w] = 0;
    }

    for(int ind=1;ind<n;ind++){
        for(int w=0;w<=x;w++){
            int notPick = 0 + prev[w];
            int pick = INT_MIN;

            if(book[ind] <= w){
                pick = pg[ind] + prev[w-book[ind]];
            }
            curr[w] = max(pick,notPick);
        }
        prev = curr;
    }

    cout<<prev[x]<<endl;

}