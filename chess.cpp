#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int row,int col,vector<string>&a,vector<vector<int>>&vis,bool flag){
    int n=a.size();
    int m=a[0].size();

    vector<int>drow = {-1,0,1,0};
    vector<int>dcol = {0,1,0,-1};

    vis[row][col] = 1;
    if(flag == true){
        a[row][col] = 'W';
    }
    else{
        a[row][col] = 'B';
    }

    for(int i=0;i<4;i++){
        int nr = row + drow[i];
        int nc = col + dcol[i];
        if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc] != 1 && a[nr][nc] == '.'){
            dfs(nr,nc,a,vis,!flag);
            }
    }
    
}
int main()
{
   int n,m;
   cin>>n>>m;
   vector<string>a(n);
   vector<vector<int>>vis(n,vector<int>(m,0));
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   bool flag = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]=='.' && vis[i][j] != 1){
                dfs(i,j,a,vis,flag);
            }
        }
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           cout<<a[i][j];
        }
        cout<<endl;
    }
}