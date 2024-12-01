#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    long long t;
    cin>>t;
    while(t--){
        long long n,m,k;
        cin>>n>>m>>k;
        string bin;
        cin>>bin;
        long long ans =0;
            long long cnt=0;
        for(int i=0;i<n;i++){
            if(bin[i]=='0'){
                cnt++;
            }
            else{
                cnt=0;
            }
            if(cnt >= m){
                // cout<<cnt<<" ";
                ans++;
                cnt =0;
                if(k>1)i+=k-1;
            }
        }
        
        cout<<ans<<endl;
    }
    }