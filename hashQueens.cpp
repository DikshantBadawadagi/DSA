#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,int n,vector<int>rowtable,vector<int>lower,vector<int>upper){
    if(rowtable[row]==1 || lower[row+col]==1 || upper[row-col+n-1]==1){
        return false;
    }
    return true;
}
void solve(int col,int n,vector<int>&rowtable,vector<int>&lower,vector<int>&upper,vector<string>&board,vector<vector<string>>&ans){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,n,rowtable,lower,upper)){
            board[row][col]='Q';
            rowtable[row]=1;
            lower[row+col]=1;
            upper[row-col+n-1]=1;
            solve(col+1,n,rowtable,lower,upper,board,ans);
            board[row][col]='.';
            rowtable[row]=0;
            lower[row+col]=0;
            upper[row-col+n-1]=0;
        }
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    vector<int>rowtable(n,0);
    vector<int>lower(2*n-1,0);
    vector<int>upper(2*n-1,0);

    solve(0,n,rowtable,lower,upper,board,ans);
   for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}