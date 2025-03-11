#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main () {
    long long t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        vector<long long>nums(n);
        long long t_mini = INT_MAX;
        for(int i=0;i<n;i++){
            cin>>nums[i];
            t_mini = min(t_mini,nums[i]);
        }


    }
}