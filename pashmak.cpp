#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin>>n;
    vector<long long>nums(n);
    unordered_map<long long,long long>mp;
    long long min=LONG_LONG_MAX,max=LONG_LONG_MIN;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        mp[nums[i]]++;
        min=min<nums[i]?min:nums[i];
        max=max>nums[i]?max:nums[i];
    }
long long ans = mp[max] * mp[min];
if(max - min == 0)cout<<0<<" "<<n*(n-1)/2<<endl;
else cout<<max - min<<" "<<ans<<endl;

}