#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int row,int col,vector<vector<char>>&grid,vector<vector<int>>&vis) {
    vis[row][col] = 1;

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    for(int i=0;i<4;i++){
        int nrow = row + drow[i];
        int ncol = col + dcol[i];

        if(nrow>=0 && nrow<grid.size() && ncol>=0 && ncol<grid[0].size() && grid[nrow][ncol] == '.' && !vis[nrow][ncol]){
            dfs(nrow,ncol,grid,vis);
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    vector<vector<int>>vis(n,vector<int>(m,0));
    int ans = 0;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>grid[i][j];
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j] == '.' && !vis[i][j]) {
                dfs(i,j,grid,vis);
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

