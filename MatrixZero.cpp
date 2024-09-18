#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
int row,col;
cin>>row>>col;
int mat[row][col];
vector<pair<int,int>>zero(row,{0,0});
  for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> mat[i][j];
            if(mat[i][j]==0){
                zero[i].first = 1;
                zero[j].second= 1;
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(zero[i].first==1 || zero[j].second==1){
                mat[i][j]=0;
            }
        }
    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }



}
