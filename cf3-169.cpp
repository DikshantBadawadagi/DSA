#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>cost(n);
        for(int i=0;i<n;i++){
            cin>>cost[i];
        }
        int mini,maxi;
        while(mini <= maxi && k > 0){
            
            mini+=1;
            k--;
        }


    }
}