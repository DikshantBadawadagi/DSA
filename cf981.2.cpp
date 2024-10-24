#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>matrix(n, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>matrix[i][j];
            }
        }
       vector<int> diff(n*2 -1,0);

       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            diff[i-j + n-1] = min(diff[i-j + n-1],matrix[i][j]);
        }
       }

       int sol = 0;
       for(int i =0;i< diff.size();i++){
        if(diff[i] < 0){
            sol -= diff[i];
        }
       }
       cout<<sol<<endl;
    }
return 0;
}