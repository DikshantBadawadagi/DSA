#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>>mat(5,vector<int>(5));
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cin>>mat[i][j];
        }
    }
     for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            if(mat[i][j] == 1){
                cout<<abs(2-i)+abs(2-j);
            }

        }
        }
}