#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<vector<int>> coord(n,vector<int>(3));
    int sum=0;
for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin>>coord[i][j];
            sum+=coord[i][j];
        }
    }
    if(sum==0){
        cout<<"Yes";
    }
    else{
        cout<<"No";
    }


}