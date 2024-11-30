#include<bits/stdc++.h>
#include<iostream>
using namespace std;

// You are given an m x n grid where each cell can have one of three values:
// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.

// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

// Input [[2, 1, 0, 2, 1], [1, 0, 1, 2, 1], [1, 0, 0, 2, 1]]
// Output : 2

// Input [[2, 1, 0, 2, 1], [0, 0, 1, 2, 1], [1, 0, 0, 2, 1]]
// Output : -1

void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,int cnt){
    int  n =grid.size();
vector<int>drow  = {-1,0,1,0};
vector<int>dcol  = {0,1,0,-1};
for(int i=0;i<4;i++){
    int nrow = row + drow[i];
    int ncol = col + dcol[i];
    
    if(nrow < n && nrow >= 0 && ncol < n && ncol >=0 && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0){
        vis[nrow][ncol] = 1;
        grid[nrow][ncol] = 2;
        dfs(nrow,ncol,vis,grid,cnt+1);
    }
}

}
int main() {
    vector<vector<int>>grid = {{2,1,1},{1,1,0},{0,1,1}};
    int n = grid.size();
    vector<vector<int>>vis(n,vector<int>{n,0});
    int cnt=0,ans;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2 && vis[i][j] != 1){
                dfs(i,j,vis,grid,cnt);
            }
        }
    }
    cout<<cnt<<endl;

}