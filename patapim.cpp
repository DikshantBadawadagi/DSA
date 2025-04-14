#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>v(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>v[i][j];
            }
        }
        vector<int>ans(2*n);

        long long sum=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ans[i+j-1] = v[i][j];
            }
        }
        for(int i=0;i<2*n;i++){
            sum += ans[i];
        }
        long long tot = (2*n)*((2*n)+1)/2;
        ans[0] = tot - sum;
        for(int i=0;i<2*n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}