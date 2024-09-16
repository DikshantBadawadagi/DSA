#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n,m,k;
        cin>>n>>m>>k;
        int ans[n];
        ans[0] = n;
        int j;
        for(int i=1;i<n-m;i++){
            j=n-i;
            ans[i] = j;
        }
        int a=0;
        for(int i=1;i<=m;i++){
            ans[n-m +a] = i;
            a++;
        }
      
      for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
      }
    }
}