#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long f(long long i,long long j, long long a, long long b, vector<long long> nums){
    if(i == 0) return 0;
    if(i ==0 && j> 0){
        return INT_MAX;
    }
    if(j >=i )return INT_MAX;

    long long mini = INT_MAX;

    for(long long k=0;k<i;k++){
        mini = min(mini, f(k,j-1,a,b,nums) + a*abs(nums[k] - nums[j]) + b*abs(nums[j] - nums[i]));
    }
    return mini;
    
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