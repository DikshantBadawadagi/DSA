#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main () {
    long long n;
    cin>>n;
    vector<int>nums(n);
    long long sum=0,maxi=-1;
    for (int i = 0; i < n; i++) {
        cin>>nums[i];
        sum+=nums[i];
        maxi=max(maxi,(long long)nums[i]);
    }
    if(sum%2==0 && maxi<=(sum-maxi)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;


}