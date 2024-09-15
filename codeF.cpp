#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,k;
        cin>>n>>k;
        int count=0;
        long long t =n;
        while(k>0 && t>0){
            k=k-t;
            t=t-1;
            count++;
        }
        if(k!=0){
            int t1=n-1;
             while(k>0 && t1>0){
            k=k-t1;
            t1=t1-1;
            count++;
        }
        }
        cout<<count<<endl;

    }
}