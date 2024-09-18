#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(int m,int n,string a,string b){
    
    int dp[m+1][n+1];
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            dp[m][n] = -1;
        }
    }
    if(m==0||n==0){
        return 0;
    }
    if(dp[m][n]!=-1){
        return dp[m][n];
    }
    if(a.at(m-1)==b.at(n-1)){
        return dp[m][n] = 1+ lcs(m-1,n-1,a,b);
    }
    else{
        return dp[m][n] = max(lcs(m,n-1,a,b),lcs(m-1,n,a,b));
    }

}

int main() {
    string a,b;
    cin>>a>>b;
    int m = a.length();
    int n = b.length();
    cout<<lcs(m,n,a,b);
}