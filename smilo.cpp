#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;

    while(t--){
        long long n;
        cin>>n;
        vector<int>nums(n);
        long long ans=0,sum=0;
        for(int i=0;i<n;i++){
            cin>>nums[i];
            sum+=nums[i];
        }
        sort(nums.begin(),nums.end());
        ans+=sum/2;
        if(sum%2!=0){
            ans+=1;
        }
        long long temp=0,i=1;
        sum/=2;
        while(sum > 0){
            sum-=nums[n-i];
            i++;
            ans++;
        }
        cout<<ans<<endl;
        


    }
}