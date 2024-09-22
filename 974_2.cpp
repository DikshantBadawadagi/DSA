#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n,k,sum=0;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            if(i + k - 1 < n) continue;

            else{
                sum+= i;
            }
        }
        if(sum%2 == 0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
}