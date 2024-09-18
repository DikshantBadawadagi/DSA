#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<string>&board,int row,int col,int n){
    int duprow = row;
    int dupcol = col;
    while(row>=0 && col>=0){
        if(board[row][col] == 'Q')return false;
        row--; col--;
    }

    row=duprow;
    col=dupcol;
     while( col>=0){
        if(board[row][col] == 'Q')return false;
         col--;
    }

    row=duprow;
    col=dupcol;
     while(row<n && col>=0){
        if(board[row][col] == 'Q')return false;
        row++; col--;
    }

    return true;

}
void solve(int col,int n,vector<string>&board,vector<vector<string>>&ans){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(board,row,col,n)){
            board[row][col]='Q';
            solve(col+1,n,board,ans);
            board[row][col]='.';
        }
    }
}
int main() {
    int n;
    cin>>n;
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i] = s;
    }
    solve(0,n,board,ans);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
  
}