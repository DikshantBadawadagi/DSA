#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n,k=0;
        cin>>n;
        long long a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        long long pref_max=0,sum=0,mx=0;
        for(int i=0;i<n;i++){
            pref_max=max(pref_max,a[i]);
        long long d = pref_max-a[i];
        sum+=d;
        mx = max(mx,d);
        }
        cout<<sum+mx<<endl;
       

    }
}