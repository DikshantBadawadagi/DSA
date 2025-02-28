#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long f(long long ind,long long n, long long a, long long b, vector<long long> nums){
    if(ind == 0) return 0;

    long long not_cap = f(ind +1,)
    
}

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n,a,b;

        cin>>n>>a>>b;

        vector<long long> nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        cout<<f(0,n,a,b,nums)<<endl;
    }
}