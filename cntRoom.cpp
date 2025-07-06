#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<char>>&grid, int n, int m) {
    grid[row][col] = '#';
    vector<int>drow = {-1,0,1,0};
    vector<int>dcol = {0,1,0,-1};
    for(int i=0;i<4;i++){
        int nrow= row+drow[i];
        int ncol = col + dcol[i];
        if(nrow >=0 && nrow < n && ncol>= 0 && ncol < m && grid[nrow][ncol] == '.'){
            dfs(nrow, ncol, grid, n, m);
        }
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>>grid(n, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == '.'){
                dfs(i,j,grid,n,m);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;

}